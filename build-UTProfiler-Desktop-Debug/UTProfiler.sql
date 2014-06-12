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
