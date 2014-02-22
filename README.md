Korba Anna
Dehar Madjer
2A ENSAE 2013/2014

Projet C++ Débutants
====================

Sujet : Bomberman
-----------------

Lien GitHub contenant les fichiers source : https://github.com/projetbomberman/bomberman
Touches directionnelles pour se déplacer.
Espace pour poser une Bombe.


Contenu du dossier rendu de projet :
------------------------------------

- Mon jeu : dossier contenant le vcxproj, le sln, tous les fichiers source
Sfml 1.6 : librairie externe utilisée ( http://sfml-dev.org/tutorials/1.6/start-vc.php )
Nous avons installé sfml en STATIC donc pas besoin des dll dans le même dossier.
- Un screenshot du jeu
- executable : contient le .exe qui fonctionne quel que soit le pc
Les fichiers spritesbomberman.png et Player.png doivent se trouver dans le même dossier que l'executable (qui se trouve dans le dossier executable).
- note d'explication du projet ci-présente

Notre projet est réalisé avec la librairie externe SFML 1.6 car elle est adaptée à la création
d'applications 2D en C++.
Nous avons eu un peu de mal à installer cette librairie pour pouvoir l'utiliser avec Visual
Studio 2010 , ce qui nous a fait perdre beaucoup de temps, mais M.Patra nous a débloqué lors du
premier suivi.

Nous avons commencé par l'affichage d'une fenêtre dans laquelle nous avons dessiné notre
TileMap. Les méthodes de construction de la carte se trouvent dans Carte.h et Carte.cpp.

Pour ce faire, nous avons essayé 2 méthodes :

Nous avons d'abord créé un fichier texte contenant des 0 des 1 et des 2 (correspondant à 3 Sprites différents, Herbe, Brique rouge et grise), formant un carré de dimension 10 caractères x 10 caractères, Puis une méthode DrawMap qui va lire le fichier texte pour remplir MapFile (tableau d’entiers) et qui a chaque chiffre associe un sprite qu'il va dessiner dans la fenêtre à sa place. L'emplacement MapFile[i][j] correspond à l'emplacement i x taille de l'image, j x taille de l'image (en pixels).

Une autre méthode (celle que nous avons finalement choisi) est de créer directement un tableau de sprites et de dessiner chaque sprite à son emplacement. Celle-ci convient mieux car elle permet d'avoir des sprites localisés ce qui nous sert pour les collisions.

Nous avons ensuite créé la classe Player pour le personnage et une classe Animation qui sert à gérer ses mouvements.

La classe Animation permet de définir les fonctions nécessaires à l’initialisation et au déplacement du joueur. On peut ainsi manipuler les coordonnées, la position (les différents Frames, ie joueur tourné vers la droite, la gauche, marchant etc…), et le mouvement. Pour ce dernier, dans la fonction Update, nous avons d’ailleurs utilisé la durée de rafraîchissement (Window.GetFrameTime()) de l’écran car le mouvement du personnage en dépend.

Nous avons donné au player une animation associée à la feuille de sprites Player.png contenant les différentes vues du personnage. Il a fallu adapter les dimensions des sprites de décor et de joueur pour qu'elles soient cohérentes. Dans la classe Player nous avons créé les méthodes permettant le déplacement du joueur lorsque l'on appuie sur les touches directionnelles et intégré les collisions : nous avons créé des booleens CollHaut, CollBas...  renvoyant faux s'il y a collision avec une brique rouge/grise et nous avons intégré ceci aux méthodes de déplacement.
Cette classe contient également des méthodes permettant l'accès à ses atributs privés et une méthode lui permettant de prendre des dégâts, de poser une bombe... (la plupart étant annotées dans le code)


La classe Bombe est assez simple, excepté pour la méthode exploser. Nous avons passé beaucoup de temps sur l'explosion de la bombe et nous avons eu un peu de mal avec les timers. Nous avons construit cette méthode de la façon suivante :

On crée un sprite de bombe et on le place à l'endroit où l'on veut que la bombe soit posée dans TableauSprites (qui contient tous les sprites dessinés sur la carte), c’est à dire „devant“ le joueur lorsque l’on appuie sur Entrée, et on la dessine sur la carte avec DrawMap.

On crée un timer (classe Clock de SFML 1.6) que l'on incrémente d'une période d'actualisation de l'écran tant que la valeur du timer est inférieure à un certain seuil.
.
Lorsque le timer dépasse ce seuil, on crée des sprites de briques cassées sur les 4 cases autour de la bombe dans TableauSprites et on les dessine avec DrawMap.

On crée aussitôt un autre timer et lorsque celui-ci dépasse une certaine valeur on crée des nouveaux sprites d'herbe qui remplacent les sprites de bombe et brique cassée dans TableauSprites et on les dessine avec DrawMap.

Cependant, tout s'affiche en même temps quelles que soient les valeurs que l'on donne aux seuils. L'écart temporel entre l'affichage des sprites de bombe, de briques cassées et d'herbe semble n'être que d'une période d'actualisation de l'écran au lieu d'être celui défini par les seuils. Nous avons codé une méthode „Getdegats“ pour le personnage qui lui aurait permis de prendre des dégâts lors de l'explosion mais nous avions besoin de exploser pour l'achever.


En conclusion, nous avons appris beaucoup, notamment l'importance de l'utilisation du débugueur, la recherche d'erreur sur les forums, la lecture de la documentation d'une librairie externe (et son installation ! ), l'affichage de fenêtres à l'écran(applications 2D), l'utilisation de classes, la gestion des événements et du temps. Nous avons également appris à collaborer sur un projet informatique via GitHub nous ayant permis d'avoir accès au travail l'un de l'autre en temps réel.
