#define b 80	// le nombre maximal d'enregistrements dans un bloc





// structure d'un enregistrement
typedef struct Tenreg { 
   int matricule;			  		 // la matricule (4 bytes)
	char nom[31];    		 		 // le nom (31 bytes)
   char prenom[34]; 				 // le prenom (34 bytes)
	char date_naissance[11];	 // la date de naissance (11 bytes)
	int wilaya_naissance; 		 // la wilaya de naissance (4 bytes)
	int groupe_sanguin;	    	 // le groupe sanguin (4 bytes)
	int grade;				 		 // le grade (4 bytes)
   // la taille de l'enregistrement est :  92 bytes
} Tenreg;






// structure d'un bloc
typedef struct Tbloc {
   Tenreg tab[b];  // un tableau d'enregistrements d'une capacite b (b*la taille de l'enregistrement=7360 bytes)
	int nb;         // nombre d'enregistrements dans tab (<= b)  (4 bytes)
	int suiv;		 // bloc suivant  (4 bytes)
   // la taille du bloc est : 7638 bytes
} Tbloc;






typedef struct Tbloc Buffer;	 // declaraion du tampon





// structure de l'entete
typedef struct Entete {
   int nb;     	 // nombre de blocs utilises (4 bytes)
	int tete; 		 // le pointeur tete	(4 bytes)
	int queue; 		 // le pointeur queue	(4 bytes)
   int cpt_inser;  // compteur d'insertions (4 bytes) 
   int cpt_supp;   // compteur de suppression (4 bytes) 
  	// la taille de l'entete est : 20 bytes
} Entete;


// structure du fichier LObarreF (fichier vu comme liste, non ordonne avec enregistrements de taille fixe)
typedef struct LObarreF {
   FILE *fich;  // 12 bytes (8 bytes + 4 bytes du padding)
   Entete entete;  // 20 bytes
   // la taille de la structure du fichier est : 32 bytes
} LObarreF;


