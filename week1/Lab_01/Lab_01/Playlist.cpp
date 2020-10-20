#include <iostream>
#include <string>
using namespace std;

#include "Playlist.h"

//playlistNode function
PlaylistNode::PlaylistNode() {
	nextNodePtr = 0;
	uniqueID = "none";
	songName = "none";
	artistName = "none";
	songLength = 0;
}
PlaylistNode::PlaylistNode(string ID, string sName, string aName, int length)
{
	uniqueID = ID;
	songName = sName;
	artistName = aName;
	songLength = length;
	nextNodePtr = 0;
}
PlaylistNode::~PlaylistNode()
{
	delete nextNodePtr;
	delete head;
	delete tail;
}
void PlaylistNode::InsertAfter(PlaylistNode* songInsert)
{
	PlaylistNode* temp;
	temp = nextNodePtr;
	nextNodePtr = songInsert;
	songInsert->nextNodePtr = temp;
	delete temp;
}
void PlaylistNode::SetNext(PlaylistNode* nextSong) {
	nextNodePtr = nextSong;
}
string PlaylistNode::GetID() const {
	return uniqueID;
}
string PlaylistNode::GetSongName() const
{
	return songName;
}
string PlaylistNode::GetArtistName() const {
	return artistName;
}
int PlaylistNode::GetSongLength() const {
	return songLength;
}
PlaylistNode* PlaylistNode::GetNext() const {
	return nextNodePtr;
}
void PlaylistNode::PrintPlaylistNode() {
	cout << "Unique ID: " << this->uniqueID << endl;
	cout << "Song Name: " << this->songName << endl;
	cout << "Artist Name: " << this->artistName << endl;
	cout << "Song Length (in seconds): " << this->songLength << endl;
}


//playlist function
