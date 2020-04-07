#include <TVout.h>
#include <fontALL.h>

TVout TV;

void setup() {
  TV.begin(PAL,150,60);
  TV.select_font(font6x8);

  TV.println("ANIX OS\n");
  TV.delay(3500);
  TV.print("Version 1.0.0.0\n");
  TV.delay(2500);
  TV.print("Loading");
  TV.delay(350);
  TV.print(".");
  TV.delay(350);
  TV.print(".");
  TV.delay(350);
  TV.print(".\n");
  TV.print("Loading Complete");
  TV.delay(2000);

  TV.clear_screen();
  TV.println("System OK");
  TV.println("Type HELP to get command list.");
  TV.delay(2000);
}
void loop(){
  
}
