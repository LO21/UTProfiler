CREATE TABLE UV (
	code VARCHAR PRIMARY KEY,
	titre VARCHAR,
	responsable VARCHAR,
	nbCredits INTEGER,
categorie VARCHAR TYPEENUM,
	printemps BOOLEAN,
	automne BOOLEAN);

CREATE TABLE Formation (
);

CREATE TABLE Dossier (
	login CHAR(8) PRIMARY KEY,
	nom VARCHAR,
	prenom VARCHAR,
	conseiller VARCHAR,
	validationAEU BOOLEAN
semestre ?);

CREATE TABLE Semestre (
);

CREATE
