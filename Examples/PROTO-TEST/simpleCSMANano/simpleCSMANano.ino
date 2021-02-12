//#include <SoftwareSerial.h>
#include "simpleCSMA.h"
#define TBASE			20
#define nstep			1000

modbus_t txobj, rxobj;
//toggle per più pulsanti
uint8_t statet[1]={0}; 
uint8_t precval[1]={0}; 
unsigned long prec=0;
byte led=9; 
byte btn=2;
byte txpin=10;
uint8_t val;
unsigned long step = 0;


void setup()
{
  pinMode(txpin, OUTPUT);  
  pinMode(led, OUTPUT); 
  pinMode(btn, INPUT);
  // Open serial communications and wait for port to open:
  //Serial.begin(19200);
  //Serial.println("I am nano!");
  init(&Serial, txpin, 2, 1, 9600); // port485, txpin, mysa, mygroup4, speed=9600
  //preparazione messaggio TX (parallelo)
  txobj.u8da = 0xFF; 
  txobj.msglen = 1;
  //txobj.data = "Salve sono Nano da disp 1";
  //txobj.msglen = strlen((char*)txobj.data )+1;
}



void loop() // run over and over
{
	poll(&rxobj,&val);
	
	if(millis()-prec > TBASE){
		prec = millis();
		step = (step + 1) % nstep;    // conteggio circolare arriva al massimo a nstep-1
		
		if(!(step%random(0, 10))){	
			statet[0] = !statet[0];
			txobj.data = &statet[0];
			sendMsg(&txobj);
		}	
	}
}

void rcvEventCallback(modbus_t* rcvd){
	//////Serial.println((const char*) rcvd->data);
	////Serial.println(val);
	digitalWrite(led, val);
	////Serial.print("RCV_LED: ");
}




