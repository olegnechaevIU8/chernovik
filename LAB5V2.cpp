#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
vector<File> list;

class File {
	string name;
	int data;
public:
	
	File() {
		name = "def";
		data = 0;
	}
	File(string fname, int fdata) {
		name = fname;
		data = fdata;
	}
	~File() {
		cout << "dctor"; 
	}
	void setName(string fname) {
		name = fname;
	}
	
	string getName() {
		return name;
	}
	
	void setData(int fdata) {
		data = fdata;
	}
	
	int getData() {
		return data;
	}
};

class Directory {
	string name;
	vector<Directory> dir;
	vector<File> files;
public:
	Directory() {
		name = "def";
	}

	~Directory() {
		files.clear();
		dir.clear();
	}

	Directory(string dname) {
		name = dname;
	}

	void pushFile(File &file) {
		files.push_back(file);
	}

	void deleteFile(string fname) {
		int i = 0;
		for (File k : files) {
			if (k.getName() == fname) {
				files.erase(files.begin() + i);
				break;
			}
			i++;
		}
	}

	void deleteDirect(Directory& direct) {
		files.clear();
		for (Directory k : dir) {
			k.deleteDirect(k);
		}
		dir.clear();
	}

	void deleteDirect(string dname) {
		for (Directory k : dir) {
			if (k.getName() == dname) {
				k.deleteDirect(k);
				break;
			}
		}
	}
	
	void printDirect() {

		cout << "Directories: " << endl;
		for (Directory k : dir) {
			cout << k.getName() << endl;
		}
		cout << "Files: " << endl;
		for (File k : files) {
			cout << k.getName() << endl;
		}
	}

	void printFile() {
		for (File k : files) {
			cout << k.getName();
		}
	}

	void pushDirect(Directory &directory) {
		dir.push_back(directory);
	}
	
	string getName() {
		return name;
	}

	void searchFile(string fname, Directory& direct) {

		for (File k : files) {
			if (k.getName() == fname)
				list.push_back(k);
		}

		for (Directory k : dir) {
			k.searchF(fname, k);
		}
	}
	
	friend ostream &operator<<(ostream &stream, Directory obj);
};


ostream &operator<<(ostream &stream, Directory obj) {
	stream << obj.name;
	return stream;
}


int main() {
	return 0;
}
