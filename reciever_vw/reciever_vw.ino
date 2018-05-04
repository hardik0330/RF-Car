#include <VirtualWire_Config.h>
#include <VirtualWire.h>

void stopm()
{
  digitalWrite(4,0);  //Back right Motor A
  digitalWrite(5,0);  //Back right Motor B

  digitalWrite(6,0); //Back left Motor A
  digitalWrite(7,0); //Back left Motor B

  digitalWrite(8,0);  //Front left Motor A
  digitalWrite(9,0);  //Front left Motor B

  digitalWrite(10,0); //Front right Motor A
  digitalWrite(11,0); //Front right Motor B
}

void setup()
{
vw_set_ptt_inverted(true); // Required for DR3100
vw_set_rx_pin(12); //Reciever pin
vw_setup(4000); // Bits per sec

pinMode(13, OUTPUT);  //onboard LED

Serial.begin(9600); //initialize Serial Monitor at 9600 baud rate

vw_rx_start(); // tells the reciever to start recieving signals


pinMode(2,OUTPUT); //gnd connections for reciever module
pinMode(3,OUTPUT); //gnd connections for reciever module
//pinMode(5,OUTPUT); //gnd connections for LED

digitalWrite(2,0);
digitalWrite(3,0);
//digitalWrite(5,0);

pinMode(13,OUTPUT);  //vcc connections for reciever module 
//pinMode(3,OUTPUT);  //vcc connections for reciever module

digitalWrite(13,1);
//digitalWrite(3,1);

pinMode(4,OUTPUT);  //Back right Motor A
pinMode(5,OUTPUT);  //Back right Motor B

pinMode(6,OUTPUT); //Back left Motor A
pinMode(7,OUTPUT); //Back left Motor B

pinMode(8,OUTPUT);  //Front left Motor A
pinMode(9,OUTPUT);  //Front left Motor B

pinMode(10,OUTPUT); //Front right Motor A
pinMode(11,OUTPUT); //Front right Motor B

stopm();
}
void forward()
{
  digitalWrite(4,1);  //Back right Motor A
  digitalWrite(5,0);  //Back right Motor B

  digitalWrite(6,1); //Back left Motor A
  digitalWrite(7,0); //Back left Motor B

  digitalWrite(8,1);  //Front left Motor A
  digitalWrite(9,0);  //Front left Motor B

  digitalWrite(10,1); //Front right Motor A
  digitalWrite(11,0); //Front right Motor B
}

void backward()
{
  digitalWrite(4,0);  //Back right Motor A
  digitalWrite(5,1);  //Back right Motor B

  digitalWrite(6,0); //Back left Motor A
  digitalWrite(7,1); //Back left Motor B

  digitalWrite(8,0);  //Front left Motor A
  digitalWrite(9,1);  //Front left Motor B

  digitalWrite(10,0); //Front right Motor A
  digitalWrite(11,1); //Front right Motor B
}

void left()
{
  digitalWrite(4,1);  //Back right Motor A
  digitalWrite(5,0);  //Back right Motor B

  digitalWrite(6,0); //Back left Motor A
  digitalWrite(7,1); //Back left Motor B

  digitalWrite(8,0);  //Front left Motor A
  digitalWrite(9,1);  //Front left Motor B

  digitalWrite(10,1); //Front right Motor A
  digitalWrite(11,0); //Front right Motor B
}

void right()
{
  digitalWrite(4,0);  //Back right Motor A
  digitalWrite(5,1);  //Back right Motor B

  digitalWrite(6,1); //Back left Motor A
  digitalWrite(7,0); //Back left Motor B

  digitalWrite(8,1);  //Front left Motor A
  digitalWrite(9,0);  //Front left Motor B

  digitalWrite(10,0); //Front right Motor A
  digitalWrite(11,1); //Front right Motor B
}

void loop()
{
uint8_t buf[VW_MAX_MESSAGE_LEN]={0};
uint8_t buflen = VW_MAX_MESSAGE_LEN;
if (vw_get_message(buf, &buflen)) 
{
if(char(buf[0])=='u' && char(buf[1])=='p')
forward();
else if(char(buf[0])=='d' && char(buf[1])=='o' && char(buf[2])=='w' && char(buf[3])=='n')
backward();
else if(char(buf[0])=='l' && char(buf[1])=='e' && char(buf[2])=='f' && char(buf[3])=='t')
left();
else if(char(buf[0])=='r' && char(buf[1])=='i' && char(buf[2])=='g' && char(buf[3])=='h' && char(buf[4])=='t')
right();
else if(char(buf[0])=='n' && char(buf[1])=='o' && char(buf[2])=='n' && char(buf[3])=='e')
stopm();
vw_wait_rx();
}
delay(1);
}
