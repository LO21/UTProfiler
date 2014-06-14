CREATE TABLE IF NOT EXISTS UV (
	code VARCHAR(10) PRIMARY KEY,
	titre VARCHAR(100),
	responsable VARCHAR(30),
	creditsCS INTEGER(2),
	creditsTM INTEGER(2),
	creditsTSH INTEGER(2),
	creditsSP INTEGER(2),
	printemps BOOL,
	automne BOOL);

CREATE TABLE IF NOT EXISTS Branche (
	b VARCHAR(10) PRIMARY KEY);

INSERT INTO Branche VALUES ('TC');

INSERT INTO Branche VALUES ('HUTECH');

INSERT INTO Branche VALUES ('GB');

INSERT INTO Branche VALUES ('GI');

INSERT INTO Branche VALUES ('GM');

INSERT INTO Branche VALUES ('GP');

INSERT INTO Branche VALUES ('GSM');

INSERT INTO Branche VALUES ('GSU');

CREATE TABLE IF NOT EXISTS Dossier (
	login CHAR(8) PRIMARY KEY,
	nom VARCHAR(25),
	prenom VARCHAR(25),
	conseiller VARCHAR(25),
	validationAEU BOOL,
	branche VARCHAR(10));

CREATE TABLE IF NOT EXISTS Saison (
	s CHAR(1));

INSERT INTO Saison VALUES ('A');

INSERT INTO Saison VALUES ('P');

CREATE TABLE IF NOT EXISTS Semestre (
	saison CHAR(1),
	annee INTEGER(4),
	dossier CHAR(8) REFERENCES Dossier(login),
	commentaire VARCHAR(100),
    PRIMARY KEY(saison, annee, dossier)
);
	
CREATE TABLE IF NOT EXISTS Resultat (
	r VARCHAR(3));

INSERT INTO Resultat VALUES ('A');

INSERT INTO Resultat VALUES ('B');

INSERT INTO Resultat VALUES ('C');

INSERT INTO Resultat VALUES ('D');

INSERT INTO Resultat VALUES ('E');

INSERT INTO Resultat VALUES ('FX');

INSERT INTO Resultat VALUES ('F');

INSERT INTO Resultat VALUES ('EC');

INSERT INTO Resultat VALUES ('RES');

CREATE TABLE IF NOT EXISTS Inscription (
	uv VARCHAR(5) REFERENCES UV(code),
	saison CHAR(1) REFERENCES Semestre(saison),
	annee INTEGER(4) REFERENCES Semestre(annee),
	login CHAR(8) REFERENCES Semestre(dossier),
	resultat VARCHAR(3) REFERENCES Resultat(r),
	PRIMARY KEY (uv, saison, annee, login));

CREATE TABLE IF NOT EXISTS FormationExt (
	login CHAR(8) REFERENCES Dossier(login),
	nom VARCHAR(50),
	lieu VARCHAR(50) NOT NULL,
	creditsCS INTEGER(2),
	creditsTM INTEGER(2),
	creditsTSH INTEGER(2),
	creditsSP INTEGER(2),
	PRIMARY KEY (login, nom));

CREATE TABLE IF NOT EXISTS TypeFormation (
	type VARCHAR(25));

INSERT INTO TypeFormation VALUES ('Branche');

INSERT INTO TypeFormation VALUES ('Filière');

INSERT INTO TypeFormation VALUES ('Mineur');

CREATE TABLE IF NOT EXISTS Formation (
	nom VARCHAR(25) PRIMARY KEY,
	responsable VARCHAR(50),
	type VARCHAR(25) REFERENCES TypeFormation(type),
	creditsTOT INTEGER(3),
	creditsCS INTEGER(3),
	creditsTM INTEGER(3),
	creditsCSTM INTEGER(3),
	creditsTSH INTEGER(3),
	creditsSP INTEGER(3));

INSERT INTO Formation VALUES('TC','Sylviane Pulvin','Branche',120,48,24,0,24,6);

INSERT INTO Formation VALUES('HUTECH','Nicolas Salzmann','Branche',180,0,0,0,0,0);

INSERT INTO Formation VALUES('GB','Nelly Cochet','Branche',180,30,30,84,24,60);

INSERT INTO Formation VALUES('GI','Philippe Trigano','Branche',180,30,30,84,24,60);

INSERT INTO Formation VALUES('GM','Jerome Favergeon','Branche',180,30,30,84,24,60);

INSERT INTO Formation VALUES('GP','Aissa Ould Dris','Branche',180,30,30,84,24,60);

INSERT INTO Formation VALUES('GSM','Frederic Lamarque','Branche',180,30,30,84,24,60);

INSERT INTO Formation VALUES('GSU','Nassima Voyneau','Branche',180,30,30,84,24,60);

INSERT INTO Formation VALUES('ADEL','Aziz Moukrim','Filière',0,0,0,18,0,0);

INSERT INTO Formation VALUES('FDD','Benjamin Quost','Filière',0,0,0,18,0,0);

INSERT INTO Formation VALUES('ICSI','Marie Hélène Abel','Filière',0,0,0,18,0,0);

INSERT INTO Formation VALUES('MPI','Pascal Alberti','Filière',0,0,0,18,0,0);

INSERT INTO Formation VALUES('SRI','Yacine Challal','Filière',0,0,0,18,0,0);

INSERT INTO Formation VALUES('STRIE','Véronique Cherfaoui','Filière',0,0,0,18,0,0);

CREATE TABLE IF NOT EXISTS AssociationFormationUV (
	uv VARCHAR(10) REFERENCES UV(code),
	formation VARCHAR(25) REFERENCES Formation(nom),
	PRIMARY KEY (uv,formation));

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'BL01',
	'Sciences Biologiques Pour L''Ingénieur',
	6,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'BL10',
	'Structures Et Physicochimie Des Molécules Biologiques',
	6,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'BL22',
	'Microbiologie Et Biologie Moléculaire',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'CM01',
	'Physique De La Matière',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'CM11',
	'Chimie Générale',
	6,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'CM12',
	'Chimie Physique Minérale',
	6,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'CM13',
	'Chimie Des Substances Organiques Et Biologiques',
	6,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'CM15',
	'Systemes Colloidaux - Applications Agroalimentaires',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'EL01',
	'Phénomènes Electromagnétiques',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'EN21',
	'Bases De L''Electronique Analogique',
	6,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'IA02',
	'Résolution De Problèmes Et Programmation Logique',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MQ01',
	'Eléments De Resistance Des Matériaux',
	6,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MQ03',
	'Mécanique Des Vibrations I',
	6,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MQ17',
	'Introduction Aux Propriétés Mécaniques Et A L''Ingénierie Des Matériaux',
	6,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MQ18',
	'Cinématique Et Dynamique Des Systèmes',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MT10',
	'Structures,Calcul Formel Et Algorithmes',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MT12',
	'Methodes Mathematiques Pour L''Analyse Du Signal Et De L''Image',
	6,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MT22',
	'Fonctions De Plusieurs Variables Réelles Et Applications',
	6,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MT23',
	'Algèbre Linéaire Et Applications',
	6,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MT90',
	'Fonctions D''Une Variable Reelle 1',
	4,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MT91',
	'Fonctions D''Une Variable Reelle 2',
	3,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'NF04',
	'Modélisation Numérique Des Problèmes De L''Ingénieur',
	6,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'NF16',
	'Algorithmique Et Structures De Données',
	6,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'PS04',
	'Thermodynamique',
	6,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'PS91',
	'Mecanique Physique',
	6,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'PS92',
	'Dynamique Des Systemes Et Des Solides',
	3,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'PS93',
	'Optique Geometrique',
	3,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'PS94',
	'Electricite',
	3,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'RO03',
	'Recherche Opérationnelle, Optimisation Combinatoire',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'RR01',
	'Cinétique Chimique Et Réacteurs Homogènes',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SR02',
	'Systèmes D''Exploitation : Des Concepts A La Programmation',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SY01',
	'Eléments De Probabilités',
	6,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SY02',
	'Méthodes Statistiques Pour L''Ingénieur',
	6,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SY04',
	'Systèmes Asservis Linéaires : Analyse Et Commande',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SY14',
	'Eléments D''Automatique',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TF01',
	'Mécanique Des Fluides Incompressibles',
	6,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TF06',
	'Transfert De Chaleur',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TN06',
	'Transmission Des Efforts En Mécanique',
	6,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MT34',
	'Analyse 2 : Mesures, Intégrations, Probabilités',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MT37',
	'Logiques, Quelques Approfondissements Mathématiques Et Philosophiques',
	3,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MT38',
	'Probabilités',
	3,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'API06',
	'Analyse De Donnees Et Data Mining (Apprentissage)',
	4,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'API09',
	'Méthodes Et Outils Pour L''Optimisation Et La Simulation (Apprentissage)',
	4,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'BA09',
	'Introduction Au Calcul Des Structures Du Batiment',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'BI01',
	'Modeles Pour La Bioinformatique',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'BL30',
	'Physiologie Des Systèmes Intégrés',
	6,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'BL40',
	'Génie Cellulaire',
	6,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'CM40',
	'Catalyse Heterogene',
	3,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'FPP02',
	'Fiabilite Et Ingenierie Robuste De Produits (Apprentissage)',
	3,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'NF11',
	'Théorie Des Langages De Programmation',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MAT03',
	'Mecanique Des Materiaux (Apprentissage)',
	3,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MB11',
	'Révision D''Analyse Et D''Algèbre (Gb, Gi, Gsu)',
	6,
	0,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MC01',
	'Machines électriques',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MEQ03',
	'Dynamique Des Solides (Apprentissage)',
	3,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'PS05',
	'Fondements De L''Acoustique Et Modélisations',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'RO04',
	'Optimisation Et Recherche Opérationnelle',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SY06',
	'Analyse Et Traitement Du Signal',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SY09',
	'Analyse Des Données Et Data Mining',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SY15',
	'Automatique Avancée',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'UB08',
	'Hydrologie Urbaine',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MQ02',
	'Mécanique Des Solides Déformables',
	6,
	0,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'BA07',
	'Modes Opératoires De La Construction',
	0,
	5,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'BL09',
	'Biophysique Des Systèmes Biologiques',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'BM01',
	'Introduction A L''Instrumentation Biomédicale',
	0,
	5,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'BT02',
	'Opérations Agro-Industrielles',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'C2I1',
	'Certificat Informatique Et Internet Niveau 1',
	0,
	4,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'CM70',
	'Travaux Pratiques De Gp (1)',
	0,
	3,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'DD02',
	'Introduction A L''Eco-Conception Et A L''Analyse De Cycle De Vie',
	0,
	3,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'EL02',
	'Electricité Industrielle Appliquée',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'FQ01',
	'Economie Globale Et Maitrise De La Qualité',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'GE37',
	'Gestion De Projet',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LO01',
	'Bases De La Programmation',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LO21',
	'Programmation Et Conception Orientees Objet',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LO22',
	'Genie Logiciel',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MT94',
	'Introduction Aux Mathematiques Appliquées',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'NF01',
	'Algorithmique Et Programmation',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'NF02',
	'Du Circuit Intégré Au Microprocesseur',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'NF15',
	'Microprocesseurs, Interfaces Et Logiciels De Bases',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'NF17',
	'Conception De Bases De Données',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'NF22',
	'Micro-Ordinateurs Et Applications',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'NF92',
	'Traitement Automatique De L''Information',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'NP90',
	'Nano-Projets',
	0,
	2,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'NX17',
	'Introduction Aux Bases De Donnees',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'PR',
	'Réalisation De Projet',
	0,
	5,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'PS09',
	'Acoustique Appliquée',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'PS90',
	'Introduction A La Mesure',
	0,
	3,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TF14',
	'Les Opérations De Transfert De Matière',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TN01',
	'Eléments De Dessin Technique',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TN02',
	'Introduction A La Conception Mécanique',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TN03',
	'Fabrication Mécanique',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TN04',
	'Réalisation',
	0,
	4,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TN08',
	'Dessin De Communication',
	0,
	5,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TN20',
	'Cao : Modélisation Géométrique',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TN22',
	'Eléments De Bureau D''Etudes',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TR91',
	'Techniques De Recherche D''Information Pour L''Ingenieur',
	0,
	2,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TS01',
	'Maitrise Des Risques',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TX',
	'Etude Expérimentale',
	0,
	5,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'UB04',
	'Ambiances Et Environnement Lumineux',
	0,
	5,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'UR03',
	'Cartographie Sémiologie Graphique Et Cao/Dao',
	0,
	5,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'UR05',
	'Aménagement Et Environnement',
	0,
	5,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'AP',
	'Atelier Projet',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'API07',
	'Architecture Des Applications Internet, Programmation Web Et Securite (Apprentissage)',
	0,
	3,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'API08',
	'Ihm Et Multimédia (Apprentissage)',
	0,
	4,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'API10',
	'Méthodes De Vérification Et Validation De Logiciel Et Programmation Sous Linux (Apprentissage)',
	0,
	3,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'BA01',
	'Equipements Techniques Du Batiment',
	0,
	5,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'BA02',
	'Gestion Technique Du Patrimoine Immobilier',
	0,
	5,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'BA04',
	'Conversion Et Gestion Des Energies Renouvelables',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'BM02',
	'Organes Artificiels Et Biorheologie',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'BM08',
	'Modélisation Des Systèmes Biomécaniques',
	0,
	5,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'BT06',
	'Analyse Des Produits Biologiques Et Alimentaires',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'BT10',
	'Risques Biologiques Et Sécurité Alimentaire',
	0,
	5,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'BT21',
	'Biotechnologies Moleculaires Et Genie Genetique',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'BT22',
	'Les Agroressources',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'CM06',
	'Calcul D''Une Opération Industrielle',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'CT02',
	'Maitrise Statistique Des Processus',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'CT04',
	'Controles Non Destructifs',
	0,
	5,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'DI03',
	'Conception Formelle Des Produits',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'DI05',
	'Methodologie Et Analyse De La Valeur',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'DI06',
	'Analyse Des Produits De Consommation',
	0,
	5,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'EG01',
	'Ergonomie',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'EN14',
	'Fonctions Electroniques Pour L''Ingénieur',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'EV01',
	'Procédés De Traitement Des Déchets',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'FQ07',
	'La Qualité Des Services A L''Industrie',
	0,
	5,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'GE38',
	'Management Et Outils D''Aide A La Créativité Industrielle Et A L''Innovation',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'GE39',
	'Management Et Marketing De L''Innovation',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'GPL01',
	'Gestion De Production Et Erp (Apprentissage)',
	0,
	5,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'IA04',
	'Systèmes Multiagents',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LO17',
	'Indexation Et Recherche D''Information',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LO18',
	'Projets Multimédia Pour La Formation',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MC05',
	'Machines De Transfert De Fluides',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MC07',
	'Electronique De Puissance',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MI03',
	'Systèmes Temps Réel',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MP02',
	'Introduction Aux Méthodes De La Gpao',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MQ04',
	'Polymères',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MQ06',
	'Modélisation Des Structures Par Eléments Finis',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MQ08',
	'Elaboration Et Proprietes D''Usage Des Metaux',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MQ09',
	'Mécanique Des Vibrations II',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MQ10',
	'Comportement Mécanique Des Matériaux',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MQ11',
	'Mise En Oeuvre Des Matériaux',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MQ14',
	'Optimisation En Mécanique',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MQ19',
	'Dynamique Des Structures',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MS02',
	'Principes Physiques Des Capteurs Et Instrumentation',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MS03',
	'Pratique Expérimentale En Acoustique Et Vibrations',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'NF24',
	'Modelisation Et Simulation Des Procedes',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'NF26',
	'Data Warehouse Et Outils Décisionnels',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'NF28',
	'Ingénierie Des Systèmes Intéractifs',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'NF33',
	'Conception Et Architecture De Systèmes Numériques Informatiques',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SCI08',
	'Introduction A L''Ingenierie Systeme',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SR03',
	'Architecture Des Applications Internet',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SY05',
	'Conduite Des Procédés',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SY12',
	'Modélisation Et Performance Des Systèmes De Production',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SY26',
	'Télécommunications',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TA02',
	'Evaluation Economique Des Procédés',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TF07',
	'Calcul Des Echangeurs Thermiques Industriels',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TF08',
	'Hydrodynamique Des Systèmes Dispersés',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TMI01',
	'Conception Niveau 2 (Apprentissage)',
	0,
	5,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TMI05',
	'Fabrication Assistee Par Ordinateur Et Machines A Commande Numerique (Apprentissage)',
	0,
	3,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TN12',
	'Conception Mécanique',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TN13',
	'Dimensionnement Pour La Conception Des Systemes Mecaniques',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TN15',
	'Création De Produit, D''Activité, D''Entreprise',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TN24',
	'Technologies De Fabrication Et Outils Méthodes',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TN29',
	'Outils De Definition Et De Developpement De Systemes',
	0,
	6,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TN30',
	'Xao En Milieu Professionnel',
	0,
	3,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'UB02',
	'Systemes De Transport Urbain',
	0,
	5,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'UB06',
	'Mises En Scènes Urbaines',
	0,
	5,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'UR01',
	'Droit De L''Urbanisme, De La Construction Et De L''Environnement',
	0,
	5,
	0,
	0,
	1,
	0);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'UXD01',
	'Design D''Experience',
	0,
	6,
	0,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'AR03',
	'Art Et Technologies Contemporaines',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'DI01',
	'Initiation Au Design Industriel',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'DI02',
	'Initiation Au Design Graphique',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'EI03',
	'Communication Interculturelle En Entreprises, Organisations Transnationales',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'EI04',
	'Intelligence économique : Stratégie D''Entreprise, Démarche Et Outils',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'EI05',
	'Science, Technologie Et Société Dans L''Union Européenne',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'GE10',
	'Economie Politique',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'GE12',
	'Géographie Et économie Des Territoires',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'GE13',
	'Les Risques Entre Technique Et Societe',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'GE15',
	'Initiation A La Création Et Gestion D''Entreprises Innovantes',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'GE20',
	'Economie Industrielle',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'GE21',
	'Economie Et Gestion De L''Innovation Et Du Numérique',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'GE22',
	'Economie Internationale',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'GE23',
	'Transferts De Technologies Et Développements',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'GE24',
	'Recherche Developpement : Ingenieur Et Investisseurs',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'GE25',
	'Gestion Et Organisation De La Production',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'GE26',
	'Management Stratégique Des Ressources Humaines',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'GE28',
	'Economie Et Droit De La Propriété Intellectuelle (Industrielle Et Artistique) Dans Une économie Reposant Sur La Connaissance',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'GE29',
	'Gestion Et Management International De L''Entreprise',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'GE36',
	'Marketing',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'GE90',
	'Organisation, Innovation Et International',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'HE01',
	'Epistémologie Et Histoire Des Sciences',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'HE03',
	'Logique : Histoire Et Formalisme',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'HE05',
	'Culture Et Histoire Des Techniques',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'IC01',
	'Histoire Et Prospective Des Industries Culturelles',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'IC03',
	'Le Numérique : Des Formats Aux Chaines De Production',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'IC05',
	'Technologies Pour La Documentation Et L''Indexation Dans L''Hypermédia',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'IC07',
	'Techniques Et Technologies Du Musical Et Du Sonore',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LA00',
	'Allemand Initiation',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LA01',
	'Allemand Niveau I',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LA02',
	'Allemand Niveau II',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LA03',
	'Allemand Niveau III',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LA04',
	'Pratique De La Communication En Allemand',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LA11',
	'Anglais Niveau I',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LA12',
	'Anglais Niveau II',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LA13',
	'Anglais Niveau III',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LA14',
	'Civilisation Du Monde Anglophone',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LA15',
	'Anglais Professionnel - Niveau V',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LA20',
	'Espagnol Initiation',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LA21',
	'Espagnol Niveau I',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LA22',
	'Espagnol Niveau II',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LA23',
	'Espagnol Niveau III',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LA24',
	'Le Monde Hispanique Contemporain : L''Amérique Latine (Niveau IV)',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LA91',
	'Francais Langue étrangère Niveau I',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LA92',
	'Francais Langue étrangère Niveau II',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LA93',
	'Francais Langue étrangère Niveau III',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LA94',
	'Francais Langue étrangère Niveau IV',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LB04',
	'Interculturalité Franco-Allemande',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LB14',
	'Interculturalité Appliquée Aux Pays Anglophones',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LB24',
	'Le Monde Hispanique (Niveau IV): L''Espagne',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LC14',
	'Communication Scientifique Et Technique En Anglais',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LG30',
	'Japonais Initiation',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LG31',
	'Japonais Niveau I',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LG40',
	'Portugais Initiation',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LG41',
	'Portugais Niveau I',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LG42',
	'Portugais Niveau II',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LG50',
	'Italien Initiation',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LG51',
	'Italien Niveau I',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LG52',
	'Italien Niveau II',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LG60',
	'Chinois Initiation',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'LG61',
	'Chinois Niveau I',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MU01',
	'Pratique Instrumentale D''Ensemble',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MU02',
	'Pratique Instrumentale De Haut Niveau',
	0,
	0,
	8,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'MU03',
	'Pratique Collective Des Musiques Contemporaines',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'PH01',
	'Introduction A La Philosophie',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'PH09',
	'Ethiques : Approche Pluridisciplinaire',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SA11',
	'Pratiques Théatrales',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SC01',
	'Séminaire Interdisciplinaire De Sciences Et Technologies Cognitives',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SC11',
	'Théorie Des Sciences Cognitives : Computation Et énaction',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SC12',
	'Technologie, Cognition, Perception',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SC21',
	'Linguistique Et Philosophie Du Langage',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SC22',
	'Sociologie Cognitive, Lien Social Et Techniques',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SI01',
	'Science Et Debat Public',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SI02',
	'Communication Professionnelle De L''Ingénieur',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SI05',
	'Theories De La Communication',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SI06',
	'La Documentattion Cross-Media Pour Les Entreprises Et Les Collectivites Locales',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SI07',
	'Medias Classiques Et Medias Numeriques',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SI11',
	'Expression Orale- Parole Publique',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SI14',
	'Parole Publique En Anglais',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SI20',
	'Rhetorique Et Arts Du Discours',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SI22',
	'Signes Et Contenus Numeriques',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SI24',
	'Etudes Des écritures Numériques Ordinaires',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SI28',
	'Ecriture Interactive Et Multimédia',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SI90',
	'Séminaire De Communication Des Connaissances Technologiques',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SL',
	'Suivi Linguistique',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SO04',
	'Initiation Au Droit',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SO05',
	'Sociologie, Organisations Et Dynamiques Des Collectifs',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SP01',
	'Un Corps Pour Comprendre Et Apprendre',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'SP02',
	'Conduire Un Projet Sportif',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TN16',
	'Etude Interculturelle',
	0,
	0,
	4,
	0,
	1,
	1);

INSERT INTO UV(code,titre,creditsCS,creditsTM,creditsTSH,creditsSP,printemps,automne) VALUES (
	'TO01',
	'Module De Preparation Au Toeic',
	0,
	0,
	2,
	0,
	1,
	1);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'BL01',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'BL01',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'BL10',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'BL22',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'CM01',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'CM11',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'CM12',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'CM13',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'CM15',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'CM15',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'EL01',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'EL01',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'EN21',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'EN21',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'EN21',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'IA02',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'IA02',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'IA02',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ01',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ01',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ01',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ01',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ01',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ03',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ03',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ03',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ17',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ17',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ17',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ18',
	'formation>
	'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MT10',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MT10',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MT12',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MT12',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MT12',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MT12',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MT22',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MT22',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MT23',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MT90',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MT90',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MT91',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF04',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF04',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF04',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF04',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF04',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF16',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF16',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF16',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'PS04',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'PS91',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'PS91',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'PS92',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'PS93',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'PS93',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'PS94',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'PS94',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'RO03',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'RO03',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'RO03',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'RR01',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'RR01',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SR02',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SR02',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SY01',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SY02',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SY02',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SY02',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SY02',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SY02',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SY02',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SY04',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SY14',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SY14',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TF01',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TF01',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TF01',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TF01',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	't type="CS">6',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	't type="CS">6',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TN06',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'BA07',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'BA07',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'BA07',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'BL09',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'BM01',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'BT02',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'BT02',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'C2I1',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'C2I1',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'CM70',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'CM70',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'DD02',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'DD02',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'EL02',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'EL02',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'FQ01',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'FQ01',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'FQ01',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'FQ01',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'FQ01',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'FQ01',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'GE37',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'GE37',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'GE37',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'GE37',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'GE37',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'LO01',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'LO01',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'LO01',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'LO01',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'LO01',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'LO21',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'LO21',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'LO21',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'LO22',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'LO22',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MT94',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF01',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF01',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF02',
	'formation>
	'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF15',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF15',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF17',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF17',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF17',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF22',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF22',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF22',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF22',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF92',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF92',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NP90',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NX17',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NX17',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NX17',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'PR',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'PR',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'PR',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'PR',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'PR',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'PR',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'PR',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'PS09',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'PS09',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'PS09',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'PS90',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'PS90',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TF14',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TF14',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TN01',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TN01',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TN02',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TN02',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TN02',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TN03',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TN04',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TN04',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TN08',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TN08',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TN20',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TN20',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TN20',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TN22',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TN22',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TN22',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TR91',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	't type="TM">6',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TX',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TX',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TX',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TX',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TX',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TX',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'UB04',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'UB04',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'UR03',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'UR03',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'UR03',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'UR05',
	'TC'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'UR05',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'UR05',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MT34',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MT37',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MT38',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'AP',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'API06',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'API07',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'API08',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'API09',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'API10',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'BA01',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'BA02',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'BA04',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'BA04',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'BA09',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'BI01',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'BM08',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'BT06',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'CM06',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'CM40',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'CT02',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'CT02',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'CT04',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'DI03',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'DI05',
	'HUTECH'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'DI05',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'DI05',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'DI06',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'EG01',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'EN14',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'EV01',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'EV01',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'FPP02',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'FPP02',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'FQ07',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'GE38',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'GE38',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'GE38',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'GE38',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'GE38',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'GE39',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'GE39',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'GE39',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'GE39',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'GE39',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'GPL01',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'GPL01',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'IA04',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'LO17',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'LO18',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MAT03',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MAT03',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MB11',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MB11',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MC01',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MC05',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MC05',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MC07',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MEQ03',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MEQ03',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MI03',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MP02',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MP02',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ02',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ02',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ04',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ06',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ06',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ08',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ09',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ10',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ11',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ14',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ19',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MQ19',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MS02',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MS03',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF11',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF24',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF26',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF28',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF33',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'PS05',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'RO04',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SR03',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SY05',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SY06',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SY06',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SY09',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SY09',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SY12',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SY15',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SY26',
	'GI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TA02',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TF07',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TF08',
	'GP'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TMI01',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TMI01',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TMI05',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TMI05',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TN12',
	'GM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TN12',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TN13',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TN24',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TN29',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'TN30',
	'GSM'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'UB02',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'UB06',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'UB08',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'UR01',
	'GSU'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'RO06',
	'ADEL'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MP02',
	'ADEL'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF26',
	'FDD'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SY09',
	'FDD'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SY19',
	'FDD'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'IA03',
	'ICSI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF29',
	'ICSI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'IA04',
	'ICSI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF28',
	'ICSI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SR03',
	'SRI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SR04',
	'SRI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SR05',
	'SRI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SR06',
	'SRI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SY27',
	'STRIE'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'MI03',
	'STRIE'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'NF33',
	'STRIE'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'SY15',
	'STRIE'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'GE38',
	'MPI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'GE39',
	'MPI'
);

INSERT INTO AssociationFormationUV(uv,formation) VALUES (
	'GE40',
	'MPI'
);

INSERT INTO Dossier(login, nom, prenom, conseiller, validationAEU, branche)
VALUES ('ritgabri', 'Rit', 'Gabrielle', 'François Sebbah', 0, 'GI');

INSERT INTO FormationExt(login, nom, lieu, creditsCS, creditsTM,creditsTSH,creditsSP)
VALUES ('ritgabri', 'UTSEUS', 'Chine', 14, 0, 6, 0);

INSERT INTO FormationExt(login, nom, lieu, creditsCS, creditsTM,creditsTSH,creditsSP)
VALUES ('ritgabri', 'MPSI à Pasteur', 'Neuilly sur Seine', 6, 0, 12, 0);

INSERT INTO Semestre(saison, annee, dossier, commentaire) 
VALUES ('P', 2014, 'ritgabri', 'en cours');

INSERT INTO Inscription(uv, saison, annee, login, resultat) VALUES
('IA02', 'P', 2014, 'ritgabri', 'EC');

INSERT INTO Dossier(login, nom, prenom, conseiller, validationAEU, branche)
VALUES ('tmonceau', 'Monceaux', 'Timothée', 'Gabrielle Orbach-Lin', 1, 'GI');

INSERT INTO FormationExt(login, nom, lieu, creditsCS, creditsTM,creditsTSH,creditsSP)
VALUES ('tmonceau', 'UTSEUS', 'Chine', 6, 11, 10, 0);

INSERT INTO Semestre(saison, annee, dossier, commentaire) 
VALUES ('A', 2013, 'tmonceau', 'poursuite normale');

INSERT INTO Inscription(uv, saison, annee, login, resultat) VALUES
('IA01', 'A', 2013, 'tmonceau', 'B');

INSERT INTO Inscription(uv, saison, annee, login, resultat) VALUES
('NF16', 'A', 2013, 'tmonceau', 'B');

INSERT INTO Inscription(uv, saison, annee, login, resultat) VALUES
('SR01', 'A', 2013, 'tmonceau', 'C');

INSERT INTO Inscription(uv, saison, annee, login, resultat) VALUES
('MI01', 'A', 2013, 'tmonceau', 'C');

INSERT INTO Inscription(uv, saison, annee, login, resultat) VALUES
('FQ01', 'A', 2013, 'tmonceau', 'C');

INSERT INTO Inscription(uv, saison, annee, login, resultat) VALUES
('LB14', 'A', 2013, 'tmonceau', 'C');

INSERT INTO Inscription(uv, saison, annee, login, resultat) VALUES
('PH01', 'A', 2013, 'tmonceau', 'C');

INSERT INTO Semestre(saison, annee, dossier, commentaire) 
VALUES ('P', 2014, 'tmonceau', 'en cours');

INSERT INTO Inscription(uv, saison, annee, login, resultat) VALUES
('IA02', 'P', 2014, 'tmonceau', 'EC');

INSERT INTO Inscription(uv, saison, annee, login, resultat) VALUES
('SR02', 'P', 2014, 'tmonceau', 'EC');

INSERT INTO Inscription(uv, saison, annee, login, resultat) VALUES
('NF17', 'P', 2014, 'tmonceau', 'EC');

INSERT INTO Inscription(uv, saison, annee, login, resultat) VALUES
('LO21', 'P', 2014, 'tmonceau', 'EC');

INSERT INTO Inscription(uv, saison, annee, login, resultat) VALUES
('SI11', 'P', 2014, 'tmonceau', 'EC');

INSERT INTO Inscription(uv, saison, annee, login, resultat) VALUES
('IC07', 'P', 2014, 'tmonceau', 'EC');

CREATE TABLE IF NOT EXISTS AssociationBrancheFiliere (
	filiere VARCHAR(25),
	branche VARCHAR(25),
	PRIMARY KEY (filiere, branche));

INSERT INTO AssociationBrancheFiliere VALUES ('ADEL', 'GI');

INSERT INTO AssociationBrancheFiliere VALUES ('FDD', 'GI');

INSERT INTO AssociationBrancheFiliere VALUES ('ICSI', 'GI');

INSERT INTO AssociationBrancheFiliere VALUES ('SRI', 'GI');

INSERT INTO AssociationBrancheFiliere VALUES ('STRIE', 'GI');

INSERT INTO AssociationBrancheFiliere VALUES ('BM', 'GB');
INSERT INTO AssociationBrancheFiliere VALUES ('BB', 'GB');
INSERT INTO AssociationBrancheFiliere VALUES ('MPI', 'GB');
INSERT INTO AssociationBrancheFiliere VALUES ('CIB', 'GB');
INSERT INTO AssociationBrancheFiliere VALUES ('IAA', 'GB');

INSERT INTO AssociationBrancheFiliere VALUES ('AVI', 'GM');
INSERT INTO AssociationBrancheFiliere VALUES ('IDI', 'GM');
INSERT INTO AssociationBrancheFiliere VALUES ('FQI', 'GM');
INSERT INTO AssociationBrancheFiliere VALUES ('MIT', 'GM');
INSERT INTO AssociationBrancheFiliere VALUES ('MARS', 'GM');
INSERT INTO AssociationBrancheFiliere VALUES ('MPI', 'GM');

INSERT INTO AssociationBrancheFiliere VALUES ('CMI', 'GSM');
INSERT INTO AssociationBrancheFiliere VALUES ('MOPS', 'GSM');
INSERT INTO AssociationBrancheFiliere VALUES ('PIL', 'GSM');
INSERT INTO AssociationBrancheFiliere VALUES ('MPI', 'GSM');

INSERT INTO AssociationBrancheFiliere VALUES ('SR', 'GSU');
INSERT INTO AssociationBrancheFiliere VALUES ('MPI', 'GSU');
INSERT INTO AssociationBrancheFiliere VALUES ('AIE', 'GSU');
INSERT INTO AssociationBrancheFiliere VALUES ('STI', 'GSU');

INSERT INTO AssociationBrancheFiliere VALUES ('MPI', 'GP');
INSERT INTO AssociationBrancheFiliere VALUES ('AIC', 'GP');
INSERT INTO AssociationBrancheFiliere VALUES ('CPI', 'GP');
INSERT INTO AssociationBrancheFiliere VALUES ('QSE', 'GP');
INSERT INTO AssociationBrancheFiliere VALUES ('TE', 'GP');