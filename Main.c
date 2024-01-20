#include "fonction.c"


int main () {
	system("clear");
	
	printf("\n\t\t\t\t\t Soyez les bienvenues !\n\n\n\n ");
   for (int each = 0; each < 4; ++each) {
	   printf ( "\r\t\t\tChargement du programme de gestion du corps militaire %.*s   \b\b\b", each, "...");
      fflush ( stdout);//force printing as no newline in output
      system("sleep 1");
  	}
	srand(time(NULL));
	while (1) {
		system("clear");
		printf("Les options disponibles sont : \n\n");
		printf("\t1) Creation du fichier de donnees PERSONNEL-ANP_DZ.bin\n");
		printf("\t2) Epuration du fichier de donnees PERSONNEL-ANP_DZ.bin des dupliques (deduplication)\n");
		printf("\t3) Insertion d'un nouvel personnel au fichier de donnees PERSONNEL-ANP_DZ.bin\n");
		printf("\t4) Modification de la region militaire d'un personnel\n");
		printf("\t5) Suppression d'un ou plusieurs personnels selon un critere donne\n");
		printf("\t6) Consultation d'un ou plusieurs personnels selon un critere donne \n");
		printf("\t7) Fragmentation du fichier de donnees PERSONNEL-ANP_DZ.bin en 6 fichiers selon la region militaire \n");
		printf("\t8) Manipulation des fichiers de la structure du corps militaire \n");
		printf("\n\n\tPour quitter, veuillez faire entrer CTRL+C \n");
		printf("\t\t \n");
		printf("Veuillez choisir une option : ");
		int opt;

switch(opt) {
case 1: {}   //Creation du fichier
case 2: {}  // Epuration du fichier de donnees
case 3: {}  // Insertion d'un nouvel personnel au fichier de donnees 
case 4: {}  //Suppression
case 5: {}  //recherche 
}



