DROP TABLE TypeFormation;

CREATE TABLE IF NOT EXISTS TypeFormation (
	type VARCHAR(25) PRIMARY KEY);

INSERT INTO TypeFormation VALUES ('Branche');

INSERT INTO TypeFormation VALUES ('Filière');

INSERT INTO TypeFormation VALUES ('Mineur');