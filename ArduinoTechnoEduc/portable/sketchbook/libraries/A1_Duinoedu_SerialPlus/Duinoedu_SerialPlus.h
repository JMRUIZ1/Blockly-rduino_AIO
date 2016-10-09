/*
 
  Original Author: David Souder - souder.d@gmail.com
  Date de derni�re modification : 25/05/2015
  www.duinoedu.com - Tous droits r�serv�s
  
*/

#ifndef Duinoedu_SerialPlus_H
#define Duinoedu_SerialPlus_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include <WProgram.h>
//#include "Wire.h"
#endif


//#include <___.h>
#include <SoftwareSerial.h>
//#include "EDU_debug.h"
//#include "EDU_define.h"

//#define DEBUG
#define SERIALPLUS_NBR_OF_CAN 99

#define SERIALPLUS_DEFAULT_INTERVAL 50		// Dur�e minimum entre 2 transmissions par d�faut	
#define SERIALPLUS_FIRST_DATE 500;			// 1�res donn�es pas avant 500ms au d�marrage 

//#define brancher branch
//#define demarrer begin

#define SERIALPLUS_MEMORISER 				-1
#define IRREMOTE_MEMORISER_TOUCHE			-1
#define IRREMOTE_MEMORISER      			-1
#define DUINOEDU_MEMORISER_TOUCHE			-1
#define DUINOEDU_MEMORISER					-1

#define SERIALPLUS_MEMORISER_200_MS 		200
#define IRREMOTE_MEMORISER_200_MS 		    200
#define DUINOEDU_MEMORISER_200_MS 		    200

#define DUINOEDU_MEMORISER_500_MS 			500
#define DUINOEDU_MEMORISER_1000_MS 			1000

#define SERIALPLUS_MEMORISER_2000_MS 		2000
#define IRREMOTE_MEMORISER_2000_MS 		    2000
#define DUINOEDU_MEMORISER_2000_MS 			2000

#define DUINOEDU_MEMORISER_5000_MS 			5000
#define DUINOEDU_MEMORISER_10000_MS 		10000

#define SERIALPLUS_NE_PAS_MEMORISER 		0
#define IRREMOTE_NE_PAS_MEMORISER 		    0
#define DUINOEDU_NE_PAS_MEMORISER 			0



#define variable1Octet byte
#define variable2octet int
#define variableTexte  String

// A faire : bas de page

class Duinoedu_SerialPlus {

  public:
	
	//========== INITIALISATION
		/*CONSTRUCTOR*/			Duinoedu_SerialPlus();
		
		/*EDU US*/	void 		branch					(HardwareSerial *ser);				// Par un pointeur sur Serial
		/*EDU US*/	void 		branch					(SoftwareSerial *ser);				// Par un pointeur sur Softserial
		/*EDU US*/	void 		branch					(uint8_t rxPin, uint8_t txPin);		// Par 2 broches soft
				
		/*EDU US*/	void 		begin					(uint16_t speed);
	
	
	
	//==========  FONCTIONS UTILISATEUR
	
		//===== [ MODE MONOCANAL : APP INVENTOR : ]
			// Lecture d'un vrai boolean
					bool  		readBoolean				(int option=200);					// Avec prise en compte d'un temps de vie du r�sultat
					uint8_t  	lastValBool;
					uint16_t 	lifeTimeBool;												// Dur�e de vie enregistr�e pour les boolean
					uint32_t 	lastTimeBool;												// Date du dernier enregistrement
					uint8_t  	trueValBool;												// La derni�re valeur lue et m�moris�e
	
	
			// App Inventor : byte
					byte 		recevoir1Octet			(int option=200);
					byte 		readByte				(int option=200);	
					uint32_t 	lastTimeByte;									    		// Date de dernier enregistrement de la valeur texte
					byte   		valByte;													// M�morisation 
	
			// App Inventor : Integer
					int 		recevoir2Octet			(int option=200);
					int 		readInteger				(int option=200);	
					uint32_t 	lastTimeInteger;											// Date de dernier enregistrement de la valeur texte
					int   		valInteger;													// M�morisation 
	
			// App Inventor : String
					String 		recevoirTexte			(int option=200);
					String 		readText				(int option=200);	
					uint32_t 	lastTimeText;												// Date de dernier enregistrement de la valeur texte
					String   	valText;													// M�morisation 


			//-- Fonctions plus bas niveau
					bool  		effectiveReadBoolean	();
					int   		effectiveReadInteger	();

			// App Inventor : byte
					void 		envoyer1Octet			(byte nbr, 		int interval=200);
					void 		writeByte				(byte nbr, 		int interval=200);
		
			// App Inventor : integer
					void 		envoyer2Octet			(int nbr, 		int interval=200);
					void 		writeInteger			(int nbr, 		int interval=200);	
		
			// App Inventor : String
					void 		envoyerTexte			(String text, 	int intervalTimerAppInventor=200,	int nbrOctet=0);
					void 		writeText				(String text, 	int intervalTimerAppInventor=200,	int nbrOctet=0);
	
	
		
		//===== [ MODE MULTICANAUX : ECHANGES MULTICANAUX ]
					void 		print					(int16_t nbr, uint8_t cnl, uint16_t interval=SERIALPLUS_DEFAULT_INTERVAL);	// Envoie la donn�e avec un interval minimum 
					int  		readNbr					(uint8_t can);						// Retourne la derni�re valeur disponible en multicanaux (lue ou enregistr�e)
	
			//-- Fonctions bas niveau
					void 		send					(int16_t nbr, uint8_t cnl);			// Inconditionnelle			
					void 		receiveNbr();												// Met � jour le tableau values[canaux]

			//-- M�moire
					int16_t 	values[SERIALPLUS_NBR_OF_CAN];
					uint16_t   	minInterval;												// Interval minimal entre 2 transmissions (attention � l'effet de pr�f�rence)
	

		

					
	
		//===== [ FONCTION BLUETOOTH ]	
					void 		btVerbose(bool _verbose);
								bool verbose;
					
					void 		btSetName(String btName);
					void		btGetName();
					
		
		//===== [ FONCTIONS SERIAL DE BASE ]
					int			print(String text);
					char		read();
					int			available();
					void 		viderBufferDeReception();									// Le flush des nouvels Arduino ne vide plus le buffer de r�ception
					void 		flushReceptionBuffer();					
					

	//========== LES POINTEURS HARD & SOFT
			SoftwareSerial *serialSoft;
			HardwareSerial *serialHard;

	
  protected:

		uint32_t 	m_dates[SERIALPLUS_NBR_OF_CAN];											// Doit stoker la date de la derni�re mesure pour tous les canaux
		uint32_t 	m_dateLastSent;
	
		void endBranch();
	

};
#endif

// A FAIRE
/*
	Gestion par serialEvent() => https://digistump.com/board/index.php?topic=966.0


// Trame <canal:valeur><canal:valeur> attente <canal:valeur><canal:valeur>

// Exemple programme Arduino
// PARTIE EMETTEUR //////////////
/* Duinoedu_SerialPlus exemple 
   Recevoir les infos de 2 potentiom�tres sur 2 LED 
   POT1 => LED1
   POT2 => LED2
   David Souder - 19/04/2015
*/
/*
#include <Duinoedu_SerialPlus.h>
Duinoedu_SerialPlus monSerialPlus;

void setup(){
  monSerialPlus.branch(&Serial);
  monSerialPlus.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
}

void loop(){
  monSerialPlus.print(analogRead(A0), CANAL0);
  monSerialPlus.print(analogRead(A1), CANAL1);
  Serial.print(88888888);
}
*/

// PARTIE RECEPTEUR //////////////
/* Duinoedu_SerialPlus exemple 
   Recevoir les infos de 2 potentiom�tres sur 2 LED 
   POT1 => LED1
   POT2 => LED2
   David Souder - 19/04/2015
*/
/*
#include <Duinoedu_SerialPlus.h>
const int pinLed1 = 3; // UNO 3,5,6,9,10,11
const int pinLed2 = 5; // UNO 3,5,6,9,10,11
Duinoedu_SerialPlus monSerialPlus;

void setup(){
  monSerialPlus.branch(&Serial);
  monSerialPlus.begin(9600);
  pinMode(pinLed1,OUTPUT);
  pinMode(pinLed2,OUTPUT);
}

void loop(){
    analogWrite(pinLed1,monSerialPlus.readNbr(CANAL0)/4); 
    analogWrite(pinLed2,monSerialPlus.readNbr(CANAL1)/4);
}
*/

  

  
  
  
  




