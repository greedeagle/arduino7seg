//We always have to include the library
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,11,10,1);

/* we always wait a bit between updates of the display */
unsigned long delaytime=100;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}


/**
 * 8ケタの整数をdigit表示する
 * 注意：arduinoのメモリ空間の関係上、６ケタまでしか入らないだろうね
 * lc 対象LcdControl
 * number 表示文字列
 */
void display8integer(LedControl target_lc, int number)
{
  lc.clearDisplay(0);
  int DIGIT_COUNT = 8;
  for(int i=0; i<DIGIT_COUNT; i++)
  {
    int item = number % 10;
    number = number /10;
    target_lc.setDigit(0,i,item,false);
  }

}

void loop() { 
  // scrollDigits();
  display8integer(lc,12345);
  delay(1000);
}
