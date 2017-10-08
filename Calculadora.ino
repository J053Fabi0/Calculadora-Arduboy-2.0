  #include <Arduboy2.h>
  #include "bitmaps.h"
  
  Arduboy2 arduboy;
  
  long n1 = 0; //Number 1
  long n2 = 0; //Number 2
  long result = 0;
  String op = "+"; //Operation - + * /
  int8_t pos = 1; //Position of the cursor in the text that goes by 0's: 1 -> 10 -> 100 -> 1000
  int8_t posY = 10; //Position of the cursor in X
  int8_t posX = 10; //Position of the cursor in Y

  int8_t count = 0;
  int16_t delayChange = 150;
  
  
  void setup() {
    arduboy.boot();
    arduboy.blank();
    arduboy.flashlight();
    arduboy.audio.begin();
    arduboy.setFrameRate(30); //Default is 30 
  }
  
  
  void loop() {
    if (!(arduboy.nextFrame()))
      return;
    arduboy.clear();
    arduboy.setCursor(106 - numDigits(n1)*6, 10);
    arduboy.println(n1);
    arduboy.println(pos);
    arduboy.println(delayChange);
    arduboy.println(count);

    arduboy.drawBitmap(128-19, 64-14, instructions, 19, 14, 1);
    
    arduboy.display();
        
    changeValue(arduboy.pressed(UP_BUTTON));

    arduboy.setRGBled(0, 0, 0);
    
  }

  int16_t numDigits(int16_t number){
    int digits = 0;
    if (number <= 0) digits = 1;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
  }
  
  void changeValue(bool UpPressed) {

    if(UpPressed) {
      n1 += pos;
      count++;
      arduboy.setRGBled(0, 0, 1); //red, green, blue. can be set to a value from 0 (fully off) to 255 (fully on).
      delay(delayChange);
    }
    else if (arduboy.pressed(DOWN_BUTTON)) {
      n1 -= pos;
      count++;
      arduboy.setRGBled(1, 0, 0); //red, green, blue. can be set to a value from 0 (fully off) to 255 (fully on).
      delay(delayChange);
    }
    else {
      delayChange = 150;
      count = 0;
    }

    if (count >= 15 && delayChange > 0 && (arduboy.pressed(DOWN_BUTTON) || UpPressed)) {
      count = 0;
      delayChange -= 50;
    }
    
  }
  
  void cursor() {
  //  arduboy.drawFastHLine()
  }
  
  
  
  
  
  
  ////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////
