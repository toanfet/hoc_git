/*
 * File name:
     Pt2272.c
 * Project name:
      Decoding RF Signal
 * Copyright:
     (c) Mikroelektronika, 2011.
 * Revision History:
     20110929:
       - initial release (FJ);
 * Description:
     This is a simple 'Hello World' project. It turns on/off LEDs connected to
     PORTA, PORTB, PORTC, PORTD and PORTE.
 * Test configuration:
     MCU:             PIC18F45K22
                      http://ww1.microchip.com/downloads/en/DeviceDoc/41412D.pdf
     dev.board:       easypic7 -
                      http://www.mikroe.com/eng/products/view/757/easypic-v7-development-system/
     Oscillator:      HS-PLL 32.0000 MHz, 8.0000 MHz Crystal
     Ext. Modules:    None.
     SW:              mikroC PRO for PIC
                      http://www.mikroe.com/eng/products/view/7/mikroc-pro-for-pic/
 * NOTES:
     - Turn ON the PORT LEDs at SW3.
 */
 /*
 *******************************************************************************
                         Include header file
 *******************************************************************************
 */
#include "Pt2272.h"
 /*
 *******************************************************************************
                         Define Global Variable
 *******************************************************************************/
 /*******************************************************************************
 *                         PT2272_GetAddr()
 * Description    :
 * Argument       :
 * Return
 * Caller
 * Author
 * Note
 */
 unsigned long PT2272_GetAddr( unsigned short * PT2272Buff){

     unsigned short i;
     unsigned long Ret = 0 ;
     for( i = 0 ; i < 8 ; i++){
         if(PT2272Buff[i] == PT2272_BIT0)                Ret = (unsigned long)( Ret *10 + 0) ;
         else if (PT2272Buff [i] == PT2272_BIT1)         Ret = (unsigned long)( Ret *10 + 1 );
         else                                            Ret = (unsigned long)( Ret *10 + 2 );
     }
     return Ret ;
 }
 /*******************************************************************************
 *                         PT2272_GetData()
 * Description    :
 * Argument       :
 * Return
 * Caller
 * Author
 * Note
 */
 unsigned short PT2272_GetData ( unsigned short * PT2272Buff){

     unsigned short Ret = 0;
     unsigned short i;
     for( i = 8 ; i < 12 ; i++){
         Ret |= ((PT2272Buff[i] == PT2272_BIT1) ? 1 : 0) << (11 - i);
     }
     return Ret ;
 }
 /*EOF*/
