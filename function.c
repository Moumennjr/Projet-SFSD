#include "affichage.c"


/*Les fonction pour generer les champs aleatoirement*/
// fonction pour generer la matricule
int rand_matricule() {return (rand() % 888889 +  111111);}

// fonction pour generer le nom
char *rand_nom() {
	static const char lettres[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *nom = (char*) malloc (31 * sizeof(char));
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
	char *prenom = (char*) malloc (34 * sizeof(char));
	int taille = rand() % 30 + 4;
	for (int i = 0; i < taille; i++) {
		prenom[i] = lettres[(int) (rand() % (sizeof(lettres) - 1))];
	}
	prenom[taille] = '\0';
	return prenom;
}

// fonction pour generer la date de naissance
char *rand_date() {
	char *date = (char*) malloc (11 * sizeof(char));
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
	char *annee = (char*) malloc (5 * sizeof(char));
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
// fonction pour generer la wilaya de naissance
int rand_wilaya(int n) { return (rand() % n + 1);}
// fonction pour generer le groupe sanguin
int rand_groupe_sanguin() { return (rand() % 8 + 1);}
// fonction pour generer le grade
int rand_grade(int n) { return (rand() % n + 1);}
// fonction pour genererla force armee
int rand_force_armee(int n) { return (rand() % n + 1);}
// fonction pour generer la region militaire
int rand_region_militaire (int n) { return (rand() % n + 1);}

// fonction pour creer un personnel militaire
Tenreg creer_perso(int force_armee, int grade, int region_militaire, int wilaya) {
	Tenreg personnel;
	memset(&personnel, 0, sizeof(Tenreg));
	personnel.matricule = rand_matricule();
	strcpy(personnel.nom, rand_nom());
	strcpy(personnel.prenom, rand_prenom());
	strcpy(personnel.date_naissance, rand_date());
	personnel.wilaya_naissance = rand_wilaya(wilaya);
	personnel.groupe_sanguin = rand_groupe_sanguin();
	personnel.grade = rand_grade(grade);
	personnel.force_armee = rand_force_armee(force_armee);
	personnel.region_militaire = rand_region_militaire(region_militaire);
	return personnel;
}

void Fusion(Index *arr, int p, int q, int r, int opt) {
	// Create L ← A[p..q] and M ← A[q+1..r]
   int n1 = q - p + 1;
   int n2 = r - q;
   Index L[n1], M[n2];

   for (int i = 0; i < n1; i++)  L[i] = arr[p + i];
   for (int j = 0; j < n2; j++)  M[j] = arr[q + 1 + j];
	
   int i = 0, j = 0, k = p;
	switch(opt) {
		case 1: { 		// tri par rapport au cles
			while (i < n1 && j < n2) {
				if (L[i].cle <= M[j].cle) {
					arr[k] = L[i];   i++;
				} else {
					arr[k] = M[j];   j++;
				}
				k++;
			}
			while (i < n1) {
				arr[k] = L[i];
				i++;  k++;
			}
			while (j < n2) {
				arr[k] = M[j];
				j++;	k++;
			}
			break;
		}
		case 2: { 		// tri par rapport a l'adresse 
			while (i < n1 && j < n2) {
				if (L[i].adr <= M[j].adr) {
					arr[k] = L[i];   i++;
				} else {
					arr[k] = M[j];   j++;
				}
				k++;
			}
			while (i < n1) {
				arr[k] = L[i];
				i++;  k++;
			}
			while (j < n2) {
				arr[k] = M[j];
				j++;	k++;
			}
			break;
		}
		case 3: { 		// tri par rapport a l'age
			while (i < n1 && j < n2) {
				if (L[i].age <= M[j].age) {
					arr[k] = L[i];   i++;
				} else {
					arr[k] = M[j];   j++;
				}
				k++;
			}
			while (i < n1) {
				arr[k] = L[i];
				i++;  k++;
			}
			while (j < n2) {
				arr[k] = M[j];
				j++;	k++;
			}
			break;
		}
		case 4: { 		// tri par rapport au grade
			while (i < n1 && j < n2) {
				if (L[i].grade <= M[j].grade) {
					arr[k] = L[i];   i++;
				} else {
					arr[k] = M[j];   j++;
				}
				k++;
			}
			while (i < n1) {
				arr[k] = L[i];
				i++;  k++;
			}
			while (j < n2) {
				arr[k] = M[j];
				j++;	k++;
			}
			break;
		}
		case 5: { 		// tri par rapport a la force armee
			while (i < n1 && j < n2) {
				if (L[i].force_armee <= M[j].force_armee) {
					arr[k] = L[i];   i++;
				} else {
					arr[k] = M[j];   j++;
				}
				k++;
			}
			while (i < n1) {
				arr[k] = L[i];
				i++;  k++;
			}
			while (j < n2) {
				arr[k] = M[j];
				j++;	k++;
			}
			break;
		}
		case 6: { 		// tri par rapport a la region militaire
			while (i < n1 && j < n2) {
				if (L[i].region_militaire <= M[j].region_militaire) {
					arr[k] = L[i];   i++;
				} else {
					arr[k] = M[j];   j++;
				}
				k++;
			}
			while (i < n1) {
				arr[k] = L[i];
				i++;  k++;
			}
			while (j < n2) {
				arr[k] = M[j];
				j++;	k++;
			}
			break;
		}
	}
}

// Module pour trier la table d'index par tri fusion
void Tri(Index *index, int l, int r, int opt) {
	 if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;
    Tri(index, l, m, opt);
    Tri(index, m + 1, r, opt);
    // Merge the sorted subarrays
    Fusion(index, l, m, r, opt);
   }
}

// Module pour chargement initial du fichier LObarreF 
void Chargement_Initial(char *nom_fichier, int N) {
	FILE *F1 = fopen("BDD/force_armee.bin", "rb");		 // Ouverture du fichier des forces armees disponibles
	FILE *F2 = fopen("BDD/grade.bin", "rb"); 				 // Ouverture du fichier des grades disponibles
	FILE *F3 = fopen("BDD/region_militaire.bin", "rb"); // Ouverture du fichier des regions militaires disponibles
	FILE *F4 = fopen("BDD/wilaya.bin", "rb"); 			 // Ouverture du fichier des wilayas disponibles

	int force_armee, grade, region_militaire, wilaya;
	fread(&force_armee, sizeof(int), 1, F1);		 // Lecture du nombre de forces armees disponibles
	fread(&grade, sizeof(int), 1, F2);				 // Lecture du nombre de grades  disponibles
	fread(&region_militaire, sizeof(int), 1, F3); // Lecture du nombre de regions militaires disponibles
	fread(&wilaya, sizeof(int), 1, F4);				 // Lecture du nombre de wilayas disponibles
	
	fclose(F1);		// Fermeture du fichier des forces armees
	fclose(F2);		// Fermeture du fichier des grades
	fclose(F3); 	// Fermeture du fichier des region millitaires
	fclose(F4); 	// Fermeture du fichier des wilayas

	Tenreg personnel;
	Index index[N];	// La table d'index
	int i, j;
	i = 1;
	j = 0;
	F = Ouvrir(nom_fichier, 'N');				// Ouverture du fichier de donnees
	FILE *G = fopen("index.bin", "wb+");	// Ouverture du fichier d'index
	fwrite(&N, sizeof(int), 1, G);			// Ecriture du nombre de peronnels dans le fichier d'index
   char *annee = (char*) malloc (5 * sizeof(char));
	for (int k = 0; k < N; k++) {		// chargement du fichier et de la table d'index simultanement
		memset(&personnel, 0, sizeof(Tenreg));
		memset(&index[k], 0, sizeof(Index));
		personnel = creer_perso(force_armee, grade, region_militaire, wilaya);
		index[k].cle = personnel.matricule;
		index[k].adr = k;
		index[k].grade = personnel.grade;
		index[k].force_armee = personnel.force_armee;
		index[k].region_militaire = personnel.region_militaire;
      strncpy(annee, personnel.date_naissance, 4);
      annee[4] = '\0';
		index[k].age = 2022 - atoi(annee);

		if (j < b) {	// espace suffisant dans ce bloc 
			buf.tab[j] = personnel;
			j++;
		} else {			//espace insuffisant dans ce bloc
			buf.nb = j;
			buf.suiv = i + 1;
			EcrireDir(F, i, buf);
			buf.tab[0] = personnel;
			i++;
			j = 1;	
		}
	}
	free(annee);
	buf.nb = j;		// le dernier bloc
	buf.suiv = -1;
	EcrireDir(F, i, buf);
	Aff_entete(F, 1, i);		//	mise a jour du nombre de blocs
	Aff_entete(F, 3, i);		//	mise a jour du dernier bloc
	Aff_entete(F, 4, N);		//	mise a jour du compteur d'insertion

	Tri(index, 0, N - 1, 1);  // Tri de la table d'index selon les matrices
	fwrite(&index, sizeof(Index), N, G);	// Ecriture de la table d'index dans le fichier d'index
	Fermer(F);		// Fermeture du fichier de donnees
	fclose(G);		// Fermeture du fichier d'index
}

// Module pour la recherche dichotomique dans la table d'index
void Recherche_Dichotomique(Index *index, int N, int cle, int opt, int *pos, int *trouve) {
	int inf = 0, sup = N - 1, pos1 = 0, mid = 0;
	*trouve = 0, *pos = N - 1;
	switch(opt) {
		case 1: {		// recherche par rapport a la cle
			while (inf <= sup) {
				mid = (inf + sup) / 2;
		 
				if (index[mid].cle == cle) {
					*trouve = 1;
					pos1 = mid;
					break;
				}
				if (index[mid].cle > cle) {
					sup = mid - 1;
				}
				if (index[mid].cle < cle) {
					inf = mid + 1;
				}
			}
			if (*trouve) {
				*pos = pos1;
			} else {
				*pos = mid;
			}
			break;
		}
		case 2: {		// recherche par rapport a l'adresse
			while (inf <= sup) {
				mid = (inf + sup) / 2;
		 
				if (index[mid].adr == cle) {
					*trouve = 1;
					pos1 = mid;
					break;
				}
				if (index[mid].adr > cle) {
					sup = mid - 1;
				}
				if (index[mid].adr < cle) {
					inf = mid + 1;
				}
			}
			if (*trouve) {
				*pos = pos1;	
			} else {
				*pos = mid;
			}
			break;
		}
		case 3: {		// recherche par rapport a l'age
			while (inf <= sup) {
				mid = (inf + sup) / 2;
		 
				if (index[mid].age == cle) {
					*trouve = 1;
					pos1 = mid;
					break;
				}
				if (index[mid].age > cle) {
					sup = mid - 1;
				}
				if (index[mid].age < cle) {
					inf = mid + 1;
				}
			}
			if (*trouve) {
				*pos = pos1;	
			} else {
				*pos = mid;
			}
			break;
		}		  
		case 4: {		// recherche par rapport au grade
			while (inf <= sup) {
				mid = (inf + sup) / 2;
		 
				if (index[mid].grade == cle) {
					*trouve = 1;
					pos1 = mid;
					break;
				}
				if (index[mid].grade > cle) {
					sup = mid - 1;
				}
				if (index[mid].grade < cle) {
					inf = mid + 1;
				}
			}
			if (*trouve) {
				*pos = pos1;	
			} else {
				*pos = mid;
			}
			break;  
		}
		case 5: {		// recherche par rapport a la force armee
			while (inf <= sup) {
				mid = (inf + sup) / 2;
		 
				if (index[mid].force_armee == cle) {
					*trouve = 1;
					pos1 = mid;
					break;
				}
				if (index[mid].force_armee > cle) {
					sup = mid - 1;
				}
				if (index[mid].force_armee < cle) {
					inf = mid + 1;
				}
			}
			if (*trouve) {
				*pos = pos1;
			} else {
				*pos = mid;
			}
			break;
		}
		case 6: {		// recherche par rapport a la region militaire
			while (inf <= sup) {
				mid = (inf + sup) / 2;
		 
				if (index[mid].region_militaire == cle) {
					*trouve = 1;
					pos1 = mid;
					break;
				}
				if (index[mid].region_militaire > cle) {
					sup = mid - 1;
				}
				if (index[mid].region_militaire < cle) {
					inf = mid + 1;
				}
			}
			if (*trouve) {
				*pos = pos1;
			} else {
				*pos = mid;
			}
			break;		  
		}	
	}
}


// Module pour rechercher un personnel selon la matricule
void Recherche(LObarreF *F, int matricule, int *trouve, int *i, int *j) {
	FILE *G = fopen("index.bin", "rb");	// Ouverture du fichier d'index
	int N = entete(F, 4) - entete(F, 5);	// Le nombre de personnels dans le fichier de donnees
	int pos = 0;
	Index index[N];	// La table d'index
	fseek(G, sizeof(int), SEEK_SET);			// Positionnement sur le debut de la table d'index
	fread(&index, sizeof(Index), N, G);		// Recuperation de la table d'index
	Recherche_Dichotomique(index, N, matricule, 1, &pos, trouve);	// Recherche dichotomique selon les matricules

	if (*trouve) {
		*i = index[pos].adr / 85 + 1;		// Le numero de bloc 
		*j = index[pos].adr % 85;			// La position dans le bloc
	} else {
		*i = entete(F, 3);	// Le bloc queue
		*j = N  % 85;			// La derniere position
	}
	fclose(G);
}

// Module d'insertion dans un fichier LObarreF
void Insertion(LObarreF *F)  {
	int trouve, i, j;
	FILE *F1 = fopen("BDD/force_armee.bin", "rb");		 // Ouverture du fichier des forces armees disponibles
	FILE *F2 = fopen("BDD/grade.bin", "rb"); 				 // Ouverture du fichier des grades disponibles
	FILE *F3 = fopen("BDD/region_militaire.bin", "rb"); // Ouverture du fichier des regions militaires disponibles
	FILE *F4 = fopen("BDD/wilaya.bin", "rb"); 			 // Ouverture du fichier des wilayas disponibles

	int force_armee, grade, region_militaire, wilaya;
	fread(&force_armee, sizeof(int), 1, F1);		 // Lecture du nombre de forces armees disponibles
	fread(&grade, sizeof(int), 1, F2);				 // Lecture du nombre de grades  disponibles
	fread(&region_militaire, sizeof(int), 1, F3); // Lecture du nombre de regions militaires disponibles
	fread(&wilaya, sizeof(int), 1, F4);				 // Lecture du nombre de wilayas disponibles
	
	fclose(F1);		// Fermeture du fichier des forces armees
	fclose(F2);		// Fermeture du fichier des grades
	fclose(F3); 	// Fermeture du fichier des region millitaires
	fclose(F4); 	// Fermeture du fichier des wilayas

	// Creation d'un personnel selon les fichiers precedents
	Tenreg personnel = creer_perso(force_armee, grade, region_militaire, wilaya);
	
	Recherche(F, personnel.matricule, &trouve, &i, &j);	// Recherche du personnel par son matricule
	if (!trouve) {		// le personnel est inexistant

		if (!entete(F, 1)) {		// fichier vide
			// insertion en premier bloc en premiere position
			buf.tab[0] = personnel;
			buf.nb = 1;
			buf.suiv = -1;
			EcrireDir(F, 0, buf);
			Aff_entete(F, 4, entete(F, 4) + 1);
		} else {						// fichier non-vide
			// insertion en dernier bloc en derniere position
			LireDir(F, entete(F, 3), &buf);
			// cas 1: dernier bloc pas plein
			if (buf.nb < b) {
				buf.tab[buf.nb] = personnel;
				buf.nb++;
				EcrireDir(F, entete(F, 3), buf);
				Aff_entete(F, 4, entete(F, 4) + 1);
			} else {
				// cas 2: dernier bloc plein
				// allocation d'un nouveau bloc vide
				Alloc_Bloc(F);	
				buf.tab[0] = personnel;
				buf.nb = 1;
				buf.suiv = -1;
				EcrireDir(F, entete(F, 3), buf);
				Aff_entete(F, 4, entete(F, 4) + 1);		
			}
		} 
		FILE *G = fopen("index.bin", "rb+");		// Ouverture du fichier d'index
		if (G != NULL) {
			int N = entete(F, 4) - entete(F, 5);	// Le nombre de personnels 
			Index ind;
			Index *index = (Index*) malloc (N * sizeof(Index));	// La table d'index
			fseek(G, sizeof(int), SEEK_SET);				// Positionnement sur le debut de la table d'index
			fread(index, sizeof(Index), N - 1, G);		// Recuperation de la table d'index
			ind.cle = personnel.matricule;
			ind.adr = N - 1;
			ind.grade = personnel.grade;
			ind.force_armee = personnel.force_armee;
			ind.region_militaire = personnel.region_militaire;
			char *annee = (char*) malloc (5 * sizeof(char));
			strncpy(annee, personnel.date_naissance, 4);
			annee[4] = '\0';
			ind.age = 2022 - atoi(annee);
			free(annee);
			index[N - 1] = ind;			// Ajout de l'index construit a la table d'index
			Tri(index, 0, N - 1, 1);	// Tri de la table d'index selon les matricules
			rewind(G);
			fwrite(&N, sizeof(int), 1, G);		// Mise a jour du nombre d'enregistrement dans le fichier d'index
			fwrite(index, sizeof(Index), N, G);	// Mise a jour de la table d'index dans le fichier d'index	
			free(index);
			fclose(G);		// Fermeture du fichier d'index
		}
		printf("Operation d'insertion terminee avec succes!\n");
	} else {
		printf("Ce personnel est existant!\n");
	}
}


// Module pour supprimer un  personnel a une position donnee
void Suppression1(LObarreF *F, int i, int j) {
	Buffer buf1, buf2;
	LireDir(F, i, &buf);
	if (i == entete(F, 3)) {
		LireDir(F, i, &buf);
		buf.tab[j] = buf.tab[buf.nb - 1];		// Ecrasement de l'enregistrement par le dernier enregistrement
		buf.nb--;									   // Decrementation du nombre d'enregistrements dans le bloc
		if (buf.nb > 0) {
			EcrireDir(F, i, buf);
		} else {
			if (entete(F, 3) == 1) {
				EcrireDir(F, i, buf);
			} else {
				Aff_entete(F, 1, entete(F, 1) - 1);		// Mise a jour du nombre de bloc utilises
				Aff_entete(F, 3, entete(F, 3) - 1);		// Mise a jour de la queue
			}
		}
	} else {
		// le bloc concerne n'est pas le bloc queue
		LireDir(F, i, &buf1);
		LireDir(F, entete(F, 3), &buf2);
		buf1.tab[j] = buf2.tab[buf2.nb - 1];
		buf2.nb--;
		EcrireDir(F, i, buf1);
		if (buf2.nb > 0) {
		// cas 1: dernier bloc contient plusieurs personnel ( > 1)
			EcrireDir(F, entete(F, 3), buf2);
		} else {
		// cas 2: dernier bloc contient un seul personnel
			Aff_entete(F, 1, entete(F, 1) - 1);		// Mise a jour du nombre de bloc utilises
			Aff_entete(F, 3, entete(F, 3) - 1);		// Mise a jour de la queue
		}
	}
	Aff_entete(F, 5, entete(F, 5) + 1);	 	// Mise a jour du compteur de suppresssion
}

// Module d'epuration dans un fichier LObarreF
void Epuration(LObarreF *F) {
	FILE *G = fopen("index.bin", "rb+");	// Ouverture du fichier d'index
	if (G != NULL) {
		int N;
		fread(&N, sizeof(int), 1, G);		// Recuperation du nombre de personnels
		Index index[N];						// La table d'index
		fread(&index, sizeof(Index), N, G);		// Recuperation de la table d'index
		Index *temp = (Index*) malloc (N * sizeof(Index));		// Une table d'index temporaire(ne contient pas de duplique)
		int j = 0;
		for (int i = 0; i < N - 1; i++) {
			if (index[i].cle !=  index[i + 1].cle) {
				temp[j++] = index[i]; 	// Insertion dans la table temporaire
			} else {
				Suppression1(F, (index[i + 1].adr / 85) + 1, index[i + 1].adr % 85);	// Suppression du fichier de donnes
			}	
		}
		temp[j] = index[N - 1];	
		rewind(G);
		fwrite(&j, sizeof(int), 1, G);		// Mise a jour du nombre de personnels
		fwrite(temp, sizeof(Index), j, G);	// Mise a jour de la table d'index
		free(temp);
		fclose(G);	// Fermeture du fichier de donnees
	}
}

// Module pour modifier la region militaire d'un personnel donnee par son matricule
Tenreg Modifier_Region_Militaire(LObarreF *F, int matricule, int region_militaire, int *pos) {
	int trouve, i, j;

	Recherche(F, matricule, &trouve, &i, &j);	// Recherche du personnel par son matricule
	if (trouve) {		// le personnel est inexistant
		LireDir(F, i, &buf);
		buf.tab[j].region_militaire = region_militaire;
		EcrireDir(F, i, buf);	// Mise a jour dans le fichier de donnees
		FILE *G = fopen("index.bin", "rb+");	// Ouverture du fichier d'index
		if (G != NULL) {
			Index index;
			fseek(G, sizeof(int) + ((i - 1) * b + j) * sizeof(Index), SEEK_SET);	// Positionnement sur ce personnel
			fread(&index, sizeof(Index), 1, G);				// Recuperation de l'index donnee
			index.region_militaire = region_militaire;	// Changement de la region militaire de l'index
			fseek(G, -sizeof(Index), SEEK_CUR);				// Repositionnement sur cet index
			fwrite(&index, sizeof(Index), 1, G);			// Mise a jour de cet index
			fclose(G);		// Fermeture du fichier d'index
		}
		*pos = (i - 1) * b + j + 1;
		return buf.tab[j];
	} else {
		printf("Ce personnel est inexistant dans le fichier de donnees!\n");
	}
}

// Module de suppression physique dans un fichier LObarreF
void Suppression(LObarreF *F, int matricule) {
	int i, j, trouve;
	Buffer buf1, buf2;

	Recherche(F, matricule, &trouve, &i, &j);
	if (trouve) {
		// le bloc concerne est le bloc queue
		if (i == entete(F, 3)) {
			LireDir(F, i, &buf);
			buf.tab[j] = buf.tab[buf.nb - 1];		// Ecrasement de l'enregistrement par le dernier enregistrement
			buf.nb--;									   // Decrementation du nombre d'enregistrements dans le bloc
			if (buf.nb > 0) {
				EcrireDir(F, i, buf);					
			} else {
				if (entete(F, 3) == 1) {
					EcrireDir(F, i, buf);						
				} else {
					Aff_entete(F, 1, entete(F, 1) - 1);		// Mise a jour du nombre de bloc utilises
					Aff_entete(F, 3, entete(F, 3) - 1);		// Mise a jour de la queue
				}
			}
		} else {
			// le bloc concerne n'est pas le bloc queue
			LireDir(F, i, &buf1);
			LireDir(F, entete(F, 3), &buf2);
			buf1.tab[j] = buf2.tab[buf2.nb - 1];
			buf2.nb--;
			EcrireDir(F, i, buf1);					
			if (buf2.nb > 0) {
			// cas 1: dernier bloc contient plusieurs personnel ( > 1)
				EcrireDir(F, entete(F, 3), buf2);
			} else {
			// cas 2: dernier bloc contient un seul personnel
				Aff_entete(F, 1, entete(F, 1) - 1);		// Mise a jour du nombre de bloc utilises
				Aff_entete(F, 3, entete(F, 3) - 1);		// Mise a jour de la queue
			}
		}
		Aff_entete(F, 5, entete(F, 5) + 1);	 	// Mise a jour du compteur de suppresssion
		FILE *G = fopen("index.bin", "rb+");	// Ouverture du fichier d'index
		if (G != NULL) {
			int N;
			fread(&N, sizeof(int), 1, G);			// Recuperation du nombre de personnels
			Index *index = (Index*) malloc (N * sizeof(Index));	
			fread(index, sizeof(Index), N, G);	// Recuperation de la table d'index
			Tri(index, 0, N - 1, 2);		// Tri de la table d'index selon les adresses
			N--;
			index[(i - 1) * entete(F, 1) + j] = index[N];	
			Tri(index, 0, N - 1, 1);		// Tri de la table d'index selon les matricules
			rewind(G);
			fwrite(&N, sizeof(int), 1, G);		 // Mise a jour du nombre de personnels 
			fwrite(index, sizeof(Index), N, G);	 // Mise a jour de la table d'index
			free(index);
			fclose(G);		// Fermeture du fichier d'index
			printf("Operation de supression du personnel terminee avec succes!\n");
		}
	} else {
		printf("Ce personnel est inexistant dans le fichier de donnees!\n");
	}
}

// Module pour supprimer les personnels d'une force armee
void Suppression_Force_Armee(LObarreF *F, int force_armee) {
	FILE *G = fopen("index.bin", "rb+");		// Ouverture du fichier d'index
	if (G != NULL) {
		int N;
		int pos = 0, trouve = 0;
		fread(&N, sizeof(int), 1, G);				// Recuperation du nombre de personnels
		Index index[N];
		fread(&index, sizeof(Index), N, G);		// Recuperation de la table d'index
		Tri(index, 0, N - 1, 5);					// Tri de la table d'index selon les force armees
		Recherche_Dichotomique(index, N, force_armee, 5, &pos, &trouve);	// Recherche de la force armee dans la table d'index
		if (trouve) {		
			int i1 = pos - 1;
			while (index[i1].force_armee == force_armee) {	// Recuperation des personnels avant cette position
				Suppression1(F, index[i1].adr / 85 + 1,index[i1].adr % 85);
				index[i1] = index[N - 1];
				i1--;
				N--;
			}
			i1 = pos;
			while (index[i1].force_armee == force_armee) {	// Recuperation des personnels apres cette position
				Suppression1(F, index[i1].adr / 85 + 1,index[i1].adr % 85);
				index[i1] = index[N - 1];
				i1++;
				N--;
			}
			rewind(G);
			fwrite(&N, sizeof(int),  1 , G);			// Mise a jour du nombre de personnels
			Tri(index, 0, N - 1, 1);					// Tri de la table d'index selon les matricules
			fwrite(&index, sizeof(Index), N, G);	// Mise a jour de la table d'index dans le fichier d'index
			printf("Operation de suppression de la force armee terminee avec succes!\n");
		} else {
			printf("Cette force armee est indisponible !\n");
		}
	}
	fclose(G);		// Fermeture du fichier d'index
}

// Module pour consulter tous les personnels d'une region donnee ayant l'age dans l'intervalle donne
Tenreg *Recherche_Intervale(LObarreF *F, int region_militaire, int age_min, int age_max, int *n) {
	FILE *G = fopen("index.bin", "rb");		// Ouverture du fichier d'index
	if (G != NULL) {
		*n = 0;
		int pos = 0, trouve = 0;
		int N;
		fread(&N, sizeof(int), 1, G);			 // Recuperation du nombre de personnels
		Index index[N];
		fread(&index, sizeof(Index), N, G);	 // Recuperation de la table d'index	
		Tri(index, 0, N - 1, 6);				 // Tri de la table d'index selon les regions militaires
		Recherche_Dichotomique(index, N, region_militaire, 6, &pos, &trouve);
		if (trouve) {
			Index *ind = (Index*) malloc (N * sizeof(Index));
			int i1 = pos - 1;
			int j1 = 0;
			// Recuperation des index avent cette postion 
			while ((i1 >= 0) && (index[i1].region_militaire == region_militaire)) {	
				if ((index[i1].age >= age_min) && (index[i1].age <= age_max)) {
					ind[j1++] = index[i1];
				}
				i1--;	
			}
			i1 = pos;
			// Recuperation des index apres cette postion 
			while ((i1 <= N - 1) && (index[i1].region_militaire == region_militaire)) {
				if ((index[i1].age >= age_min) && (index[i1].age <= age_max)) {
					ind[j1++] = index[i1];
				}	
				i1++;
			}
			if (j1 == 0) {
				free(ind);
				printf("Il n'y a pas de personnels selon ce critere!\n");
				fclose(G);
			} else {
				ind = (Index*) realloc (ind, j1 * sizeof(Index));		
				Tenreg *personnels = (Tenreg*) malloc (j1 * sizeof(Tenreg));
				Tri(ind, 0, j1 - 1, 2);
				for (int k = 0; k < j1; k++) {
					LireDir(F, ind[k].adr / 85 + 1, &buf);	 		// Recuperation du bloc a utiliser
					personnels[k] = buf.tab[ind[k].adr % 85];		// Chargement dans la table des personnels
				}
				*n = j1;
				free(ind);
				fclose(G);		// Fermeture du fichier d'index
				return personnels;		// Retourne la table des personnels
			}
		} else {
			printf("Pas de personnels de cette region militaire! \n");
		}
	}
	fclose(G);	// Fermeture du fichier d'index
}

// Module pour consulter tous les personnels appartenant a une categorie de grade donnee
Tenreg *Recherche_Categorie_Grade(LObarreF *F, int categorie, int *n) {
	// 1 : Officiers-generaux : 1 : Général de corps d’armée, 2 : Général-Major, 3 : Général [1, 2, 3]
	// 2 : Officiers-superieurs : 4 : Colonel, 5: Lieutenant-colonel, 6 : Commandant [4, 5, 6]
	// 3 : Officiers : 7 : Capitaine, 8 :  Lieutenant, 9 : Sous-lieutenant, 10 : Aspirant [7, 8, 9, 10]
	// 4 : Sous-officiers : 11 : Adjudant-chef, 12 : Adjudant, 13 : Sergent-chef, 14 : Sergent [11, 12, 13, 14]
	// 5 : Hommes de troupes : 15 : Caporal-chef, 16 : Caporal, 17 : Djoundi [15, 16, 17]
	FILE *G = fopen("index.bin", "rb");		// Ouverture du fichier d'index
	if (G != NULL) { 
		int N;
		fread(&N, sizeof(int), 1, G);				// Recuperation du nombre de personnels
		Index index[N];
		fread(&index, sizeof(Index), N, G);		// Recuperation de la table d'index	
		Tri(index, 0, N - 1, 4);					// Tri de la table d'index selon grade
		
		Index *ind = (Index*) malloc (N * sizeof(Index));
		int pos = 1, trouve = 0, existe = 0, j1 = 0;
		switch(categorie) {
			case 1: {	// Officiers-generaux
				Recherche_Dichotomique(index, N, 1, 4, &pos, &trouve);
				if (trouve) {
					existe = 1;
					int i1 = pos - 1;
					while ((i1 >= 0) && (index[i1].grade == 1)) {
						ind[j1++] = index[i1--];
					}
					i1 = pos;
					while ((i1 <= N - 1) && (index[i1].grade <= 3)) {
						ind[j1++] = index[i1++];
					}	
				} else {
					Recherche_Dichotomique(index, N, 2, 4, &pos, &trouve);
					if (trouve) {
						existe = 1;
						int i1 = pos - 1;
						while ((i1 >= 0) && (index[i1].grade == 2)) {
							ind[j1++] = index[i1--];
						}
						i1 = pos;
						while (index[i1].grade <= 3) {
							ind[j1++] = index[i1++];
						}
					} else {
						Recherche_Dichotomique(index, N, 3, 4, &pos, &trouve);
						if (trouve) {
							existe = 1;
							int i1 = pos - 1;
							while ((i1 >= 0) && (index[i1].grade == 3)) {
								ind[j1++] = index[i1--];
							}
							i1 = pos;
							while ((i1 <= N - 1) && (index[i1].grade == 3)) {
								ind[j1++] = index[i1++];
							}	
						}
					}
				}
				break;		  
	 	   }
			case 2: {	// Officiers-superieurs
				Recherche_Dichotomique(index, N, 4, 4, &pos, &trouve);
				if (trouve) {
					existe = 1;
					int i1 = pos - 1;
					while ((i1 >= 0) && (index[i1].grade == 4)) {
						ind[j1++] = index[i1--];
					}
					i1 = pos;
					while ((i1 <= N - 1) && (index[i1].grade <= 6)) {
						ind[j1++] = index[i1++];
					}	
				} else {
					Recherche_Dichotomique(index, N, 5, 4, &pos, &trouve);
					if (trouve) {
						existe = 1;
						int i1 = pos - 1;
						while ((i1 >= 0) && (index[i1].grade == 5)) {
							ind[j1++] = index[i1--];
						}
						i1 = pos;
						while ((i1 <= N - 1) && (index[i1].grade <= 6)) {
							ind[j1++] = index[i1++];
						}
					} else {
						Recherche_Dichotomique(index, N, 6, 4, &pos, &trouve);
						if (trouve) {
							existe = 1;
							int i1 = pos - 1;
							while ((i1 >= 0) && (index[i1].grade == 6)) {
								ind[j1++] = index[i1--];
							}
							i1 = pos;
							while ((i1 <= N - 1) && (index[i1].grade == 6)) {
								ind[j1++] = index[i1++];
							}	
						}
					}
				}		
				break;  
			}
			case 3: {	// Officiers
				Recherche_Dichotomique(index, N, 7, 4, &pos, &trouve);
				if (trouve) {
					int i1 = pos - 1;
					while ((i1 >= 0) && (index[i1].grade == 7)) {
						ind[j1++] = index[i1--];
					}
					i1 = pos;
					while ((i1 <= N - 1) && (index[i1].grade <= 10)) {
						ind[j1++] = index[i1++];
					}	
				} else {
					Recherche_Dichotomique(index, N, 8, 4, &pos, &trouve);
					if (trouve) {
						existe = 1;
						int i1 = pos - 1;
						while ((i1 >= 0) && (index[i1].grade == 8)) {
							ind[j1++] = index[i1--];
						}
						i1 = pos;
						while ((i1 <= N - 1) && (index[i1].grade <= 10)) {
							ind[j1++] = index[i1++];
						}
					} else {
						Recherche_Dichotomique(index, N, 9, 4, &pos, &trouve);
						if (trouve) {
							existe = 1;
							int i1 = pos - 1;
							while ((i1 >= 0) && (index[i1].grade == 9)) {
								ind[j1++] = index[i1--];
							}
							i1 = pos;
							while ((i1 <= N - 1) && (index[i1].grade <= 10)) {
								ind[j1++] = index[i1++];
							}	
						} else {
							Recherche_Dichotomique(index, N, 10, 4, &pos, &trouve);
							if (trouve) {
								existe = 1;
								int i1 = pos - 1;
								while ((i1 >= 0) && (index[i1].grade == 10)) {
									ind[j1++] = index[i1--];
								}
								i1 = pos;
								while ((i1 <= N - 1) && (index[i1].grade == 10)) {
									ind[j1++] = index[i1++];
								}
							}	
						}
					}
				}		
				break;		  
			}
			case 4: {	// Sous-officiers 
				Recherche_Dichotomique(index, N, 11, 4, &pos, &trouve);
				if (trouve) {
					existe = 1;
					int i1 = pos - 1;
					while ((i1 >= 0) && (index[i1].grade == 11)) {
						ind[j1++] = index[i1--];
					}
					i1 = pos;
					while ((i1 <= N - 1) && (index[i1].grade <= 14)) {
						ind[j1++] = index[i1++];
					}	
				} else {
					Recherche_Dichotomique(index, N, 12, 4, &pos, &trouve);
					if (trouve) {
						existe = 1;
						int i1 = pos - 1;
						while ((i1 >= 0) && (index[i1].grade == 12)) {
							ind[j1++] = index[i1--];
						}
						i1 = pos;
						while ((i1 <= N - 1) && (index[i1].grade <= 14)) {
							ind[j1++] = index[i1++];
						}
					} else {
						Recherche_Dichotomique(index, N, 13, 4, &pos, &trouve);
						if (trouve) {
							existe = 1;
							int i1 = pos - 1;
							while ((i1 >= 0) && (index[i1].grade == 13)) {
								ind[j1++] = index[i1--];
							}
							i1 = pos;
							while ((i1 <= N - 1) && (index[i1].grade <= 14)) {
								ind[j1++] = index[i1++];
							}	
						} else {
							Recherche_Dichotomique(index, N, 14, 4, &pos, &trouve);
							if (trouve) {
								existe = 1;
								int i1 = pos - 1;
								while ((i1 >= 0) && (index[i1].grade == 14)) {
									ind[j1++] = index[i1--];
								}
								i1 = pos;
								while ((i1 <= N - 1) && (index[i1].grade == 14)) {
									ind[j1++] = index[i1++];
								}
							}	
						}
					}
				}		
				break;		  
			}
			case 5: {	// Hommes de troupes 
				Recherche_Dichotomique(index, N, 15, 4, &pos, &trouve);
				if (trouve) {
					existe = 1;
					int i1 = pos - 1;
					while (i1 >= 0 && index[i1].grade == 15) {
						ind[j1++] = index[i1--];
					}
					i1 = pos;
					while ((i1 <= N - 1) && (index[i1].grade <= 17)) {
						ind[j1++] = index[i1++];
					}	
				} else {
					Recherche_Dichotomique(index, N, 16, 4, &pos, &trouve);
					if (trouve) {
						existe = 1;
						int i1 = pos - 1;
						while (i1 >= 0 && index[i1].grade == 16) {
							ind[j1++] = index[i1--];
						}
						i1 = pos;
						while ((i1 <= N - 1) && (index[i1].grade <= 17)) {
							ind[j1++] = index[i1++];
						}
					} else {
						Recherche_Dichotomique(index, N, 17, 4, &pos, &trouve);
						if (trouve) {
							existe = 1;
							int i1 = pos - 1;
							while (i1 >= 0 && index[i1].grade == 17) {
								ind[j1++] = index[i1--];
							}
							i1 = pos;
							while ((i1 <= N - 1) && (index[i1].grade == 17)) {
								ind[j1++] = index[i1++];
							}	
						}
					}
				}
				break;		  
			}
		}	
	  Tenreg *personnels = NULL;	
	   if (existe) {	
			*n = j1;
			ind = (Index*) realloc (ind, j1 * sizeof(Index));
			personnels = (Tenreg*) malloc (j1 * sizeof(Tenreg));
			Tri(ind, 0, j1 - 1, 2);
			for (int k = 0; k < j1; k++) {
				LireDir(F, ind[k].adr / 85 + 1, &buf);			// Recuperation du bloc a utiliser
				personnels[k] = buf.tab[ind[k].adr % 85];		// Chargement dans la table des personnels
			}
			free(ind);
			fclose(G);			// Fermeture du fichie d'index
		} else {
			printf("Cette categorie de grades est inexistante !\n");
		}
		return personnels;		// Retourne la table des personnels 
	}
	fclose(G);		// Fermeture du fichier d'index
}

// Module pour fragmenter le fichier en 6 fichiers selon la region militaire
void Fragmentation(LObarreF *F) {
	FILE *F1 = fopen("F/F1", "wb+");		// Ouverture du fichier de la region militaire 1
	FILE *F2 = fopen("F/F2", "wb+");		// Ouverture du fichier de la region militaire 2
	FILE *F3 = fopen("F/F3", "wb+");		// Ouverture du fichier de la region militaire 3
	FILE *F4 = fopen("F/F4", "wb+");		// Ouverture du fichier de la region militaire 4
	FILE *F5 = fopen("F/F5", "wb+");		// Ouverture du fichier de la region militaire 5
	FILE *F6 = fopen("F/F6", "wb+");		// Ouverture du fichier de la region militaire 6

	if ((F1!=NULL) && (F2!=NULL) && (F3!=NULL) && (F4!=NULL) && (F5!=NULL) && (F6!=NULL)) {
		for (int i = 1; i <= entete(F, 1); i++) {
			memset(&buf, 0, sizeof(Buffer));
			LireDir(F, i, &buf);
			for (int j = 0; j < buf.nb; j++)  {
				int k = buf.tab[j].region_militaire;
				switch(k) {
					case 1: {	// Region militaire 1
						fwrite(&buf.tab[j], sizeof(Tenreg), 1, F1);
						break;		  
					}
					case 2: {	// Region militaire 2
						fwrite(&buf.tab[j], sizeof(Tenreg), 1, F2);
						break;		  
					}
					case 3: {	// Region militaire 3
						fwrite(&buf.tab[j], sizeof(Tenreg), 1, F3);
						break;		  
					}
					case 4: {	// Region militaire 4
						fwrite(&buf.tab[j], sizeof(Tenreg), 1, F4);
						break;		  
					}
					case 5: {	// Region militaire 5
						fwrite(&buf.tab[j], sizeof(Tenreg), 1, F5);
						break;		  
					}
					case 6: {	// Region militaire 6
						fwrite(&buf.tab[j], sizeof(Tenreg), 1, F6);
						break;		  
					}			
				}
			}	
		}
	}

	fclose(F1);		// Fermeture du fichier de la region militaire 1
	fclose(F2);		// Fermeture du fichier de la region militaire 2
	fclose(F3);		// Fermeture du fichier de la region militaire 3
	fclose(F4);		// Fermeture du fichier de la region militaire 4
	fclose(F5);		// Fermeture du fichier de la region militaire 5
	fclose(F6);		// Fermeture du fichier de la region militaire 6
}
