//
//  musicTheory_test.cpp
//  staitstics
//
//  Created by 王玉彬 on 2019/1/18.
//  Copyright © 2019 王玉彬. All rights reserved.
//

#include <assert.h>
#include <math.h>
#include "MusicTheory.h"

void musicTheoryTest(){
    assert(abs(69 - MusicTheory::freq_to_semitone(440)) < 1E-6);
    assert(abs(690.0 - MusicTheory::semitone_to_freq( MusicTheory::freq_to_semitone(690))) < 1E-6 );
}
