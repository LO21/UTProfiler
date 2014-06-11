DROP TABLE Inscription;

CREATE TABLE IF NOT EXISTS Inscription (
	uv VARCHAR(5) REFERENCES UV(code),
	saison CHAR(1) REFERENCES Semestre(saison),
    annee INTEGER(4) REFERENCES Semestre(annee),
    login CHAR(8) REFERENCES Semestre(dossier),
	resultat VARCHAR(3) REFERENCES Resultat(r),
	PRIMARY KEY (uv, saison, annee, login));

INSERT INTO Inscription(uv, saison, annee, login, resultat) VALUES
('IA02', 'P', 2014, 'ritgabri', 'EC');