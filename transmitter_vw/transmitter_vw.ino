#include <VirtualWire_Config.h>
#include <VirtualWire.h>

char *controller;
void setup() {
  
pinMode(13,OUTPUT); //onboard LED

vw_set_ptt_inverted(true);
vw_set_tx_pin(12);  //Reciever pin on Arduino
vw_setup(4000);// speed of data transfer Kbps

pinMode(8,OUTPUT);  //gnd connection for RF Module
pinMode(9,OUTPUT);  //vcc connection for RF Module

digitalWrite(8,1);
digitalWrite(9,0);

pinMode(A3,INPUT);  //connection for joystick switch  
pinMode(A2,INPUT);  //connection for joystick x-axis
pinMode(A0,INPUT);  //connection for joystick y-axis

}

void loop(){
  if(analogRead(A3)==0)
  {
  controller="Hardik";
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(13,1);
  }
  else if(analogRead(A0)>=1000)
  {
  controller="up";
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(13,1);
  }
  else if(analogRead(A0)<=10)
  {
  controller="down";
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(13,1);
  }
  else if(analogRead(A2)>=1000)
  {
  controller="right";
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(13,1);
  }
  else if(analogRead(A2)<=10)
  {
  controller="left";
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(13,1);
  }
  else
  {
  controller="none";
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(13,0);
  }
  delay(1); //delay of 1ms between recieving cycles
}
