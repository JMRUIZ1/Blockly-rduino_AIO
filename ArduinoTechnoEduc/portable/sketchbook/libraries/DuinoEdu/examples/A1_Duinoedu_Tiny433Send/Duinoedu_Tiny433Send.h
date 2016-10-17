/*
 
	Original Author: David Souder - souder.d@gmail.com
	Date de derni�re modification : 10/11/2015
	www.duinoedu.xom - Tous droits r�serv�s
  
*/

/*
 
	Cette librairie utilise VirtualWire.
	  
*/


#ifndef Duinoedu_VirtualWireAdd_H
#define Duinoedu_VirtualWireAdd_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include <WProgram.h>
#include "Wire.h"
#endif

//---- On inclu les fonctions VirtualWire
	#include <virtualWire.h>

#include "EDU_debug.h"

#define DEBUG

#define FIXE_MESSAGE_LEN 9     	// Tous les messages ont le format <cc:vvvv>

class Duinoedu_Tiny433Send{

	public:
		//========== << CONSTRUCTEURS >>
			/*EDU FR*/	Duinoedu_Tiny433Send();
		
		//========== SETUP
			/*EDU US*/	void branch(uint8_t txPin, uint16_t speed = 2400);
		
		//========== OPERATIVE
			/*EDU US*/	void sendNbrInChanel(int nbr, uint8_t cnl=0, uint16_t interval=200);



	
	
	protected:
		// Attributs
			uint8_t 	m_txPin;					// Broche du tx pour l'envoi
			uint16_t 	m_speed;					// Vitesse des �changes 2000 environ
			uint32_t	m_lastTime;					// M�morise la date du dernier Send


};
#endif


// INFOS
/*
VirtualWire utilise des fonctions extern "C". Il n'y a pas besoin de cr�er d'objet VirtualWire

Taille du message :
	-fixe / 9 caract�res
	<cc:vvvv> avec cc = n� de canal et vvvv valeur de 0 � 9999

*/
