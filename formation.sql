DROP TABLE UV;

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