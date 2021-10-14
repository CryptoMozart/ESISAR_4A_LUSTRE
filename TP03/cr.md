---
title: "Compte-rendu TP3 Lustre"
author: "DOUGY Hugo & LEVERN Albéric"
titlepage: true
titlepage-rule-color: FFFFFF
titlepage-text-color: FFFFFF
titlepage-background: "/usr/share/pandoc/data/templates/pandoc-latex-template/background.pdf"
...

# Step 1:

## A simple compilation and simulation

On a exécuté la commande ` lus2c edge.lus edge -loop` afin d'executer le programme edge.lus avec luciole
On obtient le résultat suivant:

![Résultat du programme edge.lus avec luciole ](0.1.png)

![Chronogramme du programme edge.lus](0.2.png)

On compile le programme avec la commande `gcc -o edge edge*.c`

On teste le programme executable edge. 
On obtient le résultat suivant:

![Résultat de l'executable edge](0.3.png)

On test avec le programme `demo7seg.lus`

On recommence les opérations de compilation et avec luciole.
On obtient le résultat suivant:

![Résultat du programme demo7seg.lus avec luciole ](0.4.png)

On test également l'executable:

![Résultat de l'executable demo7seg](0.5.png)

Pour compter, on met le signal reset à 0.

# Step 2:

## Exercice 1: Air-conditioner controller

Nous avons choisit de concevoir uniquement une climatisation car le sujet de spécifie pas la conception d'un chauffge.

Notre systeme ne fonctionne que lorsque l'on décide d'activer l'interrupteur onOff. L'air conditionnée est donc activé que lorsque `isOn = true`.

Si jamais le systeme ne fonctionne pas (`isOn = false`) alors il sauvegarde la valeur de consigne donner par l'utilisateur pour pouvoir se ractiver quand `isOn = true`.

La climatisation ne se déclanche que lorsque la température ambiant est supérieur à la température de commande. dans la situation inverse l'air conditionné soufflera un air à la température ambiante.

Nous avons fait le choix d'activé la climatisation avec un hystérésis de 1°.

On à le résultat suivant en simulant le programme avec luciole:

![Résultat du programme aircontroller.lus avec luciole](1luciole.png)



On peut voir avec le chronogramme que l'on tend bien vers notre valeur tUseren fonction de la température tAmb. De plus on sauvegarde la valeur de tAmb lorsque `onOFF = false`. 

On a également les 2 cas suivants où la `tAmb > tUser` et `tAmb < tUser`

![tAmb < tUser](1.1.png)

![tAmb > tUser](1.2.png)

## Exercice 2: Roller shutter controller

Pour cet exercice, nous avons choisi d'implémenter un second noeud: `hour` afin de savoir si l'heure est comprise entre 22h et 6h. Si oui, le noeud renvoie `true`. Le but est d'alleger le code et de le rendre plus lisible. 

Pour l'implémentation du noeud principal, on procède par priorité. C'est à dire qu'on regarde premièrement les etats des volets. Si ils ne sont pas dans le bon état on ne change pas leur état.

On regarde ensuite l'heure puis la luminosité. 

En simulant notre programme avec luciole, on obtient le résultat suivant: 

![Chronogramme du programme shutter_controller.lus](2luciole.png)

On voit bien que toutes les conditions sont respectés et que l'heure est prioritaire par rapport à la luminostié pour la fermeture. 

De plus, les sorties `open` et `close` ne sont jamais vraies en même temps. Et si `isOpen` et `isClosed` sont vraies en même temps, les volets s'étteigent. 

***Dans la simulation, il faut faire attention à bien changer l'état manuellement de `isOpen` et `isClosed`***

## Exercice 3: Stopwatch

Pour cet exercice, on créé un nouveau noeud `swtich` afin de savoir quand à lieux un changement sur la variable `start`. 

Si `start` repasse à `true` alors on remet le chronomètre à 0 et on attend un cycle d'horloge pour recommencer à recompter. 

En simulation, on obtient le chronogramme suivant:

![Chronogramme du programme stopwatch.lus](3chrono.png)

Quand `freeze` est à `true`, on a bien la sauvegarde du compteur.
Quand `stop` est à `true`, on arrête de compter et quand `reset` est à `true` quand `stop` est à `true` on réinitialise le compteur. 

De plus, si `reset` est à `true` sans `stop` cela n'affecte pas comptage.

![Chronogramme du programme stopwatch.lus avec reset sans stop](3.1chrono.png)


