//
//  MusicTheory.cpp
//  staitstics
//
//  Created by 王玉彬 on 2019/1/16.
//  Copyright © 2019 王玉彬. All rights reserved.
//

#include "MusicTheory.h"
#include <cmath>

/**
 * MIDI note number = 69.0 + 12 * log2( freq / 440.0);
 */

double MusicTheory::semitone_to_freq(const double semitone) {
    return pow( 2 , ((semitone - 69.0) / 12.0) ) * 440.0;
}


double MusicTheory::freq_to_semitone(const double freq) {
    return 69.0 + 12 * log2( freq / 440.0);;
}
