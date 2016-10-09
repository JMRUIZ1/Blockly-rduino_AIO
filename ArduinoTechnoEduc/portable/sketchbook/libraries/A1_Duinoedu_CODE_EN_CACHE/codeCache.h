//******************************************************************//
//	                                                                //
//	                  CODE CACHE POUR ARDUBLOCK                     //
//	    PLACEZ ICI LES SECTIONS DE CODE QUE VOUS VOULEZ APPELER     // 
//	            PAR UN MOT CLE DANS ARDUINO OU ARDUBLOCK            //
//                                                                  //
//******************************************************************//
/*
	Par David Souder - souder.d@gmail.com
	Derni�re modification : le 31/03/2015
*/

/* UTILITE :
	- Permet de cr�er des blocs de code personnels et cach�s pouvant �tre appel�s 
	par un simple mot cl� dans Arduino ou Ardublock.
*/

/* PRINCIPE D'UTILISATION :
	- Il faut consid�rer 3 zones :
		o HEAD (au dessus du setup)
		o SETUP
		o LOOP
	- Suivant la zone dans laquelle vous voulez placer du code personnel cach�,
	�crivez celui-ci dans la zone : HEAD, SETUP ou LOOP en suivant ce canvas.
		
*/	

//-- A GARDER SVP 
#ifndef codeCache_H
#define codeCache_H
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include <WProgram.h>
#include "Wire.h"
#endif


//[ ZONE HEAD ]//////////////////////////////////////////////
	// 01 : Ecrivez le code que vous voulez ajouter en ent�te ci dessous (pas d'erreur de syntaxe SVP):	
	#define HEAD_EN_CACHE0 					    	    \
		int maVariableEnCache;							\
		/*A remplacer par vos d�clarations*/			\
		/*A remplacer par vos d�clarations*/			\
		// Espace � garder !
	#define HEAD_EN_CACHE1 					    	    \
		/*A remplacer par vos d�clarations*/			\
		/*A remplacer par vos d�clarations*/			\
		/*A remplacer par vos d�clarations*/			\
		// Espace � garder !
	#define HEAD_EN_CACHE2 					    	    \
		/*A remplacer par vos d�clarations*/			\
		/*A remplacer par vos d�clarations*/			\
		/*A remplacer par vos d�clarations*/			\
		// Espace � garder !
		
	// 02 Utilisez l'�tiquette AJOUT_HEAD dans Ardublock pour appeler cette section de programme
	// 03 ou �crivez HEAD_EN_CACHE0,1,2... ; au dessus du setup() du logiciel Arduino si vous n'utilisez pas Ardublock		
		/* Exemples :
		int maVariableCachee=0;			// Une variable integer 
		String maChaineCachee;			// Une cha�ne de caract�res
		char monTableauCache[10];		// Un tableau
		*/
	
	
	
	
	
//[ ZONE SETUP ]//////////////////////////////////////////////
	// 01 : Ecrivez le code que vous voulez ajouter dans le setup() ci dessous :													
	#define SETUP_EN_CACHE0 do					    	\
	{													\
		maVariableEnCache = 50; 						\
		/*A remplacer par votre code*/ 					\
		/*A remplacer par votre code*/ 					\
	} while(0)
	
	#define SETUP_EN_CACHE1 do					        \
	{													\
		/*A remplacer par votre code*/ 					\
		/*A remplacer par votre code*/ 					\
		/*A remplacer par votre code*/ 					\
	} while(0)
	
	#define SETUP_EN_CACHE2 do					        \
	{													\
		/*A remplacer par votre code*/ 					\
		/*A remplacer par votre code*/ 					\
		/*A remplacer par votre code*/ 					\
	} while(0)
	
	
	// 02 Utilisez l'�tiquette SECTION_SETUP dans Ardublock pour appeler cette section de programme
	// 03 ou �crivez SETUP_EN_CACHE0,1,2... ; dans le setup() du logiciel Arduino si vous n'utilisez pas Ardublock
		/* Exemples :
		maVariableCachee=50;			
		maChaineCachee="Hello World !";			
		monTableauCache[0]='a';	
		monTableauCache[1]='b';	
		*/
	
	
	
	
//[ ZONE LOOP ]////////////////////////////////////////////// 
	// 01 : Ecrivez le code que vous voulez ajouter dans le loop() ci dessous :													
	#define LOOP_EN_CACHE0 do					    	\
	{													\
		/*A remplacer par votre code*/					\
		/*A remplacer par votre code*/					\
		/*A remplacer par votre code*/					\
	} while(0)
	
	#define LOOP_EN_MEMOIRE1 do					    	\
	{													\
		/*A remplacer par votre code*/					\
		/*A remplacer par votre code*/ 					\
		/*A remplacer par votre code*/ 					\
	} while(0)
	
	#define LOOP_EN_MEMOIRE2 do			    	        \
	{													\
		/*A remplacer par votre code*/					\
		/*A remplacer par votre code*/ 					\
		/*A remplacer par votre code*/ 					\
	} while(0)
	
	// 02 Utilisez l'�tiquette AJOUT_LOOP dans Ardublock pour appeler cette section de programme
	// 03 ou �crivez LOOP_EN_CACHE0,1,2... ; dans le setup() du logiciel Arduino si vous n'utilisez pas Arduino
		/* Exemples :
		maVariableCachee++;					// Incr�ment de 1 � chaque passage dans le loop()		
		*/

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
// Plus tard, peut-�tre ferrez-vous vos propres libraries
class codeCache{

	public:
	
	codeCache();

	protected:



};
#endif
