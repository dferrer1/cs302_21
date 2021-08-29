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
	void Add_Song(string song_name, int song_time, string artist_name, string album_title, int track);
	
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
	//// variable library
	// general
	map <string, Artist> cool_mixtape;
	ifstream fin;
	string entry;
	int stime;
	
	// entry variables
	string title;
	string time, min, sec;
	string artist;
	string album;
	string genre;
	int track;

	// map iterators
	map<string, Artist>::iterator arit; // used to iterate through artists map (cool_mixtape)
	map<string, Album>::iterator alit; // used to iterate through albums map
	map<int, Song>::iterator sit; //used to iterate through songs map
	
	// read data
	//// read and open file name from command line
	string file = argv[1];
	fin.open(file);

	//// read file into stringstreams using getline in a while loop
	while(getline(fin, entry)) {
		stringstream ess(entry);
		
		// empty struct variables
		Song nsong;
		Album nalbum;
		Artist nartist;
		
		// parse entry
		ess >> title >> time >> artist >> album >> genre >> track;

		// remove underscores
		title = remove_underscore(title);
		artist = remove_underscore(artist);
		album = remove_underscore(album);

		// caculate time in seconds
		min = time.substr(0, time.find(':'));
		stime = (stoi(time.substr(0, time.find(':'))) * 60) + stoi(time.substr(time.find(':') + 1, 2));

		// debug entry
		//printf("Debug entry: %s %s %s %s %s %d; %d\n", title.c_str(), time.c_str(), artist.c_str(), album.c_str(), genre.c_str(), track, stime);
		
		// instantiate new_song parameters
		nsong.title = title;
		nsong.time = stime;
		nsong.track = track;

		// search for the artist
		arit = cool_mixtape.find(artist);
		if (arit != cool_mixtape.end()) {
		
			// artist exists, check for album
			alit = arit->second.albums.find(album);
			if (alit != arit->second.albums.end()) {
				
				// album exists, insert song in album
				alit->second.songs.insert(pair<int, Song>(track, nsong));

				// update album values
				alit->second.nsongs++;
				alit->second.time += stime;
				
				// update artist values
				arit->second.nsongs++;
				arit->second.time += stime;
			
			// the artist exists, but the album doesn't so create a new album, add the song, and add the album to the artist
			} else {
				
				// create new album and insert new song
				nalbum.name = album;
				nalbum.time = stime;
				nalbum.nsongs = 1;
				nalbum.songs.insert(pair<int, Song>(track, nsong));

				// add the album to the pre-existing artist, update artist values
				arit->second.albums.insert(pair<string, Album>(album, nalbum));
				arit->second.nsongs++;
				arit->second.time += stime;
			}

		// neither the artist or the album exist, so create both and add the new song
		} else {
				// create new album and insert new song
				nalbum.name = album;
				nalbum.time = stime;
				nalbum.nsongs = 1;
				nalbum.songs.insert(pair<int, Song>(track, nsong));
		
				// create new artist and insert new album
				nartist.name = artist;
				nartist.time = stime;
				nartist.nsongs = 1;
				nartist.albums.insert(pair<string, Album>(album, nalbum));

				// insert new artist in cool_mixtape
				cool_mixtape.insert(pair<string, Artist>(artist, nartist));
		}
	} // end of input while loop

	////// 

	// print formatted data
	for (arit = cool_mixtape.begin(); arit != cool_mixtape.end(); ++arit) {
		printf("%s: %d, %d:%02d\n", arit->second.name.c_str(), arit->second.nsongs, (arit->second.time / 60), (arit->second.time % 60));
		for (alit = arit->second.albums.begin(); alit != arit->second.albums.end(); ++alit) {
			printf("        %s: %d, %d:%02d\n", alit->second.name.c_str(), alit->second.nsongs, (alit->second.time / 60), (alit->second.time % 60));
			for (sit = alit->second.songs.begin(); sit != alit->second.songs.end(); ++sit) {
				printf("                %d. %s: %d:%02d\n", sit->second.track, sit->second.title.c_str(), (sit->second.time / 60), (sit->second.time % 60));
			} // end of song iterator for loop
		} // end of album iterator for loop
	} // end of artist for loop

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
void Mixtape::Add_Song(string title, int time, string artist, string album, int track) {
	Song nsong;
	map<string, Artist>::iterator arit;
	map<string, Album>::iterator alit;
	map<string, Song>::iterator sit;

	// instantiate new_song parameters
	nsong.title = title;
	nsong.time = time;
	nsong.track = track;

	// search for the artist
	//arit = this->artists.find(artist);
	//if (arit != this->artists.end()) {
		// 
		//alit = arit->first.find(album);

	//} else {
		
	//}

} // end of Add_Song
