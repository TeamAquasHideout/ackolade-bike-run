BikePathLevel_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BikePathLevel_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BikePathLevel_OnFrame
	.byte 0

BikePathLevel_OnTransition::
	special ForcePlayerOntoBike
	end

BikePathLevel_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BikePathLevel_EventScript_BeginCylcingRoadChallenge
	.2byte 0

BikePathLevel_EventScript_BeginCylcingRoadChallenge:
	special ForcePlayerOntoBike
	setvar VAR_TEMP_1, 1
	setvar VAR_BIKE_RUN, 0
	call_if_unset FLAG_UNUSED_0x021, BikeLevelNotifyBulletTime
	end

BikeLevelNotifyBulletTime:
	lockall
	msgbox BikeLevelBulletText, MSGBOX_DEFAULT
	waitbuttonpress
	setflag FLAG_UNUSED_0x021
	releaseall
	closemessage
	return

BikeLevelBulletText:
	.string "Welcome to the Mach-Bike Race!\p"
	.string "Good Luck, and try not to rage.$"
WarpToNextMap::
	special WarpBikeRun
	end
