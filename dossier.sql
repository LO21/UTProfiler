INSERT INTO Dossier(login, nom, prenom, conseiller, validationAEU, branche)
VALUES ('gveleine', 'Véleine', 'Geoffrey', 'Jacques Pateau', 0, 'GM');

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

