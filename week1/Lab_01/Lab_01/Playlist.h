#include<string>
using namespace std;

class PlaylistNode {
 private:
	 string uniqueID;
	 string songName;
	 string artistName;
	 int songLength;
	 PlaylistNode* nextNodePtr;
	 PlaylistNode* head;
	 PlaylistNode* tail;
 public:
	PlaylistNode();
	PlaylistNode(string ID, string songName, string artist, int songLenth);
	~PlaylistNode();
	void InsertAfter(PlaylistNode* insertSonh);
	void SetNext(PlaylistNode* nextSong);
	string GetID() const;
	string GetSongName() const;
	string GetArtistName() const;
	int GetSongLength() const;
	PlaylistNode* GetNext() const;
	void PrintPlaylistNode();
};