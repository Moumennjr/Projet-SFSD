#define b 85	// le nombre maximal d'enregistrements dans un bloc

 // structure d'un enregistrement
typedef struct Tenreg { 
   int matricule;			  		 // la matricule (4 bytes)
	char nom[31];    		 		 // le nom (31 bytes)
   char prenom[34]; 				 // le prenom (34 bytes)
	char date_naissance[11];	 // la date de naissance (11 bytes)
	int wilaya_naissance; 		 // la wilaya de naissance (4 bytes)
	int groupe_sanguin;	    	 // le groupe sanguin (4 bytes)
	int grade;				 		 // le grade (4 bytes)
	int force_armee;				 // la force armee (4 bytes)
	int region_militaire;		 // la region militaire (4 bytes)
   // la taille de l'enregistrement est :  100 bytes
} Tenreg;

// structure d'un bloc
typedef struct Tbloc {
   Tenreg tab[b];  // un tableau d'enregistrements d'une capacite b (8500 bytes)
	int nb;         // nombre d'enregistrements dans tab (<= b)  (4 bytes)
	int suiv;		 // bloc suivant  (4 bytes)
   // la taille du bloc est : 8508 bytes
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

// structure du fichier LObarreF (fichier cu comme tableau, non ordonne avec enregistrements de taille fixe)
typedef struct LObarreF {
   FILE *fich;  // 12 bytes (8 bytes + 4 bytes du padding)
   Entete entete;  // 24 bytes
   // la taille de la structure du fichier est : 36 bytes
} LObarreF;


// variables generales
LObarreF *F;   // fichier de structure LObarreF
Buffer buf;    // region tampon dans la MC


/***************************** La structure index ************************************/
// structure d'un index 
typedef struct Index {
   int cle;						// la cle d'un personnel
   int adr;						// l'adresse de ce personnel dans le fichier LObarreF
   int age;						// l'age d'un personnel	
   int grade;					// le grade d'un personnel
   int force_armee;			//	la force armee d'un personnel
   int region_militaire;	// la region militaire d'un personnel
	// la taille d'un index est : 24 bytes
} Index;
