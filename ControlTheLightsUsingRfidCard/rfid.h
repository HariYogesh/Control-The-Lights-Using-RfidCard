#ifndef RFID_H
#define RFID_H




unsigned char card_id[15];
long rfid_read()
{
       while(serial_available()<=8);
        _delay_ms(50);
		 serial_read();
			    serial_read();	
	   
	    s_readbuffer(card_id,8);	       
		char *eptr;  
		
		 s_clearbuffer();
		
			return strtol(card_id,  eptr, 16);
}


#endif