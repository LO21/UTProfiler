CREATE TABLE IF NOT EXISTS UV (
	code VARCHAR(5) PRIMARY KEY,
	titre VARCHAR(100) NOT NULL,
	responsable VARCHAR(30),
	creditsCS INTEGER(2),
	creditsTM INTEGER(2),
	creditsTSH INTEGER(2),
	creditsSP INTEGER(2),
	printemps BOOL,
	automne BOOL);

CREATE TABLE IF NOT EXISTS Branche (
	b VARCHAR(10));

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
	nom VARCHAR(25) NOT NULL,
	prenom VARCHAR(25) NOT NULL,
	conseiller VARCHAR(25) NOT NULL,
	validationAEU BOOL,
	branche VARCHAR(10));

CREATE TABLE IF NOT EXISTS Saison (
	s CHAR(1));

INSERT INTO Saison VALUES ('A');

INSERT INTO Saison VALUES ('P');

CREATE TABLE IF NOT EXISTS Semestre (
	id INTEGER(10) PRIMARY KEY,
	saison CHAR(1) REFERENCES Saison(s),
	annee INTEGER(4),
	dossier CHAR(8) REFERENCES Dossier(login),
	commentaire VARCHAR(100),
	ext BOOL);
	
CREATE TABLE Resultat (
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
	semestre INTEGER(10) REFERENCES Semestre(id),
	resultat VARCHAR(3) REFERENCES Resultat(r),
	PRIMARY KEY (uv, semestre) );

CREATE TABLE IF NOT EXISTS FormationExt (
	login CHAR(8) REFERENCES Dossier(login),
	nom VARCHAR(50),
	semestre INTEGER(10) REFERENCES Semestre(id),
	lieu VARCHAR(50) NOT NULL,
	creditsCS INTEGER(2),
	creditsTM INTEGER(2),
	creditsTSH INTEGER(2),
	creditsSP INTEGER(2),
	PRIMARY KEY (semestre, login) );
