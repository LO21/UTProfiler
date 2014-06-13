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


CREATE TABLE IF NOT EXISTS AssociationFormationUV (
	uv VARCHAR(10) REFERENCES UV(code),
	formation VARCHAR(25) REFERENCES Formation(nom),
	PRIMARY KEY (uv,formation));