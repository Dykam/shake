#include <stdio.h>
#include <asndlib.h>
#include <mp3player.h>
#include "oggplayer.h"
#include "music.h"

void initialize_sound_system ()
{
	ASND_Init();
	MP3Player_Init();
	
	soundMatrix_sounds = 0;
	
	soundMatrix = (sndCore_sound *)malloc(sizeof(sndCore_sound) * soundMatrix_sounds);
}

int sndMatrix_add_sound_from_file (const char filename[255])
{
	FILE * 	sound_file;
	int		sound_file_size;
	
	sound_file = fopen (filename, "rb");
	fseek(sound_file, 0, SEEK_END);
	sound_file_size = ftell(sound_file);
	rewind(sound_file);
	
	//	Add a new entry in the matrix and make some space for it
	
	++soundMatrix_sounds;
	soundMatrix = (sndCore_sound **)realloc(soundMatrix, sizeof(sndCore_sound*) * soundMatrix_sounds);

	//	Allocate some space for the sound buffer

	soundMatrix[0][soundMatrix_sounds]->sound_buffer = (u8 *)malloc(sizeof(u8) * sound_file_size);
	
	//	Fill the sndCore_sound structure
	
	soundMatrix[0][soundMatrix_sounds]->id					= 666;
	soundMatrix[0][soundMatrix_sounds]->sound_type			= SOUND_MP3;
	if (soundMatrix[0][soundMatrix_sounds]->sound_type	== SOUND_SFX)
		soundMatrix[0][soundMatrix_sounds]->sound_voice 	= ASND_GetFirstUnusedVoice();
	soundMatrix[0][soundMatrix_sounds]->sound_volume		= 100;
	soundMatrix[0][soundMatrix_sounds]->sound_time			= 0;
	
	fread(soundMatrix[0][soundMatrix_sounds]->sound_buffer, 1, sound_file_size, sound_file);
	
	fclose(sound_file);
	
	return soundMatrix[0][soundMatrix_sounds]->id;
}

int sndMatrix_add_sound_from_buffer (const u8 * sound_buffer)
	//	Add a new entry in the matrix and make some space for it
	
	++soundMatrix_sounds;
	soundMatrix = (sndCore_sound **)realloc(soundMatrix, sizeof(sndCore_sound*) * soundMatrix_sounds);

	//	Allocate some space for the sound buffer

	soundMatrix[0][soundMatrix_sounds]->sound_buffer = (u8 *)malloc(sizeof(u8) * sizeof(sound_buffer));
	
	//	Fill the sndCore_sound structure
	
	soundMatrix[0][soundMatrix_sounds]->id					= 666;
	soundMatrix[0][soundMatrix_sounds]->sound_type			= SOUND_MP3;
	if (soundMatrix[0][soundMatrix_sounds]->sound_type	== SOUND_SFX)
		soundMatrix[0][soundMatrix_sounds]->sound_voice 	= ASND_GetFirstUnusedVoice();
	soundMatrix[0][soundMatrix_sounds]->sound_volume		= 100;
	soundMatrix[0][soundMatrix_sounds]->sound_time			= 0;
	
	memcpy(soundMatrix[0][soundMatrix_sounds]->sound_buffer, sound_buffer, sizeof(u8) * sizeof(sound_buffer));

	return soundMatrix[0][soundMatrix_sounds]->id;
}

void sndMatrix_remove_sound_from_id (u8 id)
{
	--soundMatrix_sounds;
	int skipped = 0;
	sndCore_sound** newSoundMatrix = (sndCore_sound **)alloc(sizeof(sndCore_sound*) * soundMatrix_sounds);
	for(int = 0; i < soundMatrix_sounds; i++) {
		if(soundMatrix[i][0]->id != id) {
			newSoundMatrix[i][0] = soundMatrix[i + skipped][0];
			++skipped;
		} else {		
			dealloc(soundMatrix[i + skipped]);
		}
	}
	dealloc(soundMatrix);
	soundMatrix = newSoundMatrix;
}

int sndMatrix_play_sound (int sound_id)
{
	int sound = 1;
	sndCore_sound* c_sound;
	
	for ( sound ; sound < soundMatrix_sounds ; sound ++ )
	{
		if (soundMatrix[0][sound]->id == sound_id)
		{
			c_sound = soundMatrix[0][sound];
			break;
		}
	}
	
	switch (c_sound->sound_type)
	{
		case SOUND_SFX :
			if (!c_sound->sound_time)
			{
				ASND_AddVoice(c_sound->sound_voice, c_sound->sound_buffer, sizeof(c_sound->sound_buffer) * sizeof(u8));
			} else {
				ASND_PauseVoice(c_sound->sound_voice, 0)
			}
		case SOUND_MP3 :
			MP3Player_PlayBuffer(c_sound->sound_buffer, sizeof(c_sound->sound_buffer) * sizeof(u8), NULL);
		case SOUND_OGG :
			if (!c_sound->sound_time)
			{
				PauseOgg(0);
			} else {
				PlayOgg(mem_open(c_sound->sound_buffer, , sizeof(c_sound->sound_buffer) * sizeof(u8)), 0, OGG_ONE_TIME);
			}
	}
}

int sndMatrix_stop_sound (int sound_id)
{
	int sound = 1;
	sndCore_sound* c_sound;
	
	for ( sound ; sound < soundMatrix_sounds ; sound ++ )
	{
		if (soundMatrix[0][sound]->id == sound_id)
		{
			c_sound = soundMatrix[0][sound];
			break;
		}
	}
	
	switch (c_sound->sound_type)
	{
		case SOUND_SFX :
			ASND_StopVoice(c_sound->sound_voice);
			c_sound->sound_time = 0;
		case SOUND_MP3 :
			MP3Player_Stop();
			c_sound->sound_time = 0;
		case SOUND_OGG :
			StopOgg();
			c_sound->sound_time = 0;
	}
}
			

