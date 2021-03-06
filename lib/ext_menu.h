! Cette extension PunyInform vous permet d'afficher des menus qui, côté
! programmation, fonctionnent de la même facon sur toutes les versions
! Z-Machine. La présentation dans les jeux z5 et plus ressemble à l'extension
! DoMenu décrite dans le DM3 et qui fait à présent partie de la bibliothèque
! standard Inform 6. Pour les jeux z3, la présentation est plus simple, mais
! toute aussi fonctionnelle.
!
! Cette extension dévie de l'implantation standard de DoMenu sur un
! point: quand vous assignez une valeur à la variable item_width, cette valeur
! doit être la longueur totale de l'item ; par exemple si l'item est "Aide",
! item_width doit être mis à 4, alors que dans la bibliothèque standard cette
! valeur doit être la moitié de la largeur (donc 2, dans ce cas).

! Si vous écrivez un jeu qui devrait être compilable à la fois avec PunyInform
! et avec la bibliothèque standard, il est peut-être plus pratique de faire en
! sorte que ext_menu utilise la même convention pour item_width que le DoMenu
! de la bibliothèque standard. Pour avoir ce même comportement, définissez la
! constante EXT_MENU_STDLIB_MODE avant d'inclure cette extension.

System_file;

Global menu_item;
Global item_width;
Global item_name;
Global menu_nesting;

#IfV3;
[ DoMenu menu_choices EntryR ChoiceR lines main_title i j;
	menu_choices = 0; ! Avoid warning
	menu_nesting++;
.LKRD;
	menu_item = 0;
	lines = indirect(EntryR);
	main_title = item_name;

	print "--- "; print (string) main_title; print " ---^^";

	!if (menu_choices ofclass Routine) menu_choices.call();
	!else                              print (string) menu_choices;

	print "Des informations sont disponibles sur :^^";
	for(i = 1: i <= lines: i++) {
		menu_item = i;
		indirect(EntryR);
		print i, ": ", (string) item_name, "^";
	}
	if(menu_nesting == 1) {
		print "q: Retour au jeu^";
	} else {
		print "q: Menu précédent^";
	}

	for (::) {
		print "^Faites un choix entre 1 et ", lines, ", ou ENTREE pour réafficher les options.^";
		print "> ";

       _ReadPlayerInput(true);
		j = parse->1; ! number of words
		if (j == 0) jump LKRD;
		i = parse-->1;
		if(i == 'q//') {
			menu_nesting--; if (menu_nesting > 0) rfalse;
			if (deadflag == 0) <<Look>>;
			rfalse;
		}
		i = TryNumber(1);
		if (i < 1 || i > lines) continue;
		menu_item = i;
		j = indirect(EntryR);
		print "^--- "; print (string) item_name; print " ---^^";
		j = indirect(ChoiceR);
		if (j == 2) jump LKRD;
		if (j == 3) rfalse;
	}
];
#IfNot;

Constant NKEY__TX       = "N = next/suivant";
Constant PKEY__TX       = "P = précédent";
Constant QKEY1__TX      = "  Q = retour au jeu";
Constant QKEY2__TX      = "Q = menu précédent";
Constant RKEY__TX       = "ENTREE = lire sujet";

Constant NKEY1__KY      = 'N';
Constant NKEY2__KY      = 'n';
Constant PKEY1__KY      = 'P';
Constant PKEY2__KY      = 'p';
Constant QKEY1__KY      = 'Q';
Constant QKEY2__KY      = 'q';

[ FastSpaces p_spaces;
	while(p_spaces > 10) {
		@print_table TenSpaces 10 1;
		p_spaces = p_spaces - 10;
	}
	@print_table TenSpaces p_spaces 1;
];

[ DoMenu menu_choices EntryR ChoiceR
         lines main_title main_wid cl i j oldcl pkey ch y x;
	menu_nesting++;
	menu_item = 0;
	lines = indirect(EntryR);
	main_title = item_name; main_wid = item_width;
	cl = 7;

.ReDisplay;

	oldcl = 0;
	@erase_window $ffff;
	ch = 1;
	i = ch * (lines+7);
	@split_window i;
	i = HDR_SCREENWCHARS->0;
	if (i == 0) i = 80;
	@set_window 1;
	@set_cursor 1 1;

	style reverse;
	FastSpaces(i); j=1+(i-main_wid)/2;
	@set_cursor 1 j;
	print (string) main_title;
	y=1+ch; @set_cursor y 1; FastSpaces(i);
	x=1+1; @set_cursor y x; print (string) NKEY__TX;
	j=1+i-13; @set_cursor y j; print (string) PKEY__TX;
	y=y+ch; @set_cursor y 1; FastSpaces(i);
	@set_cursor y x; print (string) RKEY__TX;
	j=1+i-18; @set_cursor y j;

	if (menu_nesting == 1) print (string) QKEY1__TX;
	else                   print (string) QKEY2__TX;
	style roman;
	y = y+2*ch;
	@set_cursor y x; font off;

	if (menu_choices ofclass String) print (string) menu_choices;
	else                             menu_choices.call();

	x = 1+3;


	for (::) {
		if (cl ~= oldcl) {
			if (oldcl>0) {
				y=1+(oldcl-1)*ch; @set_cursor y x; print " ";
			}
			y=1+(cl-1)*ch; @set_cursor y x; print ">";
		}

		oldcl = cl;
		@read_char 1 -> pkey;
		if (pkey == NKEY1__KY or NKEY2__KY or 130) {
			cl++; if (cl == 7+lines) cl = 7; continue;
		}
		if (pkey == PKEY1__KY or PKEY2__KY or 129) {
			cl--; if (cl == 6) cl = 6+lines; continue;
		}
		if (pkey == QKEY1__KY or QKEY2__KY or 27 or 131) break;
		if (pkey == 10 or 13 or 132) {
			@set_window 0; font on;
			new_line; new_line; new_line;

			menu_item = cl-6;
			EntryR.call();

			@erase_window $ffff;
			@split_window ch;
			i = HDR_SCREENWCHARS->0; if ( i== 0) i = 80;
			@set_window 1; @set_cursor 1 1; style reverse; FastSpaces(i);
			j=1+(i-item_width)/2;
			@set_cursor 1 j;
			print (string) item_name;
			style roman; @set_window 0; new_line;

			i = ChoiceR.call();
			if (i == 2) jump ReDisplay;
			if (i == 3) break;

			print "^[Appuyez sur ESPACE.]";
			@read_char 1 -> pkey; jump ReDisplay;
		}
	}
	menu_nesting--; if (menu_nesting > 0) rfalse;
	font on; @set_cursor 1 1;
	@erase_window -1; @set_window 0;
#IfDef PUNYINFORM_MAJOR_VERSION;
	statusline_current_height = 0;
#IfNot;
	gg_statuswin_cursize = 0;
#EndIf;
	new_line; new_line; new_line;
	if (deadflag == 0) <<Look>>;
];

#EndIf;
