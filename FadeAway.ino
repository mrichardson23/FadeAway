#include <Servo.h>
#include <SPI.h>
#include <Ethernet.h>

Servo x;
Servo y;

byte mac[] = {  0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02 };
char serverName[] = "nosdrahcir.com";

EthernetClient client;

int letterHeight = 20; //for best results, should be divisible by four
int letterWidth = 10;  //for best results, should be divisible by four

int xLowBoundary = 1295;
int yLowBoundary = 1410;

int xHighBoundary = 1810;
int yHighBoundary = 1830;

int xPos = xLowBoundary;
int yPos = yLowBoundary;

int laserPin = 7;
int xServoPin = 9;
int yServoPin = 10;

String tweet = "";

void setup() 
{ 
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    while(true);
  }
  pinMode(laserPin, OUTPUT);
  x.attach(xServoPin); 
  y.attach(yServoPin);
  x.writeMicroseconds(xPos);
  y.writeMicroseconds(yPos);
  Serial.begin(115200);
  delay(2000);
} 


void loop() {
  Serial.println("connecting...");
  if (client.connect(serverName, 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    client.println("GET /~nosdrahc/twittersearch/ethernet.php");
    client.println();
    delay(1000);
     else {
      // if you didn't get a connection to the server:
      Serial.println("connection failed");
    }
    
    while(client.available()) {
      tweet += char(client.read());
    }
     client.stop();
  
  
  
  //tweet = "This is just a sample tweet of a few characters that should be stepped through";
  // Only proceed when the tweet is complete:
  
  for (int i = 0; i < tweet.length(); i++)
  {
    char c = tweet.charAt(i);
    switch (c) {
    case 'a':
    case 'A':
      drawA();
      drawSpace();
      break;
    case 'b':
    case 'B':
      drawB();
      drawSpace();
      break;
    case 'c':
    case 'C':
      drawC();
      drawSpace();
      break;
    case 'd':
    case 'D':
      drawD();
      drawSpace();
      break;
    case 'e':
    case 'E':
      drawE();
      drawSpace();
      break;
    case 'f':
    case 'F':
      drawF();
      drawSpace();
      break;
    case 'g':
    case 'G':
      drawG();
      drawSpace();
      break;
    case 'h':
    case 'H':
      drawH();
      drawSpace();
      break;
    case 'i':
    case 'I':
      drawI();
      drawSpace();
      break;
    case 'j':
    case 'J':
      drawJ();
      drawSpace();
      break;
    case 'k':
    case 'K':
      drawK();
      drawSpace();
      break;
    case 'l':
    case 'L':
      drawL();
      drawSpace();
      break;
    case 'm':
    case 'M':
      drawM();
      drawSpace();
      break;
    case 'n':
    case 'N':
      drawN();
      drawSpace();
      break;
    case 'o':
    case 'O':
      drawO();
      drawSpace();
      break;
    case 'p':
    case 'P':
      drawP();
      drawSpace();
      break;
    case 'q':
    case 'Q':
      drawQ();
      drawSpace();
      break;
    case 'r':
    case 'R':
      drawR();
      drawSpace();
      break;
    case 's':
    case 'S':
      drawS();
      drawSpace();
      break;
    case 't':
    case 'T':
      drawT();
      drawSpace();
      break;
    case 'u':
    case 'U':
      drawU();
      drawSpace();
      break;
    case 'v':
    case 'V':
      drawV();
      drawSpace();
      break;
    case 'w':
    case 'W':
      drawW();
      drawSpace();
      break;
    case 'x':
    case 'X':
      drawX();
      drawSpace();
      break;
    case 'y':
    case 'Y':
      drawY();
      drawSpace();
      break;
    case 'z':
    case 'Z':
      drawZ();
      drawSpace();
      break;
    case ' ':
      drawSpace();
      drawSpace();
      break;
    case '.':
      drawPeriod();
      drawSpace();
      break;
    case ',':
      drawComma();
      drawSpace();
      break;
    case ':':
      drawColon();
      drawSpace();
      break;
    case ';':
      drawSemicolon();
      drawSpace();
      break;
    case '!':
      drawExclamationPoint();
      drawSpace();
      break;
    case '\'': //apostrophe
      drawApostrophe();
      drawSpace();
      break;
    case '"': //quotation mark
      drawApostrophe();
      drawSpace();
      drawApostrophe();
      drawSpace();
      break;
    case '-':
      drawDash();
      drawSpace();
      break;
    case '\\':
      drawBackSlash();
      drawSpace();
      break;
    case '/':
      drawForwardSlash();
      drawSpace();
      break;
    case '(':
    case '<':
      drawOpenParens();
      drawSpace();
      break;
    case ')':
    case '>':
      drawClosedParens();
      drawSpace();
      break;
    case '#':
      drawHash();
      drawSpace();
      break;
    case '@':
      drawAtSign();
      drawSpace();
      break;
    case '1':
      drawOne();
      drawSpace();
      break;
    case '2':
      drawTwo();
      drawSpace();
      break;
    case '3':
      drawThree();
      drawSpace();
      break;
    case '4':
      drawFour();
      drawSpace();
      break;
    case '5':
      drawS(); // ISWYDT
      drawSpace();
      break;
    case '6':
      drawSix();
      drawSpace();
      break;
    case '7':
      drawSeven();
      drawSpace();
      break;
    case '8':
      drawEight();
      drawSpace();
      break;
    case '9':
      drawNine();
      drawSpace();
      break;
    case '0':
      drawO();
      drawSpace();
      break;
    } // end switch case
     if (xPos + letterWidth > xHighBoundary) { //character line wrap
       yPos = yPos + letterHeight + 5;
       xPos = xLowBoundary;
       updatePosition();
       delay(100);
    }
  
    if (yPos +letterHeight > yHighBoundary) { //panel wrap
      yPos = yLowBoundary;
      xPos = xLowBoundary; 
      updatePosition();
      delay(100);
    }
  } // end looping through string for chars.
  tweet = "";
  delay(20000);
} // End main loop

void drawA() {
  moveOff(0, letterHeight);
  moveOn(letterWidth/2, letterHeight*-1);
  moveOn(letterWidth/2, letterHeight);
  moveOff(0, letterHeight/-2);
  moveOn(letterWidth*-1, 0);
  moveOff(letterWidth, letterHeight/-2);

}

void drawB() {
  moveOn(0, letterHeight);
  moveOn(letterWidth, letterHeight/-4);
  moveOn(letterWidth*-1, letterHeight/-4);
  moveOn(letterWidth, letterHeight/-4);
  moveOn(letterWidth*-1, letterHeight/-4);
  moveOff(letterWidth, 0); 
}

void drawC() {
  moveOff(letterWidth, letterHeight/4);
  moveOn(letterWidth/-2, letterHeight/-4);
  moveOn(letterWidth/-2, letterHeight/2);
  moveOn(letterWidth/2, letterHeight/2);
  moveOn(letterWidth/2, letterHeight/-4);
  moveOff(0, (letterHeight/-4)*3);
}

void drawD() {
  moveOn(0, letterHeight);
  moveOn(letterWidth/2, 0);
  moveOn(letterWidth/2, letterHeight/-2);
  moveOn(letterWidth/-2, letterHeight/-2);
  moveOn(letterWidth/-2, 0);
  moveOff(letterWidth, 0);

}

void drawE() {
  moveOn(letterWidth, 0);
  moveOff(0, letterHeight/2);
  moveOn(letterWidth*-1, 0);
  moveOff(0, letterHeight/2);
  moveOn(letterWidth, 0);
  moveOff(letterWidth*-1, 0);
  moveOn(0, letterHeight*-1); 
  moveOff(letterWidth, 0);
}


void drawF() {
  moveOn(letterWidth, 0);
  moveOff(0, letterHeight/2);
  moveOn(letterWidth*-1, 0);
  moveOff(0, letterHeight/-2);
  moveOn(0, letterHeight); 
  moveOff(letterWidth, letterHeight*-1);
}

void drawG() {
  moveOff(letterWidth, letterHeight/4);
  moveOn(letterWidth/-2, letterHeight/-4);
  moveOn(letterWidth/-2, letterHeight/2);
  moveOn(letterWidth/2, letterHeight/2);
  moveOn(letterWidth/2, letterHeight/-4);
  moveOn(letterWidth/-2, 0);
  moveOff(letterWidth/2, (letterHeight/-4)*3);
}


void drawH() {
  moveOn(0, letterHeight);
  moveOff(0, letterHeight/-2);
  moveOn(letterWidth, 0);
  moveOff(0, letterHeight/2);
  moveOn(0, letterHeight*-1);
}

void drawI() {
  moveOff(letterWidth/2, 0);
  moveOn(0, letterHeight);
  moveOff(letterWidth/2, letterHeight*-1);
}


void drawJ() {
  moveOff(letterWidth, 0);
  moveOn(0, letterHeight);
  moveOn(letterWidth*-1, 0);
  moveOn(0, letterHeight/-4);
  moveOff(letterWidth, (letterHeight/-4)*3);
}


void drawK() {
  moveOn(0, letterHeight);
  moveOff(0, letterHeight/-2);
  moveOn(letterWidth, letterHeight/2);
  moveOff(letterWidth*-1, letterHeight/-2);
  moveOn(letterWidth, letterHeight/-2);


}

void drawL() {
  moveOn(0, letterHeight);
  moveOn(letterWidth, 0);
  moveOff(0, letterHeight*-1);

}


void drawM() {
  moveOff(0, letterHeight);
  moveOn(0, letterHeight * -1);
  moveOn(letterWidth/2, letterHeight/2);
  moveOn(letterWidth/2, letterHeight/-2);
  moveOn(0,letterHeight);
  moveOff(0, letterHeight * -1);
}

void drawN() {
  moveOff(0, letterHeight);
  moveOn(0, letterHeight*-1);
  moveOn(letterWidth, letterHeight);
  moveOn(0, letterHeight*-1);

}

void drawO() {
  moveOn(0, letterHeight);
  moveOn(letterWidth, 0);
  moveOn(0, letterHeight*-1);
  moveOn(letterWidth*-1, 0);
  moveOff(letterWidth, 0);
}

void drawP() {
  moveOff(0, letterHeight);
  moveOn(0, letterHeight*-1);
  moveOn(letterWidth, 0);
  moveOn(0, letterHeight/2);
  moveOn(letterWidth*-1, 0);
  moveOff(letterWidth, letterHeight/-2);

}


void drawQ() {
  moveOn(0, letterHeight);
  moveOn(letterWidth, 0);
  moveOn(0, letterHeight*-1);
  moveOn(letterWidth*-1, 0);
  moveOff(letterWidth/2, letterHeight/2);
  moveOn(letterWidth/2, letterHeight/2);
  moveOff(0,letterHeight*-1);
}



void drawR() {
  moveOff(0, letterHeight);
  moveOn(0, letterHeight*-1);
  moveOn(letterWidth, letterHeight/4);
  moveOn(letterWidth*-1, letterHeight/4);
  moveOn(letterWidth, letterHeight/2);
  moveOff(0,letterHeight*-1);
}

void drawS() {
  moveOff(letterWidth, 0);
  moveOn(letterWidth*-1, 0);
  moveOn(0, letterHeight/2);
  moveOn(letterWidth, 0);
  moveOn(0, letterHeight/2);
  moveOn(letterWidth*-1,0);
  moveOff(letterWidth, letterHeight* -1);

}




void drawT() {
  moveOn(letterWidth, 0);
  moveOff((letterWidth/-2), 0);
  moveOn(0, letterHeight);
  moveOff(letterWidth/2, letterHeight*-1);
}

void drawU() {
  moveOn(0, letterHeight);
  moveOn(letterWidth, 0);
  moveOn(0,letterHeight*-1);

}


void drawV() {
  moveOn(letterWidth/2, letterHeight);
  moveOn(letterWidth/2, letterHeight*-1);
}


void drawW() {
  moveOn(letterWidth/4, letterHeight);
  moveOn(letterWidth/4, letterHeight/-2);
  moveOn(letterWidth/4, letterHeight/2);
  moveOn(letterWidth/4, letterHeight*-1);

}

void drawX() {
  moveOn(letterWidth, letterHeight);
  moveOff(letterWidth*-1, 0);
  moveOn(letterWidth, letterHeight*-1);
}


void drawY() {
  moveOn(letterWidth/2, letterHeight/2);
  moveOn(0, letterHeight/2);
  moveOff(0, letterHeight/-2);
  moveOn(letterWidth/2, letterHeight/-2);

}


void drawZ() {
  moveOn(letterWidth, 0);
  moveOn(letterWidth*-1, letterHeight);
  moveOn(letterWidth, 0);
  moveOff(0,letterHeight*-1);

}

void drawSpace() {
  moveOff(letterWidth, 0); 
}

void drawPeriod() {
  moveOff(0,letterHeight);
  moveOn(0,0);
  moveOff(0,letterHeight*-1);
}

void drawComma() {
  moveOff(0,(letterHeight/4)*3);
  moveOn(letterWidth/-4,letterHeight/4);
  moveOff(letterWidth/4,letterHeight*-1);
}

void drawColon() {
  moveOff(0,letterHeight/4);
  moveOn(0,0);
  moveOff(0, letterHeight/2);
  moveOn(0,0);
  moveOff(0, (letterHeight/4)*-3);
}

void drawSemicolon() {
  moveOff(0,letterHeight/4);
  moveOn(0,0);
  moveOff(0, letterHeight/2);
  moveOn(0,letterHeight/4);
  moveOff(0, letterHeight*-1);
}

void drawApostrophe() {
  moveOn(0,letterHeight/4);
  moveOff(0,letterHeight/-4);
}

void drawExclamationPoint() {
  moveOn(0, (letterHeight/4)*3);
  moveOff(0, letterHeight/4);
  moveOn(0,0);
  moveOff(0,letterHeight*-1);
}

void drawDash() {
 moveOff(0, letterHeight/2);
 moveOn(letterWidth, 0);
 moveOff(0, letterHeight/-2); 
  
}

void drawForwardSlash() {
  moveOff(0, letterHeight);
  moveOn(letterWidth, letterHeight*-1);  
}

void drawBackSlash() {
  moveOn(letterWidth, letterHeight);
  moveOff(0,letterHeight*-1);
}

void drawOpenParens() {
  moveOff(letterWidth/2, 0);
  moveOn(letterWidth/-2, letterHeight/2);
  moveOn(letterWidth/2, letterHeight/2);
  moveOff(letterWidth/2, letterHeight *-1);  
}

void drawClosedParens() {
  moveOff(letterWidth/2, 0);
  moveOn(letterWidth/2, letterHeight/2);
  moveOn(letterWidth/-2, letterHeight/2);
  moveOff(letterWidth/2, letterHeight * -1);
}

void drawHash() {
  moveOff(letterWidth/4, 0);
  moveOn(0,letterHeight);
  moveOff(letterWidth/2, 0);
  moveOn(0,letterHeight *-1);
  moveOff(letterWidth/4, letterHeight/4);
  moveOn(letterWidth*-1, 0);
  moveOff(0, letterHeight/2);
  moveOn(letterWidth, 0);
  moveOff(0, (letterHeight/-4)*3);
}

void drawAtSign() {
  moveOff(0, letterHeight);
  moveOn(0,letterHeight*-1);
  moveOn(letterWidth, 0);
  moveOn(0, letterHeight);
  moveOn(letterWidth/-4, letterHeight/-4);
  moveOn(0, letterHeight/-4);
  moveOn(letterWidth/-4, 0);
  moveOn(0, letterHeight/4);
  moveOn(letterWidth/4, 0);
  moveOff((letterWidth/4)*3, (letterHeight/4)*-3);
}

void drawOne() {
  moveOff(letterWidth/4, 0);
  moveOn(letterWidth/4, 0);
  moveOn(0, letterHeight);
  moveOff(letterWidth/2, letterHeight*-1);
}

void drawTwo() {
  moveOn(letterWidth, 0);
  moveOn(0, letterHeight/2);
  moveOn(letterWidth*-1, 0);
  moveOn(0, letterHeight/2);
  moveOn(letterWidth, 0);
  moveOff(0, letterHeight*-1);
}

void drawThree() {
  moveOn(letterWidth,0);
  moveOn(0, letterHeight);
  moveOn(letterWidth*-1, 0);
  moveOff(0, letterHeight/-2);
  moveOn(letterWidth, 0);
  moveOff(0, letterHeight/-2);
}

void drawFour() {
  moveOn(0, letterHeight/2);
  moveOn(letterWidth, 0);
  moveOff(0, letterHeight/-2);
  moveOn(0, letterHeight);
  moveOff(0, letterHeight*-1);
}

void drawSix() {
  moveOff(0,letterHeight/2);
  moveOn(letterWidth,0);
  moveOn(0,letterHeight/2);
  moveOn(letterWidth*-1, 0);
  moveOn(0, letterHeight*-1);
  moveOn(letterWidth, 0);
}

void drawSeven() {
  moveOn(letterWidth, 0);
  moveOn(letterWidth/-2, letterHeight);
  moveOff(letterWidth/2, letterHeight*-1);
}

void drawEight() {
  moveOn(0, letterHeight);
  moveOn(letterWidth, 0);
  moveOn(0, letterHeight*-1);
  moveOn(letterWidth*-1, 0);
  moveOff(0, letterHeight/2);
  moveOn(letterWidth, 0);
  moveOff(0, letterHeight/-2);
}

void drawNine() {
  moveOff(letterWidth, letterHeight/2);
  moveOn(letterWidth*-1, 0);
  moveOn(0,letterHeight/-2);
  moveOn(letterWidth, 0);
  moveOn(0, letterHeight);
  moveOn(letterWidth*-1, 0);
  moveOff(letterWidth, letterHeight *-1);
}

void moveOn (int xGo, int yGo) {
  digitalWrite(laserPin, HIGH);
  xPos = xPos + xGo;
  yPos = yPos + yGo;
  x.writeMicroseconds(xPos);
  y.writeMicroseconds(yPos);
  delay(75);
  digitalWrite(laserPin, LOW);
}

void moveOff (int xGo, int yGo) {
  xPos = xPos + xGo;
  yPos = yPos + yGo;
  x.writeMicroseconds(xPos);
  y.writeMicroseconds(yPos);
  delay(75);
}

void updatePosition() {
  x.writeMicroseconds(xPos);
  y.writeMicroseconds(yPos);
  delay(75);
}




