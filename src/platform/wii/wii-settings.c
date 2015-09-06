/* Copyright (c) 2015 Juan Carlos Ruvalcaba
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>

#include "wii-settings.h"

void _wiiParseArgs(int argc, char *argv[]){
	for (int i = 1; i < argc; i++){
		if (strcasecmp (argv [i], "-rom") == 0 && (i + 1 < argc) && (i + 2 < argc) && (i + 3 < argc)){
			snprintf(wiiSettings.fullRomPath, 256, "%s%s%s",argv [i+1], argv [i+2], argv [i+3]);
		}
		if (strcasecmp (argv [i], "-r") == 0 && (i + 1 < argc)){
			wiiSettings.render = atoi (argv [++i]);
		}
		if (strcasecmp (argv [i], "-video_mode") == 0 && (i + 1 < argc)){
			wiiSettings.video_mode = atoi (argv [++i]);
		}
		if (strcasecmp (argv [i], "-reduceScale") == 0 && (i + 1 < argc)){
			wiiSettings.reduceScale = atoi (argv [++i]);
		}
		if (strcasecmp (argv [i], "-useCustomInput") == 0){
			wiiSettings.useCustomInput = true;
		}
		if (strcasecmp (argv [i], "-button_A") == 0 && (i + 1 < argc)){
			snprintf(wiiSettings.buttonA, 5, "%s",argv [i+1]);
		}
		if (strcasecmp (argv [i], "-button_B") == 0 && (i + 1 < argc)){
			snprintf(wiiSettings.buttonB, 5, "%s",argv [i+1]);
		}
		if (strcasecmp (argv [i], "-button_L") == 0 && (i + 1 < argc)){
			snprintf(wiiSettings.buttonL, 5, "%s",argv [i+1]);
		}
		if (strcasecmp (argv [i], "-button_R") == 0 && (i + 1 < argc)){
			snprintf(wiiSettings.buttonR, 5, "%s",argv [i+1]);
		}
	}
	_fixInvalidSettings();
}

void _fixInvalidSettings(){
	if(!(wiiSettings.video_mode >= 0 && wiiSettings.video_mode < 7)){
		wiiSettings.video_mode = 0;
	}
	if(!(wiiSettings.render >= 0 && wiiSettings.render < 5)){
		wiiSettings.render = 1;
	}
	if(wiiSettings.reduceScale < 50 || wiiSettings.reduceScale > 100){
		wiiSettings.reduceScale = 100;
	}
	if(strcasecmp (wiiSettings.buttonA, "") == 0 || wiiSettings.buttonA == NULL){
		snprintf(wiiSettings.buttonA, 5, "%s","A");
	}
	if(strcasecmp (wiiSettings.buttonB, "") == 0 || wiiSettings.buttonB == NULL){
		snprintf(wiiSettings.buttonB, 5, "%s","B");
	}
	if(strcasecmp (wiiSettings.buttonL, "") == 0 || wiiSettings.buttonL == NULL){
		snprintf(wiiSettings.buttonL, 5, "%s","L");
	}
	if(strcasecmp (wiiSettings.buttonR, "") == 0 || wiiSettings.buttonR == NULL){
		snprintf(wiiSettings.buttonR, 5, "%s","R");
	}
}
