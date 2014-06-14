CREATE TABLE IF NOT EXISTS AssociationBrancheFiliere (
	filiere VARCHAR(25),
	branche VARCHAR(25),
	PRIMARY KEY (filiere, branche));

INSERT INTO AssociationBrancheFiliere VALUES ('ADEL', 'GI');
INSERT INTO AssociationBrancheFiliere VALUES ('FDD', 'GI');
INSERT INTO AssociationBrancheFiliere VALUES ('ICSI', 'GI');
INSERT INTO AssociationBrancheFiliere VALUES ('SRI', 'GI');
INSERT INTO AssociationBrancheFiliere VALUES ('STRIE', 'GI');