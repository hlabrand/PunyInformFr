! ######################### Grammar + Actions

! ---------------------
! Base verbs
! ---------------------

Verb 'repondre' 'dire'
    * topic 'a//' creature                          -> Answer
    * 'a' creature 'de' topic                       -> AskTo;

Verb 'parler'
    * 'a'/'au'/'aux'/'avec' creature 'de' topic     -> Tell;

Verb 'demander' 'questionner'
	* creature 'sur' topic                      -> Ask
	* noun 'a//' creature                       -> AskFor
	* creature 'de' topic                       -> AskTo
	* 'que' creature topic                      -> AskTo;

Verb 'attaquer' 'casser' 'frapper' 'detruire' 'tuer'
     'battre' 'fendre' 'assasiner'
     'briser' 'torturer'
    * noun                                      -> Attack
    * noun 'avec' held                          -> Attack;

Verb 'escalader' 'grimper' 'monter'
	* noun                                      -> Climb
	* 'sur'       noun                          -> Climb
	* 'par' 'dessus'                            -> Climb
	* 'par-dessus'                              -> Climb
	* 'dans'        noun                        -> Enter;

Verb 'fermer' 'refermer' 'couvrir' 
	* noun                                      -> Close;

Verb 'couper' 'trancher' 'decouper'
	* noun                                      -> Cut
	* noun 'avec' held                          -> Attack;

Verb 'creuser'
	* noun                                      -> Dig
	* noun 'avec' held                          -> Dig;

Verb 'boire' 'avaler' 'siroter'
    * noun                                          -> Drink;

Verb 'poser' 'deposer' 'abandonner' 'lacher' 'lancer' 'jeter'
	* multiheld                                 -> Drop
	* multiexcept 'dans' noun                   -> Insert
	* held 'sur'/'dessus'/'contre' noun         -> ThrowAt;

Verb 'manger' 'devorer'
    * held                                          -> Eat;

Verb 'entrer' 'rentrer'
    * 'dans' noun                                   -> Enter
    * noun                                          -> Enter;

Verb 'examiner' 'x//'
    * noun                                          -> Examine;

Verb 'sortir' 'ressortir'
    *                                               -> Exit
    * noun                                          -> Exit;

Verb 'remplir'
    * noun                                          -> Fill;

Verb 'descendre' 'redescendre'
    * noun                                          -> GetOff;


Verb 'donner' 'offrir' 'payer' 'remettre'
    * held 'a//' creature                           -> Give
    * 'a//' creature held                           -> Give reverse;

[ ADirection;
	if (noun == Directions) rtrue;
	rfalse;
];

Verb 'aller'
	* noun=ADirection                           -> Go
	* 'a//'/'au' noun=ADirection                -> Go
	* noun                                      -> Enter;

Verb 'inserer' 'introduire'
    * multiexcept 'dans' noun                       -> Insert
    * multiexcept 'sur' noun                        -> PutOn;

Verb 'inventaire' 'i//'
    *                                               -> Inv;

Verb 'sauter'
    *                                               -> Jump
    * 'par-dessus' noun                             -> JumpOver
    * 'par' 'dessus' noun                           -> JumpOver
    * 'dans'/'sur' noun                             -> Enter;
!    * 'de'/'du'/'des' noun                          -> Exit;

Verb 'ecouter'
    *                                               -> Listen;

Verb 'verrouiller'
    * noun 'avec' held                              -> Lock;

Verb 'regarder' 'r//' 'observer'
    *                                               -> Look
    * noun                                          -> Examine
    * 'dans' noun                                   -> Search
    * 'a//' 'l^interieur' noun                      -> Search;

Verb 'ouvrir' 'decouvrir' 'deballer'
    * noun                                          -> Open
    * noun 'avec' held                              -> Unlock;

Verb 'tirer' 'trainer'
    * noun                                          -> Pull
    * 'sur' noun                                    -> Pull;

Verb 'appuyer'
    * 'sur' noun                                    ->Push;

Verb 'pousser' 'deplacer' 'bouger'
    * noun                                          -> Push
    * noun 'vers' noun=ADirection                   -> PushDir;

Verb 'transferer'
    * noun 'au' noun                                -> Transfer;

Verb 'mettre'
    * multiexcept 'dans' noun                       -> Insert
    * multiexcept 'sur' noun                        -> PutOn
    * held                                          -> Wear;

Verb 'lire'
    * noun                                          -> Examine
    * 'sur' topic 'dans' noun                       -> Consult
    * topic 'dans' noun                             -> Consult;

Verb 'enlever' 'oter' 'retirer'
    * held                                          -> Disrobe
    * multi                                         -> Take
    * multiinside 'de'/'du'/'des' noun              -> Remove;

Verb 'frotter' 'laver' 'nettoyer' 'polir' 'balayer' 'essuyer'
    * noun                                          -> Rub;

Verb 'fouiller'
    * noun                                          -> Search;

Verb 'crier' 'hurler'
    * topic 'a//' creature                          -> Answer
    * topic                                         -> Shout
    *                                               -> Shout;

Verb 'montrer' 'pointer' 'presenter'
    * creature held                                 -> Show reverse
    * held 'a//' creature                           -> Show;

Verb 's^asseoir' 's^allonger' 'm^asseoir' 'm^allonger'
    * 'sur'/'dans' noun                             -> Enter;

Verb 'sentir' 'renifler'
    *                                               -> Smell
    * noun                                          -> Smell;

!Verb 'stand'
!   *                                               -> Exit
!   * 'up'                                          -> Exit
!   * 'on' noun                                     -> Enter;

Verb 'allumer' 'demarrer'
    * noun                                          ->SwitchOn;
Verb 'eteindre' 'arreter'
    * noun                                          ->SwitchOff;

Verb 'prendre' 'ramasser' 'cueillir'
    * multi                                         -> Take
    * multiinside 'de'/'du'/'des' noun              -> Remove;

Verb 'attacher' 'nouer' 'accrocher' 'connecter' 'brancher'
    * noun                                          -> Tie
    * noun 'a//' noun                               -> Tie;

Verb 'toucher'
    * noun                                          -> Touch;

Verb 'tourner' 'devisser' 'visser'
	* noun                                      -> Turn;

Verb 'deverrouiller'
	* noun 'avec' held                          -> Unlock;

Verb 'attendre' 'z//'
    *                                               -> Wait;

Verb 'enfiler' 'porter' 'revetir'
    * held		                            -> Wear;

[ AnswerSub;
	if (second > 1 && RunLife(second,##Answer) ~= 0) rfalse;
	PrintMsg(MSG_ANSWER_DEFAULT);
];

[ AskSub;
	if (RunLife(noun,##Ask) ~= 0) rfalse;
	PrintMsg(MSG_ASK_DEFAULT);
];

[ AskToSub;
	PrintMsg(MSG_ASKTO_DEFAULT, noun);
];

[ AskForSub;
	if (noun == player) <<Inv>>;
	PrintMsg(MSG_ASKFOR_DEFAULT, noun);
];

[ AttackSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun has animate && RunLife(noun, ##Attack) ~= 0) rfalse;
	PrintMsg(MSG_ATTACK_DEFAULT);
];

[ ClimbSub;
	if(noun has animate) { PrintMsg(MSG_CLIMB_ANIMATE); rtrue;}
	PrintMsg(MSG_CLIMB_DEFAULT);
];

[ CloseSub;
	if(ObjectIsUntouchable(noun)) return;
	if(noun hasnt openable) { PrintMsg(MSG_CLOSE_YOU_CANT, 'fermer'); rtrue; }
	if(noun hasnt open) { PrintMsg(MSG_CLOSE_NOT_OPEN, noun); rtrue; }
	give noun ~open;
	scope_modified = true;
	run_after_routines_msg = MSG_CLOSE_DEFAULT;
	run_after_routines_arg_1 = 'fermer';
];

[ ConsultSub;
	PrintMsg(MSG_CONSULT_NOTHING_INTERESTING);
];

[ CutSub;
	PrintMsg(MSG_CUT_NO_USE);
];

[ DigSub;
	PrintMsg(MSG_DIG_NO_USE);
];

[ DisrobeSub;
    if (noun notin player || noun hasnt worn) { PrintMsg(MSG_DISROBE_NOT_WEARING); rtrue; }
    give noun ~worn;
	run_after_routines_msg = MSG_DISROBE_DEFAULT;
];

[ DrinkSub;
	PrintMsg(MSG_DRINK_NOTHING_SUITABLE);
];

[ DropSub _p;
	if(noun notin player) { PrintMsg(MSG_DROP_NOT_HOLDING); rtrue; }
	if(_ImplicitDisrobeIfWorn(noun)) rtrue;
	_p = parent(player);
	!if(_p ~= location) <<Insert noun _p>>;
	move noun to parent(player);
	give noun moved;
	run_after_routines_msg = MSG_DROP_DROPPED;
];

[ EatSub;
	if(ObjectIsUntouchable(noun)) return;
	if(noun has animate) { PrintMsg(MSG_EAT_ANIMATE); rtrue; }
	if(noun hasnt edible) { PrintMsg(MSG_EAT_INEDIBLE); rtrue; }
	remove noun;
	scope_modified = true;
	run_after_routines_msg = MSG_EAT_DEFAULT;
];

[ EnterSub _door_dir;
	if(noun has door) {
#IfDef OPTIONAL_SIMPLE_DOORS;
		if(noun.#door_dir > 2) {
			! This is a Simple Door, where door_dir is an array
			if(real_location == noun.&found_in-->1)
				_door_dir = 1;
			_door_dir = noun.&door_dir-->_door_dir;
		} else {
#EndIf;
			! Normal Inform door
			_door_dir = noun.door_dir;
			if(UnsignedCompare(_door_dir, top_object) > 0) {
				_door_dir = noun.door_dir();
			}
#IfDef OPTIONAL_SIMPLE_DOORS;
		}
#EndIf;
		! Convert to fake object
		_door_dir = DirPropToFakeObj(_door_dir);
		<<Go _door_dir>>;
	}
	if(noun hasnt enterable) { PrintMsg(MSG_ENTER_YOU_CANT, 'entrer'); rtrue; }
	if(player in noun) { PrintMsg(MSG_ENTER_ALREADY); rtrue; }
	if(noun has container && noun hasnt open) { PrintMsg(MSG_ENTER_NOT_OPEN, noun); rtrue; }
	if(parent(noun) ~= parent(player)) { PrintMsg(MSG_ENTER_BAD_LOCATION); rtrue; }
	PlayerTo(noun, true);
	run_after_routines_msg = MSG_ENTER_DEFAULT;
	run_after_routines_arg_1 = 'entrer';
];

[ ExamineSub x;
#Ifndef OPTIONAL_NO_DARKNESS;
	if(location == thedark) {
		PrintMsg(MSG_EXAMINE_DARK);
		rtrue;
	}
#Endif;
    if (noun.description == 0) {
        if (noun has container) {
            if (noun has open or transparent) <<Search noun>>;
            else { PrintMsg(MSG_EXAMINE_CLOSED, noun); rtrue;	}
		}
        if (noun has switchable) { PrintMsg(MSG_EXAMINE_ONOFF); rtrue; }
		PrintMsg(MSG_EXAMINE_NOTHING_SPECIAL);
		rtrue;
    }
	x = PrintOrRun(noun, description);
	if (x == 0 && noun has switchable) PrintMsg(MSG_EXAMINE_ONOFF);
	run_after_routines_msg = 1; ! Run after routines, don't print a msg
];

[ ExitSub _p;
	_p = parent(player);
	if(parent(_p) == 0) { PrintMsg(MSG_EXIT_ALREADY); rtrue; }
	if(noun == 0) <<Exit _p>>;
	if(player notin noun) {
		if(IndirectlyContains(noun, player)) { PrintMsg(MSG_EXIT_FIRST_LEAVE, parent(player)); rtrue; }
		if(noun has supporter) { PrintMsg(MSG_EXIT_NOT_ON); rtrue; }
		PrintMsg(MSG_EXIT_NOT_IN);
		rtrue;
	}
	if(noun has container && noun hasnt open) { PrintMsg(MSG_EXIT_NOT_OPEN, noun); rtrue; }
	PlayerTo(parent(noun), true);
	run_after_routines_msg = MSG_EXIT_DEFAULT;
	run_after_routines_arg_1 = 'sortir';
];

[ FillSub;
	PrintMsg(MSG_FILL_NO_WATER);
];

[ GetOffSub;
	if (parent(player) == noun) <<Exit noun>>;
	PrintMsg(MSG_EXIT_NOT_ON); rtrue;
];

[ GiveSub;
	if(ObjectIsUntouchable(second)) return;
	if (parent(noun) ~= player) { PrintMsg(MSG_GIVE_NOT_HOLDING); rtrue; }
	if (second == player)  { PrintMsg(MSG_GIVE_PLAYER); rtrue; }
	if (RunLife(second, ##Give) ~= 0) rfalse;
	PrintMsg(MSG_GIVE_DEFAULT);
];

[ GoSub _prop;
	! when called Directions have been set properly
	_prop = selected_direction;
#IfTrue RUNTIME_ERRORS > RTE_MINIMUM;
	if(_prop == 0) return RuntimeError(ERR_INVALID_DIR_PROP);
#EndIf;

	GoDir(_prop);
];

! Generic routine to move object. Can be used for Insert, PutOn, Take, Drop, Transfer, Empty (and Enter/Exit?)
! p_messages:
! 0: Noun is already in second
! 1: Can't put noun in/on itself
! 2: Second isn't open
! 3: Try to grab if not held (1 to try, no message#)
! 4: Try to disrobe noun if worn (1 to try, no message#)
! 5: Second is animate
! 6: Second isn't container
! 7: Second isn't supporter
! 8: Check if second is full
! 9: Default (success) message
[ _MoveNounToSecond p_messages _msg _ancestor _action;
	if(ObjectIsUntouchable(second)) return;
	_ancestor = CommonAncestor(noun, second);

	_msg = p_messages-->0;
	if(_msg && parent(noun) == second) {
		PrintMsg(_msg);
		rtrue;
	}
	_msg = p_messages-->1;
	if(_msg && _ancestor == noun) {
		PrintMsg(_msg);
		rtrue;
	}
	_msg = p_messages-->2;
	if(_msg && second ~= _ancestor && second has container && second hasnt open) {
		PrintMsg(_msg, second);
		rtrue;
	}
	_msg = p_messages-->3;
	if(_msg && noun ~=player && second ~= Directions &&  _ImplicitGrabIfNotHeld(noun)) rtrue;

	_msg = p_messages-->4;
	if(_msg && _ImplicitDisrobeIfWorn(noun)) rtrue;

	! run before on receiver
#IfDef DEBUG;
	if(debug_flag & 1) print "(", (name) second, ").before()^";
#EndIf;
	receive_action = action;
	_action = action; action = ##Receive;
	if(RunRoutines(second, before) ~= 0) { action = _action; rtrue; }
	action = _action;

	_msg = p_messages-->5;
	if(_msg && second has animate) {
		PrintMsg(_msg);
		rtrue;
	}
	_msg = p_messages-->6;
	if(_msg && second hasnt container) {
		PrintMsg(_msg, second);
		rtrue;
	}
	_msg = p_messages-->7;
	if(_msg && second hasnt supporter) {
		PrintMsg(_msg, second);
		rtrue;
	}
	_msg = p_messages-->8;
	if(_msg && _AtFullCapacity(second)) {
		PrintMsg(_msg);
		rtrue;
	}

	move noun to second;

	! run after on object
	if(AfterRoutines()) rtrue;

	! run after on receiver
#IfDef DEBUG;
	if(debug_flag & 1) print "(", (name) second, ").after()^";
#EndIf;
	_action = action; action = ##Receive;
	if(RunRoutines(second, after) ~= 0) { action = _action; rtrue; }
	action = _action;

	if (keep_silent) return;
	_msg = p_messages-->9;
	if(_msg) PrintMsg(_msg);
];


! 0: Noun is already in second
! 1: Can't put noun in/on itself
! 2: Second isn't open
! 3: Try to grab if not held (1 to try, no message#)
! 4: Try to disrobe noun if worn (1 to try, no message#)
! 5: Second is animate
! 6: Second isn't container
! 7: Second isn't supporter
! 8: Check if second is full
! 9: Default (success) message
Array _InsertMessages -->
	MSG_INSERT_ALREADY
	MSG_INSERT_ITSELF
	MSG_INSERT_NOT_OPEN
	1
	1
	MSG_INSERT_ANIMATE
	MSG_INSERT_NOT_CONTAINER
	0
	MSG_INSERT_NO_ROOM
	MSG_INSERT_DEFAULT;

[ InsertSub;
	if(noun == player) <<Enter second>>;
	_MoveNounToSecond(_InsertMessages);
];

[ InvSub;
    if(PrintMsg(MSG_INVENTORY_DEFAULT) == false) {
		PrintMsg(MSG_INVENTORY_EMPTY);
	}
	run_after_routines_msg = 1; ! Run after routines, don't print a msg
];

[ JumpSub;
	PrintMsg(MSG_JUMP);
];

[ JumpOverSub;
	PrintMsg(MSG_JUMP_OVER);
];

[ ListenSub;
    PrintMsg(MSG_LISTEN_DEFAULT);
];

[ LockSub;
	if (ObjectIsUntouchable(noun)) return;
	if (ObjectIsUntouchable(second)) return;
	if (noun hasnt lockable) { PrintMsg(MSG_LOCK_NOT_A_LOCK, 'verrouiller'); rtrue; }
	if (noun has locked)  { PrintMsg(MSG_LOCK_ALREADY_LOCKED, 'verrouiller'); rtrue; }
	if (noun has open) { PrintMsg(MSG_LOCK_CLOSE_FIRST); rtrue; }
	if (RunRoutines(noun, with_key) ~= second) { PrintMsg(MSG_LOCK_KEY_DOESNT_FIT); rtrue; }
	give noun locked;
	run_after_routines_msg = MSG_LOCK_DEFAULT;
	run_after_routines_arg_1 = 'verrouiller';
];

[ LookSub _old_lookmode;
	_old_lookmode = lookmode;
	lookmode = 2; ! force long description
	Look();
	lookmode = _old_lookmode;
];

[ OpenSub;
	if(ObjectIsUntouchable(noun)) return;
	if(noun hasnt openable) { PrintMsg(MSG_OPEN_YOU_CANT, 'ouvrir'); rtrue; }
	if(noun has locked) { PrintMsg(MSG_OPEN_LOCKED); rtrue; }
	if(noun has open) { PrintMsg(MSG_OPEN_ALREADY); rtrue; }
	give noun open;
	scope_modified = true;
	run_after_routines_msg = MSG_OPEN_DEFAULT;
];

[ PullSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun has static)   { PrintMsg(MSG_PULL_STATIC); rtrue; }
	if (noun has scenery)  { PrintMsg(MSG_PULL_SCENERY); rtrue; }
	if (noun has animate)  { PrintMsg(MSG_PULL_ANIMATE); rtrue; }
	PrintMsg(MSG_PULL_DEFAULT); !Nothing obvious happens
];

[ PushSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun has static)   { PrintMsg(MSG_PUSH_STATIC); rtrue; }
	if (noun has scenery)  { PrintMsg(MSG_PUSH_SCENERY); rtrue; }
	if (noun has animate)  { PrintMsg(MSG_PUSH_ANIMATE); rtrue; }
	PrintMsg(MSG_PUSH_DEFAULT);
];

[ PushDirSub;
	PrintMsg(MSG_PUSHDIR_DEFAULT);
];

! 0: Noun is already in second
! 1: Can't put noun in/on itself
! 2: Second isn't open
! 3: Try to grab if not held (1 to try, no message#)
! 4: Try to disrobe noun if worn (1 to try, no message#)
! 5: Second is animate
! 6: Second isn't container
! 7: Second isn't supporter
! 8: Check if second is full
! 9: Default (success) message
Array _PutOnMessages -->
	MSG_PUTON_ALREADY
	MSG_PUTON_ITSELF
	0
	1
	1
	MSG_PUTON_ANIMATE
	0
	MSG_PUTON_NOT_SUPPORTER
	MSG_PUTON_NO_ROOM
	MSG_PUTON_DEFAULT;

[ PutOnSub;
	if(noun == player) <<Enter second>>;
	_MoveNounToSecond(_PutOnMessages);
];

[ RemoveSub _i;
	_i = parent(noun);
	if (_i has container && _i hasnt open) { PrintMsg(MSG_REMOVE_CLOSED, _i); rtrue; }
	if (_i ~= second) { PrintMsg(MSG_REMOVE_NOT_HERE); rtrue; }
	if(TryToTakeNoun() ~= false) rtrue;
	action = ##Remove; if (AfterRoutines()) rtrue;
	action = ##Take;
	run_after_routines_msg = MSG_REMOVE_DEFAULT;
];

[ RubSub;
	PrintMsg(MSG_RUB_DEFAULT);
];

[ SearchSub _f _i;
#Ifndef OPTIONAL_NO_DARKNESS;
	if(location == thedark) { PrintMsg(MSG_SEARCH_DARK); rtrue; }
#Endif;
	if (ObjectIsUntouchable(noun)) return;
	objectloop(_i in noun) if(_i hasnt concealed && _i hasnt scenery) _f++;
	if(noun has supporter) {
		if(_f == 0)
			PrintMsg(MSG_SEARCH_NOTHING_ON);
		else
			PrintMsg(MSG_SEARCH_ON_IT_ISARE);
		rtrue;
	}
	if(noun hasnt container) { PrintMsg(MSG_SEARCH_NOTHING_SPECIAL); rtrue; }
	if(noun hasnt transparent && noun hasnt open) {
		PrintMsg(MSG_SEARCH_CANT_SEE_CLOSED); rtrue;
	}
	if(AfterRoutines()) rtrue;
	_i = MSG_SEARCH_EMPTY;
	if(_f)
		_i = MSG_SEARCH_IN_IT_ISARE;
	PrintMsg(_i);
];

[ ShoutSub;
	PrintMsg(MSG_SHOUT_DEFAULT);
];

[ ShowSub;
	if (parent(noun) ~= player) { PrintMsg(MSG_SHOW_NOT_HOLDING); rtrue; }
	if (second == player) <<Examine noun>>;
	if (RunLife(second, ##Show) ~= 0) rfalse;
	PrintMsg(MSG_SHOW_DEFAULT);
];

[ SmellSub;
	if(ObjectIsUntouchable(noun)) return;
	PrintMsg(MSG_SMELL_DEFAULT);
];

[ SwitchOffSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun hasnt switchable) { PrintMsg(MSG_SWITCH_OFF_NOT_SWITCHABLE); rtrue; }
	if (noun hasnt on)         { PrintMsg(MSG_SWITCH_OFF_NOT_ON); rtrue; }
	give noun ~on;
	run_after_routines_msg = MSG_SWITCH_OFF_DEFAULT;
];

[ SwitchOnSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun hasnt switchable) { PrintMsg(MSG_SWITCH_ON_NOT_SWITCHABLE); rtrue; }
	if (noun has on)           { PrintMsg(MSG_SWITCH_ON_ON); rtrue; }
	give noun on;
	run_after_routines_msg = MSG_SWITCH_ON_DEFAULT;
];

[ TakeSub;
	if(TryToTakeNoun() ~= false) rtrue;
	run_after_routines_msg = MSG_TAKE_DEFAULT;
];

[ TieSub;
	PrintMsg(MSG_TIE_DEFAULT);
];

[ TellSub;
	if (noun == player) { PrintMsg(MSG_TELL_PLAYER); rtrue; }
	if (RunLife(noun, ##Tell) ~= 0) rfalse;
	PrintMsg(MSG_TELL_DEFAULT);
];

[ ThrowAtSub;
	if(_ImplicitGrabIfNotHeld(noun)) rtrue;
	if(ObjectIsUntouchable(second)) return;
	if(_ImplicitDisrobeIfWorn(noun)) rtrue;
	if(second > 1) {
#IfDef DEBUG;
		if(debug_flag & 1) print "(", (name) second, ").before()^";
#EndIf;
		action = ##ThrownAt;
		if (RunRoutines(second, before) ~= 0) { action = ##ThrowAt; rtrue; }
		action = ##ThrowAt;
	}
	if(second hasnt animate) { PrintMsg(MSG_THROW_ANIMATE); rtrue; }
	if(RunLife(second,##ThrowAt) ~= 0) rfalse;
	PrintMsg(MSG_THROW_DEFAULT);
];

[ TouchSub;
	if(ObjectIsUntouchable(noun)) return;
	PrintMsg(MSG_TOUCH_DEFAULT);
];


[ TransferSub;
	if(noun in second || (noun in parent(player) && selected_direction == d_to)) {
		PrintMsg(MSG_TRANSFER_ALREADY);
		rtrue;
	}
	if(noun notin player && TryToTakeNoun() == true) return;
	if (second has supporter) <<PutOn noun second>>;
	if (second == Directions && selected_direction == d_to) <<Drop noun>>;
	<Insert noun second>;
];

[ TurnSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun has static)   { PrintMsg(MSG_TURN_STATIC); rtrue; }
	if (noun has scenery)  { PrintMsg(MSG_TURN_SCENERY); rtrue; }
	if (noun has animate)  { PrintMsg(MSG_TURN_ANIMATE); rtrue; }
	PrintMsg(MSG_TURN_DEFAULT);
];

[ UnlockSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun hasnt lockable) { PrintMsg(MSG_UNLOCK_NOT_A_LOCK, 'deverrouiller'); rtrue; }
	if (noun hasnt locked)  { PrintMsg(MSG_UNLOCK_ALREADY_UNLOCKED, 'deverrouiller'); rtrue; }
	if (RunRoutines(noun, with_key) ~= second) { PrintMsg(MSG_UNLOCK_KEY_DOESNT_FIT); rtrue; }
	give noun ~locked;
	run_after_routines_msg = MSG_UNLOCK_DEFAULT;
	run_after_routines_arg_1 = 'deverrouiller';
];

[ WaitSub;
	if(AfterRoutines()) rtrue;
	PrintMsg(MSG_WAIT_DEFAULT);
];

[ WearSub;
	if (parent(noun) ~= player) { PrintMsg(MSG_WEAR_NOT_HOLDING); rtrue; }
	if (noun has worn) { PrintMsg(MSG_WEAR_ALREADY_WORN); rtrue; }
	if (noun hasnt clothing) { PrintMsg(MSG_WEAR_NOT_CLOTHING, 'porter'); rtrue; }
	give noun worn;
	run_after_routines_msg = MSG_WEAR_DEFAULT;
];


! ---------------------
! Extended verbs
! ---------------------

#IfDef OPTIONAL_EXTENDED_VERBSET;

Verb 'souffler'
	* held                                      -> Blow;

Verb 'mince' 'zut' 'crotte'
	*                                           -> Mild
	* topic                                     -> Mild;

Verb 'bruler'
	* noun                                      -> Burn
	* noun 'avec' held                          -> Burn;

Verb 'acheter'
	* noun                                      -> Buy;

Verb 'consulter'
	* noun 'sur  ' topic                        -> Consult;

Verb 'vider'
	* noun                                      -> Empty
	* noun 'dans'/'sur' noun                    -> EmptyT;

Verb 'dedans'
	*                                           -> GoIn;

Verb 'embrasser' 'caliner' 'enlacer'
    * creature                                  -> Kiss;

Verb 'non'
	*                                           -> No;

Verb 'decoller'
	* noun                                      -> Take;

Verb 'prier'
    *                                           -> Pray;

Verb 'forcer'
	* noun 'avec' held                          -> Unlock;

Verb 'regler' 'adjuster'
	* noun                                      -> Set
	* noun 'a//' special                         -> SetTo;

Verb 'merde' 'putain' 'connard'
	*                                           -> Strong
	* topic                                     -> Strong;

Verb 'chanter'
	*                                           -> Sing;

Verb 'dormir'
	*                                           -> Sleep;

Verb 'pardon'
	*                                           -> Sorry;

Verb 'ecraser' 'ecrabouiller' 'presser'
	* noun                                      -> Squeeze;

Verb 'nager' 'plonger'
	*                                           -> Swim;

Verb 'balancer'
	* noun                                      -> Swing
	* 'sur' noun                                 -> Swing;

Verb 'gouter'
	* noun                                      -> Taste;

Verb 'reflechir'
	*                                           -> Think;

Verb 'transferer'
	* noun 'to' noun                            -> Transfer;

Verb 'reveiller'
    * 'se'                                      -> Wake
    * creature                                  -> WakeOther;

Verb 'saluer'
	*                                           -> WaveHands
	* noun                                      -> Wave;

Verb 'oui' 'o//'
	*                                           -> Yes;

[ BlowSub;
	PrintMsg(MSG_BLOW_DEFAULT);
];

[ BurnSub;
	PrintMsg(MSG_BURN_DEFAULT);
];

[ BuySub;
	PrintMsg(MSG_BUY_DEFAULT);
];

[ EmptySub;
	<EmptyT noun FAKE_D_OBJ>;
];

[ EmptyTSub _i _recipient;
	if(noun == second) { PrintMsg(MSG_EMPTY_WOULDNT_ACHIEVE); rtrue; }
	if(noun has container && noun hasnt open) {
		PrintMsg(MSG_EMPTY_IS_CLOSED, noun);
		rtrue;
	}
	if(second == Directions && selected_direction ~= 0)
		_recipient = DirPropToFakeObj(selected_direction);
	else
		_recipient = second;
	_i = child(noun);
	if(_i == 0) { PrintMsg(MSG_EMPTY_ALREADY_EMPTY, noun); rtrue; }
	while(_i ~= 0) {
		if(keep_silent == 0) print (name) _i, ": ";
		<Transfer _i _recipient>;
		if(_i in noun || _i in player) rtrue;
		_i = child(noun);
	}
	run_after_routines_msg = 1;
];

[ GoInSub;
	! shortcut to <<Go in>>
	<Go FAKE_IN_OBJ>;
];

[ KissSub;
    if (ObjectIsUntouchable(noun)) return;
    if (RunLife(noun, ##Kiss) ~= 0) rfalse;
    if (noun == player) { PrintMsg(MSG_KISS_PLAYER); rtrue; }
    PrintMsg(MSG_KISS_DEFAULT);
];

[ MildSub;
	PrintMsg(MSG_MILD_DEFAULT);
];

[ NoSub;
	PrintMsg(MSG_RHETORICAL_QUESTION);
];

[ PraySub;
	PrintMsg(MSG_PRAY_DEFAULT);
];

[ SetSub;
	PrintMsg(MSG_SET_DEFAULT);
];

[ SetToSub;
	PrintMsg(MSG_SET_TO_DEFAULT);
];

[ SingSub;
	PrintMsg(MSG_SING_DEFAULT);
];

[ SleepSub;
	PrintMsg(MSG_SLEEP_DEFAULT);
];

[ SorrySub;
	PrintMsg(MSG_SORRY_DEFAULT);
];

[ StrongSub;
	PrintMsg(MSG_STRONG_DEFAULT);
];

[ SqueezeSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun has animate) { PrintMsg(MSG_SQUEEZE_YOURSELF); rtrue; }
	PrintMsg(MSG_SQUEEZE_DEFAULT);
];

[ SwimSub;
	PrintMsg(MSG_SWIM_DEFAULT);
];

[ SwingSub;
	PrintMsg(MSG_SWING_DEFAULT);
];

[ TasteSub;
	if (ObjectIsUntouchable(noun)) return;
	PrintMsg(MSG_TASTE_DEFAULT);
];

[ ThinkSub;
	PrintMsg(MSG_THINK_DEFAULT);
];

[ WakeSub;
    PrintMsg(MSG_WAKE_DEFAULT);
];

[ WakeOtherSub;
    if (ObjectIsUntouchable(noun)) return;
    if (RunLife(noun, ##WakeOther) ~= 0) rfalse;
    PrintMsg(MSG_WAKEOTHER_DEFAULT);
];

[ WaveSub;
    if(parent(noun) ~= player) { PrintMsg(MSG_WAVE_NOTHOLDING, noun); rtrue; }
    PrintMsg(MSG_WAVE_DEFAULT);
];

[ WaveHandsSub;
	PrintMsg(MSG_WAVEHANDS_DEFAULT);
];

[ YesSub;
	PrintMsg(MSG_RHETORICAL_QUESTION);
];

#EndIf;

! ---------------------
! Base meta verbs
! ---------------------

Verb meta 'encore' 'g//'
    *                                           -> Again;

#Ifdef OPTIONAL_FULL_SCORE;
Verb meta 'fullscore' 'full'
    *                                           -> FullScore
    * 'score'                                   -> FullScore;
#Endif;

#Ifndef NO_SCORE;
Verb meta 'notifications'
	*                                           -> NotifyOn
	* 'on'                                      -> NotifyOn
	* 'off'                                     -> NotifyOff;
#Endif;

Verb meta 'oups'
    *                                           -> Oops
    * special                                   -> OopsCorrection;

Verb meta 'recommencer'
	*                                           -> Restart;

Verb meta 'charger'
	*                                           -> Restore;

Verb meta 'sauver' 'sauvegarder'
	*                                           -> Save;

#Ifndef NO_SCORE;
Verb meta 'score'
    *                                           -> Score;
#Endif;

    
Verb meta 'mode'
* 'bref'/'normal'                              -> LookModeNormal
* 'court'/'short'                              -> LookModeShort
* 'verbose'/'long'                             -> LookModeLong;

Verb meta 'version'
	*                                           -> Version;

Verb meta 'quitter' 'q//'
	*                                           -> Quit;

[ AgainSub;
	! nothing here - this is taken care of in the main game loop instead
];

#IfDef OPTIONAL_FULL_SCORE;
#IfDef TASKS_PROVIDED;
[ FullScoreSub _i _score_sum _sc;
#IfNot;
[ FullScoreSub _i _score_sum;
#EndIf;
	new_line;
	PrintMsg(MSG_FULLSCORE_START);
#IfDef TASKS_PROVIDED;
	for(_i=0 : _i<NUMBER_TASKS : _i++)
		if (task_done->_i == 1) {
			_sc = task_scores->(_i);
			PANum(_sc);
			_score_sum = _score_sum + _sc;
			PrintTaskName(_i);
		}
#IfNot;
	_i = 0; ! Avoid warning
#EndIf;
#IfDef OPTIONAL_SCORED;
	if(things_score ~= 0) {
		PANum(things_score);
		PrintMsg(MSG_FULLSCORE_OBJECTS);
	}
	if(places_score ~= 0) {
		PANum(places_score);
		PrintMsg(MSG_FULLSCORE_ROOMS);
	}
	_score_sum = score - _score_sum - things_score - places_score;
#IfNot;
	_score_sum = score - _score_sum;
#EndIf;
	if(_score_sum ~= 0) {
		PANum(_score_sum);
		PrintMsg(MSG_FULLSCORE_ACTIONS);
	}
	@new_line;
	PANum(score);
	PrintMsg(MSG_FULLSCORE_END);
];
#EndIf;

[ LookModeNormalSub;
	lookmode=1;
	PrintMsg(MSG_LOOKMODE_NORMAL);
];

[ LookModeLongSub;
	lookmode=2;
	PrintMsg(MSG_LOOKMODE_LONG);
];

[ LookModeShortSub;
	lookmode=3;
	PrintMsg(MSG_LOOKMODE_SHORT);
];

#Ifndef NO_SCORE;
[ NotifyOnSub;
	notify_mode = 1;
	"Score notification on.";
];

[ NotifyOffSub;
	notify_mode = 0;
	"Score notification off.";
];
#Endif;

[ OopsSub;
	"Pas grave.";
];

[ OopsCorrectionSub;
	! nothing here - this is taken care of in the main game loop instead
];

[ QuitSub;
	PrintMsg(MSG_AREYOUSUREQUIT);
	if(YesOrNo()) {
		deadflag = GS_QUIT;
	}
];

[ RestartSub;
    PrintMsg(MSG_RESTART_CONFIRM);
	if(YesOrNo()) {
		@restart;
        PrintMsg(MSG_RESTART_FAILED);
	}
];

#IfV3;
[ RestoreSub;
	@restore ?restore_success; ! can't use @restore because of compiler test
	verb_word = 'restore';
	PrintMsg(MSG_RESTORE_FAILED);
	rtrue;
.restore_success; ! This is never reached, since a successful restore continues after save opcode.
#IfNot;
[ RestoreSub _flag;
	@restore -> _flag;
	! must have failed here so no need to check the flag
	PrintMsg(MSG_RESTORE_FAILED);
#EndIf;
];

#IfV3;
[ SaveSub;
	@save ?save_success;
	PrintMsg(MSG_SAVE_FAILED);
	rtrue;
.save_success;
    PrintMsg(MSG_SAVE_DEFAULT);
#IfNot;
[ SaveSub _result;
	@save -> _result;
	if(_result == 0) { PrintMsg(MSG_SAVE_FAILED); rtrue; }
	PrintMsg(MSG_SAVE_DEFAULT); ! _result = 1: save ok, 2: Restore ok
#EndIf;
];

#Ifndef NO_SCORE;
[ ScoreSub;
	PrintMsg(MSG_SCORE_DEFAULT);
	PrintRank();
];
#Endif;

[ Banner _i;
	new_line;
#IfDef Story;
	#IfV5;
		style bold;
	#EndIf;
		print (string) Story;
	#IfV5;
		style roman;
	#EndIf;
	#IfDef Headline;
		print (string) Headline;
	#EndIf;
#EndIf;
	print "Release ", (0-->1) & $03ff, " / Serial number ";
	for (_i = 18:_i < 24: _i++) print (char) 0->_i;
	print " / Inform v";
	inversion;
	print " PunyInform v", PUNYINFORM_MAJOR_VERSION, (char) '.', PUNYINFORM_MINOR_VERSION;
#IfDef DEBUG;
	print " D";
#EndIf;
	@new_line;
];

[ VersionSub;
	Banner();
];

! ---------------------
! Extended meta verbs
! ---------------------

#IfDef OPTIONAL_EXTENDED_METAVERBS;
Global transcript_mode = false;        ! true when game scripting is on
Global xcommsdir = false;              ! true if command recording is on

Verb meta 'noscript' 'unscript'
	*                                           -> ScriptOff;

#Ifndef NO_PLACES;
Verb meta 'objects'
	*                                           -> Objects;
Verb meta 'places'
	*                                           -> Places;
#Endif; ! NO_PLACES

Verb meta 'recording'
	*                                           -> CommandsOn
	* 'on'                                      -> CommandsOn
	* 'off'                                     -> CommandsOff;

Verb meta 'replay'
	*                                           -> CommandsRead;

Verb meta 'script' 'transcript'
	*                                           -> ScriptOn
	* 'on'                                      -> ScriptOn
	* 'off'                                     -> ScriptOff;

Verb meta 'verify'
	*                                           -> Verify;

[ CommandsOnSub;
	@output_stream 4;
	xcommsdir = 1;
	"[Command recording on.]";
];

[ CommandsOffSub;
	if (xcommsdir == 1) @output_stream -4;
	xcommsdir = 0;
	"[Command recording off.]";
];

[ CommandsReadSub;
	@input_stream 1;
	xcommsdir = 2;
	"[Replaying commands.]";
];

#Ifndef NO_PLACES;
[ PlacesSub i j k;
	print "You have visited: ";
	objectloop(i has visited) if(parent(i) == 0) j++;
	objectloop(i has visited) {
		if(parent(i) == 0) {
			print (name) i; k++;
			if (k == j) { print ".^"; return; }
			if (k == j-1) print " and ";
			else          print ", ";
		}
	}
];

[ ObjectsSub i j f;
	print "Objects you have handled: ";
	objectloop (i has moved) {
		j = parent(i);
		if(j) {
			if(f == 0) @new_line;
			f = 1;
			print "- ", (the) i, "   ";
			if (j == player) {
				if (i has worn) {
					print "(worn)";
				} else {
					print "(held)";
				}
			} else if(j has animate) print "(given away)";
			else if(j has visited) print "(in ", (name) j, ")";
			else if(j has container) print "(inside ", (the) j, ")";
			else if(j has supporter) print "(on ", (the) j, ")";
			else if(j has enterable) print "(in ", (the) j, ")";
			else print "(lost)";
			@new_line;
		}
	}
	if(f == 0) "none.";
];
#Endif; ! NO_PLACES

[ ScriptOnSub;
	transcript_mode = ((HDR_FLAGS2-->0) & 1);
	if (transcript_mode) "Transcripting is already on.";
	@output_stream 2;
	if (((HDR_FLAGS2-->0) & 1) == 0) "Attempt to begin transcript failed.";
	print "Start of a transcript of^";
	Banner();
	transcript_mode = true;
];

[ ScriptOffSub;
	transcript_mode = ((HDR_FLAGS2-->0) & 1);
	if (transcript_mode == false) "Transcripting is already off.";
	print "^End of transcript.^";
	@output_stream -2;
	if ((HDR_FLAGS2-->0) & 1) "Attempt to end transcript failed.";
	transcript_mode = false;
];

[ VerifySub;
	@verify ?Vmaybe;
	jump Vwrong;
.Vmaybe;
	"The game file has verified as intact.";
.Vwrong;
	"The game file did not verify as intact, and may be corrupt.";
];


#EndIf;

! ---------------------
! Debug verbs
! ---------------------

#IfDef DEBUG;
Verb meta 'pronoun' 'pronouns'
    *                                           -> Pronouns;

Verb meta 'random'
	*                                           -> RandomSeed
	* special                                   -> RandomSeed
	* 'seed' number                             -> RandomSeed;

Verb meta 'scope'
	*                                           -> Scope
	* noun                                      -> Scope;

Verb meta 'purloin'
	* noun										-> Purloin;

Verb meta 'tree'
	*											-> Tree
	* noun										-> Tree;

Verb meta 'gonear'
	* noun										-> GoNear;

Verb meta 'debug'
	*                                           -> Debug
	* 'reactive'                                -> Debug;

Verb meta 'routines' 'messages'
	*                                           -> RoutinesOn
	* 'on'                                      -> RoutinesOn
	* 'off'                                     -> RoutinesOff;

Verb meta 'actions'
	*                                           -> ActionsOn
	* 'on'                                      -> ActionsOn
	* 'off'                                     -> ActionsOff;

Verb meta 'timers' 'daemons'
	*                                           -> TimersOn
	* 'on'                                      -> TimersOn
	* 'off'                                     -> TimersOff;

Global scope_cnt;

[ GoNearSub _obj;
	_obj = noun;
	while(parent(_obj) ~= 0) _obj = parent(_obj);
	PlayerTo(_obj);
];

[ PronounsSub;
	print "It: ", (name) itobj, "^Him: ", (name) himobj, "^Her: ", (name) herobj, "^Them: ", (name) themobj, "^";
];

[ PurloinSub;
	if(noun == player) { PrintMsg(MSG_TAKE_YOURSELF); rtrue; }
	if(IndirectlyContains(noun, player)) { PrintMsg(MSG_TAKE_PLAYER_PARENT, noun); rtrue; }

	move noun to player;
	scope_modified = true;
	"Purloined.";
];

[ RandomSeedSub _i;
	! sets the random seed, making randomness predictable
	! also a test of special and number, thus the fancy grammar
	!print special_word, " ", special_number," ",parsed_number,"^";
	if(special_word ~=0) "You can't send randomness to an object!";
	_i = parsed_number;
	if(_i == 0) _i = 100; ! either 'xxxx' (unknown special) or '0'
	random(-_i);
	"The random seed is set to ", _i, ".";
];

[ _ScopeSubHelper p_obj;
	print scope_cnt++,": ", (a) p_obj, " (", p_obj, ")";
	if(ObjectIsUntouchable(p_obj, true)) print " [untouchable]";
	@new_line;
];

[ ScopeSub;
	scope_cnt = 1;
	LoopOverScope(_ScopeSubHelper, noun);
	if(scope_cnt < 2) "Nothing in scope.^";
];

[ TreeSub _obj _p;
	_obj = noun;
	if(_obj==0) _obj = real_location;
	print (name) _obj;
	_p = parent(_obj);
	if(_p) {
		print " (";
		if(_p has supporter)
			@print_char 'o';
		else
			@print_char 'i';
		print "n ", (name) _p, ")";
	}
	@new_line;
	TreeSubHelper(_obj, 1);
];

[TreeSubHelper p_parent p_indent _x _i;
	objectloop(_x in p_parent) {
		for(_i = 0 : _i < p_indent : _i++) print "  ";
		print (name) _x, "^";
		if(child(_x)) TreeSubHelper(_x, p_indent + 1);
	}
];

[DebugSub _w _o;
	wn = num_words;
	_w = NextWord();
	switch(_w) {
		'reactive':
#Ifndef OPTIONAL_MANUAL_REACTIVE;
			_o = 1;
			"Define OPTIONAL_MANUAL_REACTIVE and recompile.";
#Ifnot;
			print "Probably give reactive to these objects (see notes about ~reactive~ in manual) :^";
			objectloop(_o) {
#Ifdef OPTIONAL_REACTIVE_PARSE_NAME;
				if(_o hasnt reactive && (_o.&react_before ~= 0 ||
						_o.&react_after ~= 0 || _o.&each_turn ~= 0 ||
						_o.&add_to_scope ~= 0 || _o.&parse_name ~= 0))
					print "(",_o,") ", (name) _o, "^";
#Ifnot;
				if(_o hasnt reactive && (_o.&react_before ~= 0 ||
						_o.&react_after ~= 0 || _o.&each_turn ~= 0 ||
						_o.&add_to_scope ~= 0))
					print "(",_o,") ", (name) _o, "^";
#Endif;
			}
			print "^Remove reactive from these objects:^";
			objectloop(_o) {
#Ifdef OPTIONAL_REACTIVE_PARSE_NAME;
				if(_o has reactive && _o.&react_before == 0 &&
						_o.&react_after == 0 && _o.&each_turn == 0 &&
						_o.&add_to_scope == 0 && _o.&parse_name == 0)
					print "(",_o,") ", (name) _o, "^";
#Ifnot;
				if(_o has reactive && _o.&react_before == 0 &&
						_o.&react_after == 0 && _o.&each_turn == 0 &&
						_o.&add_to_scope == 0)
					print "(",_o,") ", (name) _o, "^";
#Endif;
			}
#Endif;
		default:
			"Type one of the following:^
			DEBUG REACTIVE";
	}
];

[ RoutinesOnSub;  debug_flag = debug_flag | 1;  "[Message listing on.]"; ];

[ RoutinesOffSub; debug_flag = debug_flag & 14; "[Message listing off.]"; ];

[ ActionsOnSub;   debug_flag = debug_flag | 2;  "[Action listing on.]"; ];

[ ActionsOffSub;  debug_flag = debug_flag & 13; "[Action listing off.]"; ];

[ TimersOnSub;    debug_flag = debug_flag | 4;  "[Timers listing on.]"; ];

[ TimersOffSub;   debug_flag = debug_flag & 11; "[Timers listing off.]"; ];


#EndIf;

! ---------------------
! HELP ROUTINES
! ---------------------

[ _ListObjsMsg;
	print "^Vous voyez ";
	if(also_flag) print "aussi ";
	!print "see ";
];

[ _ListObjsInOnMsg p_parent;
	if(newline_flag)
		print "^";
	if(p_parent has supporter) print "Sur "; else print "Dans ";
	print (the) p_parent, " vous voyez ";
	if(also_flag) print "aussi ";
	!print "voir ";
];

[ Look _obj _top_ceil _ceil _initial_found _describe_room
	_you_can_see_1 _you_can_see_2 _desc_prop _last_level _action;
	PrintMsg(MSG_LOOK_BEFORE_ROOMNAME);
	if((lookmode == 1 && location hasnt visited) || lookmode == 2) _describe_room = true;
#IfV5;
	style bold;
#EndIf;

	! Print the room name
#Ifdef OPTIONAL_NO_DARKNESS;
	_ceil = ScopeCeiling(player, _last_level);
#Ifnot;
	if(location == thedark)
		_ceil = location;
	else
		_ceil = ScopeCeiling(player, _last_level);
#Endif;

	_top_ceil = _ceil;

	if(_ceil == location) {
#IfDef OPTIONAL_SCORED;
		if(location has scored && location hasnt visited) {
			score = score + ROOM_SCORE;
#IfDef OPTIONAL_FULL_SCORE;
			places_score = places_score + ROOM_SCORE;
#EndIf;
		}
#EndIf;
		_PrintObjName(location);
	} else {
		print (The) _ceil;
	}
#IfV5;
	style roman;
#EndIf;
#Ifndef OPTIONAL_NO_DARKNESS;
	if(location == thedark) {
		@new_line;
		PrintOrRun(location, description);
		jump EndOfLook;
	}
#Endif;
	_obj = parent(player);
	while(_obj ~= _ceil or 0) {
		if(_obj has supporter)
			print " (sur ";
		else
			print " (dans ";
		print (the) _obj, ")";
		_obj = parent(_obj);
	}
	while(_ceil ~= player or 0) {
		if(_describe_room) {
			if(_ceil == location) {
				@new_line;
				PrintOrRun(_ceil, description);
			} else if(_ceil.inside_description ~= 0 or NULL) {
				@new_line;
				PrintOrRun(_ceil, inside_description);
			}
		} else if(_ceil == location)
			@new_line;

		also_flag = false;
		! write intial and describe messages in a new paragraph
		objectloop(_obj in _ceil && _obj hasnt scenery or concealed && _obj ~= player) {
			give _obj workflag;
			if(_obj.&describe) {
				if(PrintOrRun(_obj, describe, 0)) {
					_initial_found = true;
					give _obj ~workflag;
					also_flag = true;
					continue;
				}
			}
			if(_obj has container or door) {
				if(_obj has open) {
					_desc_prop = when_open;
				} else {
					_desc_prop = when_closed;
				}
			} else if(_obj has switchable) {
				if(_obj has on) {
					_desc_prop = when_on;
				} else {
					_desc_prop = when_off;
				}
			} else {
				_desc_prop = initial;
			}
			if(_obj.&_desc_prop && (_obj hasnt moved || _desc_prop == when_off)) { ! Note: when_closed in an alias of when_off
				_initial_found = true;
				give _obj ~workflag;
				@new_line;
				PrintOrRun(_obj, _desc_prop);
				also_flag = true;
			}
		}

		! write any remaining objects in a new paragraph
		if(parent(_ceil) == 0) {
			_you_can_see_1 = _ListObjsMsg;
			_you_can_see_2 = " ici.^";
		} else {
			_you_can_see_1 = _ListObjsInOnMsg;
			_you_can_see_2 = ".^";
		}
		newline_flag = true;
		if(PrintContents(_you_can_see_1, _ceil, true)) print (string) _you_can_see_2;


#IfDef OPTIONAL_PRINT_SCENERY_CONTENTS;
		newline_flag = true;
		objectloop(_obj in _ceil && _obj has scenery &&
				(_obj has supporter ||
					(_obj has container && _obj has transparent or open)) &&
					child(_obj) ~= 0 &&
					IndirectlyContains(_obj, player) == false) {
			if(PrintContents(_ListObjsInOnMsg, _obj)) {
				print (string) ". ";
				newline_flag = false;
			}
		}
		if(newline_flag == false)
			print "^";
#EndIf;

		! Descend one level
		_ceil = ScopeCeiling(player, _ceil);
	} ! while
.EndOfLook;
	! finally, call the optional library entry routine
	LookRoutine();
	_action = action; action = ##Look;
	AfterRoutines();
	action = _action;

	if(_top_ceil == location)
		give location visited;
];

#Ifndef NO_SCORE;
#Ifndef PrintRank;
[ PrintRank; "."; ];
#Endif;
#Endif;

#IfDef OPTIONAL_FULL_SCORE;
#IfDef TASKS_PROVIDED;
[ Achieved num;
    if (task_done->num == 0) {
        task_done->num = 1;
        score = score + task_scores->num;
    }
];
#EndIf;
[ PANum p_m _n;
	print "  ";
	_n = p_m;
	if(_n < 0)    { _n = -p_m; _n = _n*10; }
	if(_n < 10)   { print "   "; jump Panuml; }
	if(_n < 100)  { print "  "; jump Panuml; }
	if(_n < 1000) { print " "; }
.Panuml;
	print p_m, " ";
];
#EndIf;

[ TryToTakeNoun _i _k _ancestor _after_recipient;
    ! Try to transfer the given item to the player: return false
    ! if successful, true if unsuccessful, printing a suitable message
    ! in the latter case. Return value 2 means it was a success, and a "Taken"
	! message has been printed.
    ! People cannot ordinarily be taken.
    if(noun == player) { PrintMsg(MSG_TAKE_YOURSELF); rtrue; }
#Ifdef DisallowTakeAnimate;
	if(noun has animate && DisallowTakeAnimate(noun)) { PrintMsg(MSG_TAKE_ANIMATE); rtrue; }
#Ifnot;
    if(noun has animate) { PrintMsg(MSG_TAKE_ANIMATE); rtrue; }
#Endif;
	_ancestor = CommonAncestor(player, noun);

    if (_ancestor == 0) {
        _i = _ObjectScopedBySomething(noun);
        if (_i) _ancestor = CommonAncestor(player, _i);
    }

	if(noun in player) { PrintMsg(MSG_TAKE_ALREADY_HAVE); rtrue; }
	if(ObjectIsUntouchable(noun, false, true)) rtrue;
	if(IndirectlyContains(noun, player)) { PrintMsg(MSG_TAKE_PLAYER_PARENT, noun); rtrue; }

	! The item is now known to be accessible.

    ! Consult the immediate possessor of the item, if it's in a container
    ! which the actor is not in.

    _i = parent(noun);
    if (_i && _i ~= _ancestor && (_i has container or supporter)) {
        _after_recipient = _i;
#IfDef DEBUG;
		if(debug_flag & 1) print "(", (name) _i, ").before()^";
#EndIf;
        _k = action; action = ##LetGo;
        if (RunRoutines(_i, before)) { action = _k; rtrue; }
        action = _k;
    }

	if(noun has scenery) { PrintMsg(MSG_TAKE_SCENERY); rtrue; }
    if(noun has static) { PrintMsg(MSG_TAKE_STATIC); rtrue; }

    if(_AtFullCapacity(player)) { PrintMsg(MSG_TAKE_NO_CAPACITY); rtrue; }

	move noun to player;
	give noun ~concealed;
	update_moved = true;

	! Send "after" message to the object letting go of the item, if any.

	if (_after_recipient) {
#IfDef DEBUG;
		if(debug_flag & 1) print "(", (name) _after_recipient, ").after()^";
#EndIf;
		_k = action; action = ##LetGo;
		_i = RunRoutines(_after_recipient, after);
		action = _k;
		if(_i) return 2;
	}

	rfalse;
];

[ GoDir p_property _new_location _old_location  _door_to _vehicle _vehicle_mode _saved_location;
	if(parent(player) ~= real_location) {
		! special rule when in enterable (veichles)
		! before routine for the object is called with Go dir, and returns
		! 0   to disallow the movement, printing a refusal;
		! 1   to allow the movement, moving vehicle and player;
		! 2   to disallow but print and do nothing; or
		! 3   to allow but print and do nothing.
		_vehicle = parent(player);
#IfDef DEBUG;
		if(debug_flag & 1) print "(", (name) _vehicle, ").before()^";
#EndIf;
		_saved_location = location;
#Ifndef OPTIONAL_NO_DARKNESS;
		if(location == thedark) location = real_location;
#Endif;
		_vehicle_mode = RunRoutines(_vehicle, before);
		if(_vehicle_mode ~= 3) location = _saved_location;
		if(_vehicle_mode == 0) { PrintMsg(MSG_GO_FIRST_LEAVE, parent(player)); rtrue; }
		if(_vehicle_mode == 2 or 3) rtrue;
	}
	!if(player notin location) { PrintMsg(MSG_GO_FIRST_LEAVE, parent(player)); rtrue; }
	if(real_location provides p_property) {
		@get_prop real_location p_property -> _new_location; ! works in z3 and z5
	}
	if(_new_location ofclass String)
		print_ret (string) _new_location;
	if(UnsignedCompare(_new_location, top_object) > 0) {
		_new_location = real_location.p_property();
		if(_new_location == 1)
			rtrue;
	}

	! Check for a door
	if(_new_location ~= 0 && _new_location has door) {
		! The destination is in fact a door
		if(_new_location has concealed)
			_new_location = 0;
		else {
			if(_new_location hasnt open) { PrintMsg(MSG_GO_DOOR_CLOSED, _new_location); rtrue; }
			_door_to = _new_location.door_to;
#IfDef OPTIONAL_SIMPLE_DOORS;
			if(_door_to == 0) {
				! This is a Simple Door, where door_to has been left out
				if(real_location == _new_location.&found_in-->0)
					_door_to = 1;
				_new_location = _new_location.&found_in-->_door_to;
			} else {
#EndIf;
				! Normal Inform door
				if(UnsignedCompare(_door_to, top_object) > 0) {
					_new_location = _new_location.door_to();
	!				print "GoDir, door leads to ", (the) _new_location, "^";
					if(_new_location == 1)
						rtrue;
				} else
					_new_location = _door_to;
#IfDef OPTIONAL_SIMPLE_DOORS;
			}
#EndIf;
		}
	}

	! If _new_location is 0, we tell the player they can't go there and exit
	if(_new_location == 0) {
		if(real_location provides cant_go) {
#IfDef DEBUG;
#IfV3;
			if(debug_flag & 1) print "(", (name) real_location, ").cant_go()^";
#EndIf;
#EndIf;
			PrintOrRun(real_location, cant_go);
			rtrue;
		}
        PrintMsg(MSG_GO_CANT_GO);
		rtrue;
	}

#IfDef DEBUG;
#IfV3;
	if(debug_flag & 1) print "(", (name) _new_location, ").before()^";
#EndIf;
#EndIf;
	action = ##Going;
	if(RunRoutines(_new_location, before)) { action = ##Go; rtrue; }
	action = ##Go;

	if(_vehicle_mode == 1) {
		move _vehicle to _new_location;
		_new_location = _vehicle;
	}

	_old_location = location;

	PlayerTo(_new_location, true);
	if(deadflag ~= GS_PLAYING) rtrue;

	action = ##Going;
	if(RunRoutines(_old_location, after)) { action = ##Go; rtrue; }
	action = ##Go;


	if(AfterRoutines()) rtrue;
	if(keep_silent) rtrue;
	Look();
];


[ VerbName p_v ;
	! first give entry routine a chance to override
	if(PrintVerb(p_v)) return;

#IfV3;
	switch(p_v) {
		'recommencer': print "recommencer"; return;
		'sauvegarder': print "sauvegarder"; return;
                'enfiler': print "enfiler"; return;
                'verrouiller': print "verrouiller"; return;
                'deverrouiller': print "déverrouiller"; return;
                'refermer': print "refermer"; return;
                ! TODO: pour être complets, il en faudrait bien plus ;
                ! mais pour économiser de la place je n'ai mis que ceux pour qui une réponse par défaut affiche leur verbe
		'x//', 'examiner': print "examiner"; return;
		'i//', 'inventaire': print "inventaire"; return;
		'l//': print "regarder"; return;
		'z//': print "attendre"; return;
		'q//': print "quitter"; return;
		'g//': print "encore"; return;
	}
#IfNot;
	switch(p_v) {
		'x//': print "examiner"; return;
		'i//': print "inventaire"; return;
		'l//': print "regarder"; return;
		'z//': print "attendre"; return;
		'q//': print "quitter"; return;
		'g//': print "encore"; return;
	}
#EndIf;

	print (address) p_v;
];
