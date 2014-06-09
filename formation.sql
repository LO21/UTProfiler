CREATE TABLE IF NOT EXISTS FormationExt (
	login CHAR(8) REFERENCES Dossier(login),
	nom VARCHAR(50),
	lieu VARCHAR(50) NOT NULL,
	creditsCS INTEGER(2),
	creditsTM INTEGER(2),
	creditsTSH INTEGER(2),
	creditsSP INTEGER(2),
	PRIMARY KEY (nom, login) );
	
	CREATE TABLE IF NOT EXISTS Dossier (
	login CHAR(8) PRIMARY KEY,
	nom VARCHAR(25) NOT NULL,
	prenom VARCHAR(25) NOT NULL,
	conseiller VARCHAR(25) NOT NULL,
	validationAEU BOOL,
	branche VARCHAR(10));
	
INSERT INTO FormationExt(login, nom, lieu, creditsCS, creditsTM,creditsTSH,creditsSP)
VALUES ('ritgabri', 'UTSEUS', 'Chine', 14, 0, 6, 0);

INSERT INTO FormationExt(login, nom, lieu, creditsCS, creditsTM,creditsTSH,creditsSP)
VALUES ('ritgabri', 'MPSI � Pasteur', 'Neuilly sur Seine', 6, 0, 12, 0);