/////////////////////////////////////////////////////////////////////////////////////////////////////
///  Project Name : ControlTheLightsUsingRfidCard
//
//  Target Board : atmega32
//
//  Date Created : 06-Apr-18 12:27:00 PM
// 
//  Online Resource  : www.electronicsforstudents.com
//
//  Libraries Included : 
/////////////////////////////////////////////////////////////////////////////////////////////////////


#include<avr/io.h>
#include<util/delay.h>


#include "serial.h"
#include "lcd.h"
#include "rfid.h"


int main()
{
	unsigned long cardnumber;	//creating a variable of type char in order to store the card number
	
	lcd_init();	//initializing the lcd 
	
	serial_init(9600); 	//initializing the serial comm
	
	serial_select(0);	//selecting serial comm 0
	
	lcd_string("Swipe Card");
	
	int light=0;
	
	while (1)
	{
	cardnumber = rfid_read(); //function to rad the rfid value as per written in the library
	
	lcd_gotoxy(0,1);
	lcd_num(cardnumber);	//displaying the rfid value on the lcd
	if((cardnumber==8764230) && (light==0))
	{
	write(portb,all,h);
	//write(porta,2,h);
	light=1;
	
	}
	
	if((cardnumber==8764230) &&(light==1))
	{
	  write(portb,all,l);
	light =0;
	//write(porta,2,l);
	
	
	}
	}
	
	

}