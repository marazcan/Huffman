#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Dugum{
	public:
		char karakter;
		int frekans;	// Dosyada kaç kez tekrarlandığı
		string kod; 	// 01 kod karşılığı
		Dugum* sol;
		Dugum* sag;
		Dugum(char kr,int frek, Dugum* sl=NULL,Dugum *sg=NULL){
			karakter=kr;
			frekans=frek;
			sol=sl;
			sag=sg;
			kod="";
		}
		bool Yaprakmi() const{
			if(sol == NULL && sag == NULL) return true;
			return false;
		}
		bool operator==(Dugum& sag){
			if(this->karakter == sag.karakter) return true;
			else return false;
		}
		bool operator!=(Dugum& sag){
			if(this->karakter != sag.karakter) return true;
			else return false;
		}
		bool operator>(Dugum& sag){
			if(this->frekans > sag.frekans) return true;
			else return false;
		}
};
class Huffman{
	private:
		int harfler;  			// harflerin ASCII karşılıkları
		string girdi;			// dosyadan okunan girdi
		Dugum *root;
				
		Dugum* AgacOlustur(int frek[]);
		void KodOlustur(Dugum*,string);
		int MinDugumIndeks(Dugum* dugumler[]);
		void DosyaOku(string)throw(string);
		Dugum* Kok();
		void inorder(Dugum*);
		void SilSolDugum(Dugum*);
		void SilSagDugum(Dugum*);
	public:
		Huffman(string)throw(string);
		void Kodla();
		friend ostream& operator<<(ostream&,Huffman&);
		~Huffman();
};


#endif