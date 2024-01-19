// fonction pour generer la matricule
int rand_matricule() {return (rand() % 888889 +  111111);}

// fonction pour generer le nom
char *rand_nom() {
	static const char lettres[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char nom = (char) malloc (31 * sizeof(char));
	int taille = rand() % 28 + 3;
	for (int i = 0; i < taille; i++) {
		nom[i] = lettres[(int) (rand() % (sizeof(lettres) - 1))];
	}
	nom[taille] = '\0';
	return nom;
}



// fonction pour generer le prenom
char *rand_prenom() { 
	static const char lettres[] = "abcdefghijklmnopqrstuvwxyz";
	char prenom = (char) malloc (34 * sizeof(char));
	int taille = rand() % 30 + 4;
	for (int i = 0; i < taille; i++) {
		prenom[i] = lettres[(int) (rand() % (sizeof(lettres) - 1))];
	}
	prenom[taille] = '\0';
	return prenom;
}


/ fonction pour generer la date de naissance
char *rand_date() {
	char date = (char) malloc (11 * sizeof(char));
	date[0] = rand() % 2 + 1 + '0';
	if (date[0] == 2 + '0') {
		date[1] = 0 + '0';
		date[2] = 0 + '0';
		date[3] = rand() % 4 + '0';
	} else if (date[0] ==  1 + '0') {
		date[1] = 9 + '0';
		date[2] = rand() % 6 + 4 + '0';
		date[3] = rand() % 10 + '0';
	}
	date[4] = '/';
	date[5] = rand() % 2 + '0';
	if (date[5] == 1 + '0') {
		date[6] = rand() % 2 + 1 + '0';
	} else if (date[5] == 0 + '0') {
		date[6] = rand() % 9 + 1 + '0';
	}
	date[7] = '/';
	char annee = (char) malloc (5 * sizeof(char));
	strncpy(annee, date, 4);
	annee[4] = '\0';
	if (atoi(annee) % 4 == 0) {   // une annee bissextile
		if ((date[5] == 0 + '0') && (date[6] == 2 + '0')) {   // mois de fevrier
			date[8] =  rand() % 3 + '0';
			if (date[8] ==  3 + '0') {
				date[9] = rand() % 2 + '0';
			} else {
				date[9] = rand() % 9 + 1 + '0';
			}
		} else {
			date[8] =  rand() % 4 + '0';
			if (date[8] ==  3 + '0') {
				date[9] = rand() % 2 + '0';
			} else {
				date[9] = rand() % 9 + 1 + '0';
			}
		}
	} else {    // une annee non-bissextile
		date[8] =  rand() % 4 + '0';
		if (date[8] ==  3 + '0') {
			date[9] = rand() % 2 + '0';
		} else {
			date[9] = rand() % 9 + 1 + '0';
		}
	}
	free(annee);
	date[10] = '\0';
	return date;
}




/ fonction pour generer la wilaya de naissance
int rand_wilaya(int n) { return (rand() % n + 1);}



/ fonction pour generer le groupe sanguin
int rand_groupe_sanguin() { return (rand() % 8 + 1);}


// fonction pour generer le grade
int rand_grade(int n) { return (rand() % n + 1);}
