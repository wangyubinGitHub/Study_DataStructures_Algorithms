//
//  MusicTheory.h
//  staitstics
//
//  Created by 王玉彬 on 2019/1/16.
//  Copyright © 2019 王玉彬. All rights reserved.
//

#ifndef MusicTheory_h
#define MusicTheory_h

class MusicTheory{
public:
    
    /**
     * MIDI note number = 69.0 + 12 * log2( freq / 440.0);
     */
    static double freq_to_semitone(const double freq);
    
    static double semitone_to_freq(const double semitone);
    
};

#endif /* MusicTheory_h */
