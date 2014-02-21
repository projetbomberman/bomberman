Korba Anna
Dehar Madjer
2A ENSAE 2013/2014

Projet C++ Débutants
====================

Sujet : Bomberman
=================

Touches directionnelles pour se déplacer.
Espace pour poser une Bombe.
Les fichiers spritesbomberman.png et Player.png doivent se trouver dans le même dossier que l'executable.

Nous avons choisi de réaliser notre projet avec la librairie externe SFML 1.6 car elle est adaptée à la création d'applications 2D en C++.
Nous avons eu un peu de mal à installer cette librairie pour pouvoir l'utiliser avec Visual Studio 2010 ce qui nous a pris beaucoup de temps, M.Patra nous a débloqué lors du premier suivi.
	
Nous avons commencé par l'affichage d'une fenêtre dans laquelle nous avons dessiné notre TileMap. Les méthodes de construction de la carte se trouvent dans Carte.h et Carte.cpp.

Pour ce faire, nous avons employé 2 méthodes : 
Nous avons créé 3 sprites à partir d'une image (spritesbomberman.png).

Nous avons d'abord créé un fichier texte contenant des 0 des 1 et des 2 formant un carré de dimension 10 caractères x 10 caractères. MapFile est un tableau d'entiers. Puis une méthode DrawMap qui va lire le fichier texte pour remplir MapFile et qui a chaque chiffre associe un sprite qu'il va dessiner dans la fenêtre à sa place. L'emplacement MapFile[i][j] correspond à l'eplacement i x taille de l'image, j x taille de l'image.
Une autre méthode (celle que nous avons finalement choisi) est de créer directement un tableau de sprites et de dessiner chaque sprite à son emplacement. Celle-ci convient mieux car elle permet d'avoir des sprites localisés ce qui nous sert pour les collisions.

Nous avons ensuite créé la classe Player pour le personnage et une classe Animation qui sert à créer ses mouvements.

La classe Animation permet de définir les fonctions nécessaires à l’initialisation et au déplacement du joueur. On peut ainsi manipuler les coordonnées, la position (les différents Frames, ie joueur tourné vers la droite, la gauche, marchant etc…), et le mouvement. Pour ce dernier, dans la fonction Update, nous avons d’ailleurs utilisé la durée de rafraîchissement (Window.GetFrameTime()) de l’écran car le mouvement du personnage en dépend.

Nous avons donné au player une animation associée à la feuille de sprites Player.png contenant les différentes vues du personnage. Dans la classe Player nous avons créé les méthodes permettant le déplacement du joueur lorsque l'on appuie sur les touches directionnelles et intégré les collisions : nous avons créé des booleens CollHaut, CollBas... disant s'il y a collision avec une brique rouge ou non et nous avons intégré ceci aux méthodes de déplacement. 
Cette classe contient également des méthodes permettant l'accès à ses atributs privés et une méthode lui permettant de prendre des dégâts, de poser une bombe... (la plupart étant annotées dans le code)


La classe Bombe est assez simple excepté pour la méthode exploser. Nous avons passé beaucoup de temps sur l'explosion de la bombe et nous avons eu un peu de mal avec les timers. Nous avons construit cette méthode de la façon suivante :
On créer un sprite de bombe et on le place à l'endroit où l'on veut que la bombe soir posée dans le tableau TableauSprites (qui contient tous les sprites dessinés sur la carte).
On le dessine sur la carte avec DrawMap.
On crée un timer (classe Clock de SFML 1.6) que l'on incrémente d'une période d'actualisation de l'écran tant que la valeur tu timer est inférieure à un certain seuil.
Lorsque le timer dépasse ce seuil, on crée des sprites de briques cassées sur les 4 cases autour de la bombe dans TableauSprites et on les dessine avec DrawMap.
On créer aussitôt un autre timer et lorsque celui-ci dépasse une certaine valeur on crée des nouveaux sprites d'herbe qui remplacent les sprites de bombe et brique cassée dans TableauSprites et on les dessine avec DrawMap.

Cependant, tout s'affiche en même temps quelles que soient les valeurs que l'on donne aux seuils. L'écart temporel entre l'affichage des sprites de bombe, de briques cassées et d'herbe semble n'être que d'une période d'actualisation de l'écran au lieu d'être celui défini par les seuils.

Nous n’avons ainsi pas eu le temps de gérer la mort du personnage, ie à savoir s’il est touché par les cases voisines de l’endroit où il a posé la bombe, à cause de ce même problème de timer.
