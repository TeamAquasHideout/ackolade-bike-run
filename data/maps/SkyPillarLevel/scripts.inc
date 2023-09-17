SkyPillarLevel_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SkyPillarLevel_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SkyPillarLevel_OnFrame
	.byte 0

SkyPillarLevel_OnResume::
	special ForcePlayerOntoBike
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_SKY_PILLAR_3F
	end

SkyPillarLevel_OnFrame:
	map_script_2 VAR_TEMP_1, 0, SkyPillarLevel_EventScript_BeginCylcingRoadChallenge
	.2byte 0

SkyPillarLevel_EventScript_BeginCylcingRoadChallenge:
	special ForcePlayerOntoBike
	setvar VAR_TEMP_1, 1
	setvar VAR_BIKE_RUN, 2
	end
