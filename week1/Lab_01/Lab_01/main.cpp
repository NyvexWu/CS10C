

#include <iostream>
#include "Playlist.h"

using namespace std;
void printMenu(string);
void functions(char, string);
int main()
{
    string playlistTitle;
    cout << "Enter playlist's title:" << endl;
	cout << endl;
    getline(cin, playlistTitle);
    printMenu(playlistTitle);
}

void printMenu(string title) {
	char option;
	cout << title << " PLAYLIST MENU" << endl;
	cout << "a - Add song" << endl;
	cout << "d - Remove song" << endl;
	cout << "c - Change position of song" << endl;
	cout << "s - Output songs by specific artist" << endl;
	cout << "t - Output total time of playlist (in seconds)" << endl;
	cout << "o - Output full playlist" << endl;
	cout << "q - Quit" << endl;
	cout << endl;
	cout << "Choose an option:" << endl;
	cin >> option;
	functions(option, title);
}
void functions(char choice,string title) {
	PlaylistNode* head = 0;
	PlaylistNode* tail = 0;
	PlaylistNode* location =0;
	string songID;
	string sName;
	string aName;
	int sLength;
	PlaylistNode* temp =0;
	if (choice == 'q') {
	}
	else if (choice == 'a')
	{
		cout << "ADD SONG" << endl;
		cout << "Enter song's unique ID:" << endl;
		cin.ignore();
		getline(cin, songID);
		cout << "Enter song's name:" << endl;
		getline(cin, sName);
		cout << "Enter artist's name:" << endl;
		getline(cin, aName);
		cout << "Enter song's length (in seconds):" << endl;
		cin.ignore();
		cin >> sLength;
		PlaylistNode* newSong = new PlaylistNode(songID, sName, aName, sLength);
		if (head == 0)
		{
			head = newSong;
			tail = newSong;
		}
		else {
			tail->InsertAfter(newSong);
			tail = newSong;	
		}
		cout << endl;
		printMenu(title);
	}
	else if (choice == 'd') {
		location = head;
		cout << "REMOVE SONG" << endl;
		cout << "Enter song's unique ID:" << endl;
		getline(cin, songID);
		if (head == 0)
		{
			cout << "Playlist is empty" << endl;
		}
		while (location != 0)
		{
			if (location->GetID() == songID)
			{
				sName = location->GetSongName();
				if (head == location)
				{
					if (head == tail)
					{
						tail = 0;
					}
					temp = head;
					head = location->GetNext();
					delete temp;
					location = head;
					temp = location;
				}
				else {
					if (tail == location)
					{
						tail = location;
					}
					temp->SetNext(location->GetNext());
					delete location;
					location = temp;
					location = location->GetNext();
				}
				  cout << "\"" << sName << "\" removed." << endl;
			}
			else {
				temp = location;
				location = location->GetNext();
			}
		}
		printMenu(title);
	}
	else if (choice == 'c') {
		location = head;
		temp = head;
		int sLocation;
		int nLocation;
		cout << "CHANGE POSITION OF SONG" << endl;
		cout << "Enter song's current position:";
		cin >> sLocation;
		cout << "Enter new position for song:" << endl;
		cin >> nLocation;
		int i = 1;
		while (i < sLocation)
		{
			temp = location;
			location = location->GetNext();
		}
		sName = location->GetSongName();
		if (head == location)
		{
			head = location->GetNext();
		}
		else if (tail == location)
		{
			temp->SetNext(tail->GetNext());
			tail = temp;
		}
		else
		{
			temp->SetNext(location->GetNext());
		}
		i = 2;
		while (i < sLocation)
		{
			temp = temp->GetNext();
			i = i + 1;
		}
		if (sLocation <= 1)
		{
			location->SetNext(head);
			head = location;
		}
		else if (sLocation > (sLocation - 1))
		{
			tail = location;
			temp->InsertAfter(location);
		}
		cout << "\"" << sName << "\" moved to position " << sLocation << endl;
		printMenu(title);
	}
	else if (choice == 's') {
		cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
		cout << "Enter artist's name:";
		getline(cin, aName);
		location = head;
		int i = 1;
		if (head == 0)
		{
			cout << "Playlist is empty" << endl;
		}
		else {
			while (location != 0)
			{
				if (location->GetArtistName() == aName)
				{
					cout << i << "." << endl;
					location->PrintPlaylistNode();
					cout << endl;
				}
				i = i + 1;
				location = location->GetNext();
			}
		}
		printMenu(title);
		cout << endl;
	}
	else if (choice == 't') {
		location = head;
		int time = 0;
		for (location = head; location != 0; location = location->GetNext()) {
			time = time + location->GetSongLength();
		}
		cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
		cout << "Total time: " << time << " seconds" << endl;
		printMenu(title);
	}
	else if (choice == 'o' || choice == 'O') {
	    cout << title << " - OUTPUT FULL PLAYLIST" << endl;
		PlaylistNode* location = head;
		if (head == 0)
		{
			cout << "Playlist is empty" << endl;
		}
		else {
			int num =1;
			for (PlaylistNode* i = head; i != NULL; i = i->GetNext()) {
				cout << num << "." << endl;
				i->PrintPlaylistNode();
				if (i->GetNext() != NULL) {
					cout << endl;
				}
				++num;
			}
		}
		cout << endl;
		printMenu(title);
	}
	else {
		cout << "The choice you entered does not exist" << endl;
		cout << "Please try again" << endl;
		cout << endl;
		printMenu(title);
	}
}