CaveLevel_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CaveLevel_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveLevel_OnFrame
	.byte 0

CaveLevel_OnTransition::
	special ForcePlayerOntoBike
	end

CaveLevel_OnFrame:
	map_script_2 VAR_TEMP_1, 0, CaveLevel_EventScript_BeginCylcingRoadChallenge
	.2byte 0

CaveLevel_EventScript_BeginCylcingRoadChallenge:
	special ForcePlayerOntoBike
	setvar VAR_TEMP_1, 1
	setvar VAR_BIKE_RUN, 3
	end
