/*
 * ATtinySerialOut.h
 *
 *  Copyright (C) 2015-2020  Armin Joachimsmeyer
 *  Email: armin.joachimsmeyer@gmail.com
 *
 *  This file is part of TinySerialOut https://github.com/ArminJo/ATtinySerialOut.
 *
 *  TinySerialOut is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/gpl.html>.
 *
 */

//
// ATMEL ATTINY85
//
//                                               +-\/-+
//               PCINT5/!RESET/ADC0/dW (5) PB5  1|    |8  VCC
// USB+   PCINT3/XTAL1/CLKI/!OC1B/ADC3 (3) PB3  2|    |7  PB2 (2) SCK/USCK/SCL/ADC1/T0/INT0/PCINT2 / TX Debug output
// USB-   PCINT4/XTAL2/CLKO/ OC1B/ADC2 (4) PB4  3|    |6  PB1 (1) MISO/DO/AIN1/OC0B/ OC1A/PCINT1 - (Digispark) LED
//                                         GND  4|    |5  PB0 (0) MOSI/DI/AIN0/OC0A/!OC1A/SDA/AREF/PCINT0
//                                               +----+

// ATMEL ATTINY167
// Pin numbers are for Digispark core
// Pin numbers in Parenthesis are for ATTinyCore
//
//                    +-\/-+
//    RX  6 (0) PA0  1|    |20  PB0 (D8)  0 OC1AU  TONE  Timer 1 Channel A
//    TX  7 (1) PA1  2|    |19  PB1 (9)  1 OC1BU  Internal LED
//        8 (2) PA2  3|    |18  PB2 (10) 2 OC1AV  Timer 1 Channel B
//   INT1 9 (3) PA3  4|    |17  PB3 (11) 4 OC1BV  connected with 51 Ohm to D- and 3.3 volt Zener.
//             AVCC  5|    |16  GND
//             AGND  6|    |15  VCC
//       10 (4) PA4  7|    |14  PB4 (12) XTAL1
//       11 (5) PA5  8|    |13  PB5 (13) XTAL2
//       12 (6) PA6  9|    |12  PB6 (14) 3 INT0  connected with 68 Ohm to D+ (and disconnected 3.3 volt Zener). Is terminated with ~20 kOhm if USB attached :-(
//        5 (7) PA7 10|    |11  PB7 (15) RESET
//                    +----+
//

#ifndef TINY_SERIAL_OUT_H_
#define TINY_SERIAL_OUT_H_

#if defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__) || defined(__AVR_ATtiny87__) || defined(__AVR_ATtiny167__)
#include <Arduino.h>

#if (F_CPU != 1000000) &&  (F_CPU != 8000000) &&  (F_CPU != 16000000)
#error "F_CPU value must be 1000000, 8000000 or 16000000."
#endif

/*
 * Change this, if you need another pin as serial output
 * or set it as Symbol like "-DTX_PIN PB1"
 * or when switching port (e.g. for ATiny167), then we need more Symbols like "-DTX_PIN PB1 -DTX_PORT PORTB -DTX_PORT_ADDR 0x05 -TX_DDR DDRB"
 */
#if defined(__AVR_ATtiny87__) || defined(__AVR_ATtiny167__)
#ifndef TX_PIN
#define TX_PIN PA1 // (package pin 2 / TXD on Tiny167) - can use one of PA0 to PA7 here
#endif
#ifndef TX_PORT
#define TX_PORT PORTA
#define TX_PORT_ADDR 0x02 // PORTA
#define TX_DDR DDRA

//#define TX_PORT PORTB
//#define TX_PORT_ADDR 0x05
//#define TX_DDR DDRB
#endif

#else // defined(__AVR_ATtiny87__) || defined(__AVR_ATtiny167__)
#ifndef TX_PIN
#define TX_PIN PB2 // (package pin 7 on Tiny85) - can use one of PB0 to PB4 (+PB5) here
#endif
#define TX_PORT PORTB
#define TX_PORT_ADDR 0x18 // PORTB
#define TX_DDR DDRB
#endif // defined(__AVR_ATtiny87__) || defined(__AVR_ATtiny167__)
/*
 * @1 MHz use bigger (+120 bytes for unrolled loop) but faster code. Otherwise only 38400 baud is possible.
 * @8/16 MHz use 115200 baud instead of 230400 baud.
 */
#ifndef TINY_SERIAL_DO_NOT_USE_115200BAUD  // define this to force using other baud rates
#define USE_115200BAUD
#endif

/*
 * Define or comment this out, if you want to use this class as a replacement for standard Serial as the print class
 * Adds around 800 Bytes of code
 */
//#define TINY_SERIAL_INHERIT_FROM_PRINT
/*
 * Define or comment this out, if you want to save code size and if you can live with 87 micro seconds intervals of disabled interrupts for each sent byte.
 */
//#define USE_ALWAYS_CLI_SEI_GUARD_FOR_OUTPUT
extern bool sUseCliSeiForWrite; // default is true
void useCliSeiForStrings(bool aUseCliSeiForWrite); // might be useful to set to false if output is done from ISR, to avoid to call unwanted sei().

inline void initTXPin() {
    // TX_PIN is active LOW, so set it to HIGH initially
    TX_PORT |= (1 << TX_PIN);
    // set pin direction to output
    TX_DDR |= (1 << TX_PIN);
}

void write1Start8Data1StopNoParity(uint8_t aValue);
inline void write1Start8Data1StopNoParityWithCliSei(uint8_t aValue) {
    uint8_t oldSREG = SREG;
    cli();
    write1Start8Data1StopNoParity(aValue);
    SREG = oldSREG;
}

inline void writeValue(uint8_t aValue) {
    write1Start8Data1StopNoParity(aValue);
}

// The same class as for plain arduino
#if defined(ARDUINO_AVR_DIGISPARK)
// The digispark library defines (2/2019) F but not __FlashStringHelper
//# define F(string_literal) ((fstr_t*)PSTR(string_literal))
#define __FlashStringHelper fstr_t
#endif
#if not defined(F)
class __FlashStringHelper;
#define F(string_literal) (reinterpret_cast<const __FlashStringHelper *>(PSTR(string_literal)))
#endif

void writeString(const char * aStringPtr);
void writeString(const __FlashStringHelper * aStringPtr);
void writeString_P(const char * aStringPtr);
void writeString_E(const char * aStringPtr);
void writeStringWithCliSei(const char * aStringPtr);
void writeStringWithoutCliSei(const char * aStringPtr);
void writeStringSkipLeadingSpaces(const char * aStringPtr);

void writeBinary(uint8_t aByte); // write direct without decoding
void writeChar(uint8_t aChar); // Synonym for writeBinary
void writeCRLF();
void writeByte(int8_t aByte);
void writeUnsignedByte(uint8_t aByte);
void writeUnsignedByteHex(uint8_t aByte);
void writeUnsignedByteHexWithPrefix(uint8_t aByte);
void writeInt(int aInteger);
void writeUnsignedInt(unsigned int aInteger);
void writeLong(long aLong);
void writeUnsignedLong(unsigned long aLong);
void writeFloat(double aFloat);
void writeFloat(double aFloat, uint8_t aDigits);

char nibbleToHex(uint8_t aByte);

#if defined(TINY_SERIAL_INHERIT_FROM_PRINT)
class TinySerialOut: public Print
#else
class TinySerialOut
#endif
{
public:

    void begin(long);
    void end();
    void flush(void);

    void printHex(uint8_t aByte); // with 0x prefix
    void printHex(uint16_t aWord); // with 0x prefix
    void printlnHex(uint8_t aByte); // with 0x prefix
    void printlnHex(uint16_t aWord); // with 0x prefix

    // virtual functions of Print class
    size_t write(uint8_t aByte);

#if !defined(TINY_SERIAL_INHERIT_FROM_PRINT)
    void print(const __FlashStringHelper * aStringPtr);
    void print(const char* aStringPtr);
    void print(char aChar);
    void print(uint8_t aByte, uint8_t aBase = 10);
    void print(int aInteger, uint8_t aBase = 10);
    void print(unsigned int aInteger, uint8_t aBase = 10);
    void print(long aLong, uint8_t aBase = 10);
    void print(unsigned long aLong, uint8_t aBase = 10);
    void print(double aFloat, uint8_t aDigits = 2);

    void println(const char* aStringPtr);
    void println(const __FlashStringHelper * aStringPtr);
    void println(char aChar);
    void println(uint8_t aByte, uint8_t aBase = 10);
    void println(int aInteger, uint8_t aBase = 10);
    void println(unsigned int aInteger, uint8_t aBase = 10);
    void println(long aLong, uint8_t aBase = 10);
    void println(unsigned long aLong, uint8_t aBase = 10);
    void println(double aFloat, uint8_t aDigits = 2);

    void println(void);
#endif // TINY_SERIAL_INHERIT_FROM_PRINT

};

// #if ... to be compatible with ATTinyCores and AttinyDigisparkCores
#if ((!defined(UBRRH) && !defined(UBRR0H)) || (defined(USE_SOFTWARE_SERIAL) && (USE_SOFTWARE_SERIAL != 0))) || defined(TINY_DEBUG_SERIAL_SUPPORTED) || ((defined(UBRRH) || defined(UBRR0H) || defined(LINBRRH)) && (defined(USE_SOFTWARE_SERIAL) && (USE_SOFTWARE_SERIAL == 0)))
// Switch to SerialOut since Serial is already defined or comment out
// at line 54 in TinySoftwareSerial.h included in in ATTinyCores/src/tiny/Arduino.h at line 228  for ATTinyCores
// or line 71 in HardwareSerial.h included in ATTinyCores/src/tiny/Arduino.h at line 227 for ATTinyCores
// or line 627ff TinyDebugSerial.h included in AttinyDigisparkCores/src/tiny/WProgram.h at line 18 for AttinyDigisparkCores
extern TinySerialOut SerialOut;
#define Serial SerialOut
#else
extern TinySerialOut Serial;
#endif

#endif // defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__) || defined(__AVR_ATtiny87__) || defined(__AVR_ATtiny167__)

#endif /* TINY_SERIAL_OUT_H_ */

#pragma once
