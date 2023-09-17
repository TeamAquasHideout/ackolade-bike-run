FortreeLevel_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, FortreeLevel_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FortreeLevel_OnFrame
	.byte 0

FortreeLevel_OnTransition::
	special ForcePlayerOntoBike
	end

FortreeLevel_OnFrame:
	map_script_2 VAR_TEMP_1, 0, FortreeLevel_EventScript_BeginCylcingRoadChallenge
	.2byte 0

FortreeLevel_EventScript_BeginCylcingRoadChallenge:
	special ForcePlayerOntoBike
	setvar VAR_TEMP_1, 1
	setvar VAR_BIKE_RUN, 1
	call_if_unset FLAG_UNUSED_0x020, SkyPillarNotifyBulletTime
	end

SkyPillarNotifyBulletTime:
	lockall
	msgbox SkyPillarBulletText, MSGBOX_DEFAULT
	waitbuttonpress
	setflag FLAG_UNUSED_0x020
	special SetBulletTime
	releaseall
	closemessage
	return

SkyPillarBulletText:
	.string "You have unlocked Bullet Time!.\p"
	.string "Hold R to slow time around you.$"
