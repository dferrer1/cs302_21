/*
Author: Diego Ferrer
Dates: 8/22/21 - 8/30/21
Collaborators: Caleb Hagens
Description: This is the main file for the first project that I had to do for CS302. 
			 The assignment involves taking a formatted text file in(using the command line to determine the name of the file),
			 change the formatting, and print the info taken in with a set format.
			 Ex:
			 UNIX> lib_info Small.txt
			 Coltrane, John: 4, 18:37
					Giant Steps: 4, 18:37
							1. Giant Steps: 4:46
							3. Countdown: 2:25
							6. Naima: 4:24
							7. Mr. P.C.: 7:02
			 Lyle, Bobby: 1, 5:16
					Night Breeze: 1, 5:16
							5. Naima: 5:16
			 Puente, Tito: 1, 4:02
					El Rey: 1, 4:02
							5. Giant Steps: 4:02
			 Tjader, Cal: 1, 5:36
					A Fuego Vivo: 1, 5:36
							6. Naima: 5:36
			 Walton, Cedar: 4, 30:44
					Eastern Rebellion: 1, 8:38
							2. Naima: 8:38
					Naima: 3, 22:06
							2. This Guy's In Love With You: 8:10
							4. Down In Brazil: 6:07
							6. Naima: 7:49
*/
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

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
    map <string, Artist > artists;
    int nartists;

	// Create_Song: no return; takes the name of the song, song running time, the artist's name, the album title, and the track of the album its in
	//			 declares and builds a Song object; 
	//			 checks if the artist already exists in the Mixtape;
	//				if yes:
	//					checks if the album exists in the Artist;
	//						if yes:
	//							| saves the location of the album
	//						if no:
	//							| calls Add_Album
	//							| saves the location of the new album
	//				if no:
	//					| calls Add_Artist
	//					| calls Add_Album
	//			 	
	//			 adds the song object to the Album,
	//			 increments the Album song count,
	//			 updates the Album song time,
	//			 increments the Artist song count,
	//			 updates the Artist song time
	void Add_Song(string song_name, string song_time, string artist_name, string album_title, string track);
	
	// Song Add_Song

	// Add_Album: no return
	//			  
	void Add_Album(string fsong, string album_title, int fsong_time);
	
	// Add_Artist: no return; takes the name of the artist and the Artist struct
	void Add_Artist(string fartist, string artist_name, int fsong_time);
	
	// print song
	// print album
	// print artist
	// print mixtape
};

// remove_underscore: returns a string; takes a string
//					  runs replace on a string until all underscores have been replaced with spaces
string remove_underscore(string a);

int main(int argc, char* argv[]) {
	// variable library
	Mixtape cool_mixtape;
	ifstream fin;
	string entry;
	
	string title;
	string time;
	string artist;
	string album;
	string genre;
	string track;

	// read data
	//// read and open file name from command line
	string file = argv[1];
	fin.open(file);

	//// read file into stringstreams using getline in a while loop
	while(getline(fin, entry)) {
		stringstream ess(entry);
		
		// parse entry
		ess >> title >> time >> artist >> album >> genre >> track;

		// remove underscores
		title = remove_underscore(title);
		artist = remove_underscore(artist);
		album = remove_underscore(album);

		// debug entry
		printf("Debug entry: %s %s %s %s %s %s\n", title.c_str(), time.c_str(), artist.c_str(), album.c_str(), genre.c_str(), track.c_str());
		
		// call Add_Song
		cool_mixtape.Add_Song(title, time, artist, album, track);
		
	} // end of input while loop

	////// 

	// print formatted data


} // end of main

// remove_underscore: returns a string; takes a string
//					  runs replace on a string until all underscores have been replaced with spaces
string remove_underscore(string a) {
	int fus;

	// replace each underscore with a space until they have all been replaced
	while ((fus = a.find('_')) != string::npos) { // Condition Source: https://www.techiedelight.com/replace-occurrences-character-string-cpp/
		a.replace(fus, 1, " ");
	}

	return a;
} // end of remove_underscore


void Mixtape::Add_Song(string title, string time, string artist, string album, string track) {
	
} // end of Add_Song
