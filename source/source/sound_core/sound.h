#define		SOUND_MP3	0
#define		SOUND_OGG	1
#define		SOUND_SFX	2

typedef struct
{
	int		id;				// Unique id
	int		sound_type;	
	int		sound_voice;
	int		sound_volume;
	int		sound_time;
	u8	*	sound_buffer;
}	sndCore_sound;

sndCore_sound** soundMatrix;
int				soundMatrix_sounds;
