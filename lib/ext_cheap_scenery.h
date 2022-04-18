! ext_cheap_scenery.h, une extension pour PunyInform par Fredrik Ramsberg
!
! Cette extension permet d'implanter des objets de décor (scenery) simples,
! que l'on peut juste examiner, le tout en n'utilisant qu'un seul objet pour
! tout le jeu. Ceci permet de minimiser le nombre d'objets et l'utilisation
! de la mémoire dynamique.
!
! Pour l'utiliser, incluez ce fichier après globals.h. Puis, ajoutez une
! propriété nommée cheap_scenery aux lieux où vous voulez ajouter des objets
! de décor gratuits. Vous pouvez ainsi ajouter jusqu'à 10 objets de décor
! gratuits par lieux. Pour chaque objet de décor, spécifiez, dans cet ordre,
! un adjectif, un nom, et une chaîne de caractères de description ou une
! routine en affichant une. Vous pouvez ajoutez un synonyme du nom au lieu
! d'un adjectif. Si vous n'avez besoin ni de l'un ni de l'autre, écrivez
! "1" en première position.
!
! Note : si vous voulez utiliser cette extension pour un jeu Z-Code version 3,
! il ne FAUT PAS déclarer cheap_scenery comme une propriété globale
! (common property), sinon, elle ne pourra pas contenir 10 objets de décor,
! mais un seul.
!
! Si vous voulez utiliser la même description pour un objet de décor dans
! plusieurs lieux, déclarez une constante correspondant à cette chaîne de
! caractère, et faites référence à cette constante dans chacun des lieux.
!
! Avant d'inclure cette extension, vous pouvez aussi définir une routine ou
! une chaîne de caractères nommée SceneryReply. Si vous le faites, elle sera
! utilisée à chaque fois que le joueur fait une action impliquant l'objet
! autre que l'examiner. Si c'est une chaîne de caractères, elle sera affichée.
! Si c'est une routine, elle sera appelée. Si la routine affiche quelque
! chose, elle devrait renvoyer true, et false dans le cas contraire. La
! routine est appelée avec deux paramètres - l'adjectif/synonyme et le nom
! listé dans la propriété cheap_scenery qui correspond à l'input.

!
! Exemple d'utilisation :

! [SceneryReply word1 word2 ;
!   Push:
!     if(location == RiverBank && word2 == 'eau')
!         "Si vous voulez nagez, dites juste ~nager~."
!     "Comment donc pourrais-je faire cela ?";
!   default:
!     rfalse;
! ];
!
! Include "ext_cheap_scenery.h";
!
! Constant SCN_WATER = "L'eau est si belle en cette saison, toute claire et
! scintillante.";
! [SCN_SUN;
!   deadflag = 1;
!   "Vous fixez le soleil des yeux, et vous sentez que vos yeux brûlent.
!     Au bout d'un moment, tout devient noir. Sans la vue, vous avez peu de
!     chances d'aller au bout de votre enquête.";
! ];
!
! Object RiverBank "Bord de la rivière"
!   with
!	 description "La rivière est plutôt large ici. Le soleil se reflète
!        dans l'eau bleue, les oiseaux volent haut dans le ciel.",
!	 cheap_scenery
!      'bleue' 'eau' SCN_WATER
!      'oiseau' 'oiseaux' "Ils ont l'air si insouciants."
!      1 'soleil' SCN_SUN,
!   has light;


System_file;

#IfnDef RUNTIME_ERRORS;
Constant RUNTIME_ERRORS = 2;
#EndIf;
#IfnDef RTE_MINIMUM;
Constant RTE_MINIMUM = 0;
Constant RTE_NORMAL = 1;
Constant RTE_VERBOSE = 2;
#EndIf;

Object CheapScenery "objet"
	with
		number 0,
		parse_name [ _w1 _w2 _i _sw1 _sw2 _len;
			_w1 = NextWordStopped();
			_w2 = NextWordStopped();
			_i = 0;
			_len = location.#cheap_scenery / 2;
#IfTrue RUNTIME_ERRORS > RTE_MINIMUM;
#IfTrue RUNTIME_ERRORS == RTE_VERBOSE;
			if(_len % 3 > 0)
				"ERROR: cheap_scenery property of current location has
					incorrect # of values!^";
#IfNot;
			if(_len % 3 > 0)
				"ERROR: cheap_scenery #1!^";
#EndIf;
			while(_i < _len) {
				_sw1 = location.&cheap_scenery-->(_i+2);
#IfTrue RUNTIME_ERRORS == RTE_VERBOSE;
				if(~~(_sw1 ofclass String or Routine))
					"ERROR: Element ", _i+2, " in cheap_scenery property of
						current location is not a string or routine!^",
						"Element: ", (name) _sw1, "^";
#IfNot;
				if(~~(_sw1 ofclass String or Routine))
					"ERROR: cheap_scenery #2!^";
#EndIf;

				_i = _i + 3;
			}
			_i = 0;
#endif;
			while(_i < _len) {
				_sw1 = location.&cheap_scenery-->_i;
				_sw2 = location.&cheap_scenery-->(_i+1);
				if(_w1 == _sw1 && _w2 == _sw2) {
					self.number = _i;
					return 2;
				}
				if(_w1 == _sw1 or _sw2) {
					self.number = _i;
					return 1;
				}
				_i = _i + 3;
			}
			! It would make sense to return 0 here, but property
			! routines return 0 by default anyway.
		],
		description [ _k;
			_k = location.&cheap_scenery-->(self.number + 2);
			if(_k ofclass Routine) {
				_k();
				rtrue;
			}
			print_ret (string) _k;
		],
#Ifdef SceneryReply;
		before [i w1;
#Ifnot;
		before [;
#Endif;
			Examine:
				rfalse;
			default:
				#ifdef SceneryReply;
				if(SceneryReply ofclass string)
					print_ret (string) SceneryReply;
				i = location.&cheap_scenery;
				w1 = self.number;
				if(SceneryReply(i-->w1, i-->(w1 + 1)))
					rtrue;
				#endif;
				"Pas besoin de vous préoccuper de cela.";
		],
		found_in [;
			if(location provides cheap_scenery) rtrue;
		],
	has concealed scenery
#Ifdef OPTIONAL_REACTIVE_PARSE_NAME;
		reactive
#Endif;
;
