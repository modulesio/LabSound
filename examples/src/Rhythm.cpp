

#include "LabSoundIncludes.h"

#include "Rhythm.h"

using namespace LabSound;

void rhythm(RefPtr<AudioContext> context, float seconds)
{
    //--------------------------------------------------------------
    // Play a rhythm
    //
    SoundBuffer kick(context, "kick.wav");
    SoundBuffer hihat(context, "hihat.wav");
    SoundBuffer snare(context, "snare.wav");
    
    float startTime = 0;
    float eighthNoteTime = 1.0f/4.0f;
    for (int bar = 0; bar < 2; bar++) {
        float time = startTime + bar * 8 * eighthNoteTime;
        // Play the bass (kick) drum on beats 1, 5
        kick.play(time);
        kick.play(time + 4 * eighthNoteTime);
        
        // Play the snare drum on beats 3, 7
        snare.play(time + 2 * eighthNoteTime);
        snare.play(time + 6 * eighthNoteTime);
        
        // Play the hi-hat every eighth note.
        for (int i = 0; i < 8; ++i) {
            hihat.play(time + i * eighthNoteTime);
        }
    }
    while (seconds > 0) {
        seconds -= 0.01f;
        usleep(10000);
    }
}
