! ext_flags.h, une extension de Fredrik Ramsberg pour la bibliothèque
! PunyInform, adaptée de flags.h par Adam Cadre.

! Ceci est un système simple pour faire des flags (on/off, actif/inactif,
! levé/baissé) qui ne prennent qu'un bit de mémoire; comme ça, on ne gaspille
! pas de mémoire (et de variables globales) avec des déclaration de variables
! comme "flagfini" ou autre, qui prendraient 16 bits alors que la variable ne
! prendra jamais d'autres valeurs que 0 ou 1.

! Voici comment l'utiliser dans vos programmes. Après avoir inclus globals.h,
! déclarez la constante FLAG_COUNT avec pour valeur le nombre de flags dont
! vous avez besoin, puis incluez cette extension.
!
! Quand vous avez besoin d'un nouveau flag, créez une constante avec un nom
! explicite. Et pourquoi pas aussi ajouter un commentaire, ou garder une liste
! quelque part récapitulant ce que chaque flag veut dire.

! Constant F_PERROQUET_FAIM 0; ! Est-ce que le perroquet a besoin de manger ?
! Constant F_BILLETS_OK 1;  ! Est-ce que Hildegarde a réservé ses billets
!                           ! d'avion avec la bonne carte bancaire?
! Constant F_SAUVE_CHAT 2;   ! Le joueur a-t-il sauvé le chat coincé dans
!                            ! l'arbre?

! Et ainsi de suite. Notez que le premier flag est le numéro 0.

! Lever ou baisser un flag se fait en appelant la routine SetFlag(NuméroDuFlag)
! ou ClearFlag(NuméroDuFlag). Pour indiquer que le joueur a sauvé le chat,
! écrivez "SetFlag(F_SAUVE_CHAT);", et pour baisser le flag, écrivez
! "ClearFlag(F_SAUVE_CHAT);"  (Sans les guillemets, bien sûr.)

! On teste un flag en appelant FlagIsSet ou FlagIsClear. Donc si vous avez
! un bout de code qui ne doit s'exécuter que si le perroquet a faim, vous le
! mettriez dans un bloc condtionnel "if (FlagIsSet(F_FED_PARROT)) { ... }".
! Naturally, you can test if a flag is clear by calling FlagIsClear instead.



System_file;

Array flag_powers static ->
	$$00000001
	$$00000010
	$$00000100
	$$00001000
	$$00010000
	$$00100000
	$$01000000
	$$10000000;

Array game_flags -> FLAG_COUNT / 8 + (FLAG_COUNT & 7 > 0);

[ SetFlag p_x _y;
#IfV5;
	@log_shift p_x (-3) -> _y;
#IfNot;
	_y = p_x / 8;
#EndIf;
	game_flags -> _y = game_flags -> _y | flag_powers -> (p_x & 7);
];

[ ClearFlag p_x _y;
#IfV5;
	@log_shift p_x (-3) -> _y;
#IfNot;
	_y = p_x / 8;
#EndIf;
	game_flags -> _y = game_flags -> _y & ~ flag_powers -> (p_x & 7);
];

[ FlagIsSet p_x _y;
#IfV5;
	@log_shift p_x (-3) -> _y;
#IfNot;
	_y = p_x / 8;
#EndIf;
	return (game_flags -> _y & flag_powers -> (p_x & 7) > 0);
];

[ FlagIsClear p_x _y;
#IfV5;
	@log_shift p_x (-3) -> _y;
#IfNot;
	_y = p_x / 8;
#EndIf;
	return (game_flags -> _y & flag_powers -> (p_x & 7) == 0);
];
