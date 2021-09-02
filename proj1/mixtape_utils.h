#ifndef MIXTAPE_UTILS_H
#define MIXTAPE_UTILS_H

/*
Author: Diego Ferrer
Dates: 8/22/21 - 8/30/21
Collaborators: Dr. Scott Emrich, Caleb Hagens
Description: 
*/

// Provided by Dr. Emrich
struct Song { 
    string title;
    int time;  // could also be a string
    int track;
};

struct Album {
    map <int, Song > songs;
    string name;
    int time;
    int nsongs;  // optional variable but makes it easier
};

struct Artist {
    map <string, Album > albums;
    string name;
    int time;
    int nsongs;
};
//

struct Mixtape {
	map <string, Artist > mixtape;
	string title;
	int nartists;
	
	// member functions
	// add song
	// add album
	// add artist
}

#endif
