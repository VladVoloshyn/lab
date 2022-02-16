#include <algorithm> // sort
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <utility> // pair
using namespace std;

using Item = pair<int, double>;
using Poly = list<Item>;

void PrintPolynom(Poly* pol) {              //функція, яка друкує поліном 
	bool firstTime = true;
	for (Item& p : *pol)
	{
		if (!firstTime)
		cout << "; ";

		cout << p.first << " " << p.second;
		firstTime = false;
	}
}

void NormPolynom(Poly* pol) {				// Зведення подібних доданків
		
	auto bgn = begin(*pol);
	while (bgn != end(*pol)) 
	{
		auto p = *bgn;

		int pwr = p.first;            //присвоюємо перші значення в списку
		double cft = p.second;

		auto nxt = bgn; ++nxt;           // переходимо на наступне значення

		while (nxt != end(*pol)) {
			auto q = *nxt;                // присвоюємо q натупні значеня
			if (q.first != pwr)
				++nxt;                     //шукаємо однакові степені
			else {
				cft += q.second;
				nxt = pol->erase(nxt);    //видалення ведених елементів 
			}
	}
		if (cft == p.second)
			++bgn;
		else {
			p.second = cft;
			auto del = bgn;
			bgn = pol->insert(bgn, p); 
			pol->erase(del);;
		}
	}

	pol->sort([](Item & p1, Item & p2)				// Впорядкування по спаданню степенів
		{ return p1.first > p2.first; });
} 


Poly* GetPolynom(istream& in) 
{
	Poly* pol = new Poly;    // список
	string line, str1;
	int pwr; double cft;
	getline(in, line, '\n');   //записує дані з потоку
	istringstream elm1(line);  //рядкове введення потоку
	while (getline(elm1, str1, ';')) { 
		istringstream elm2(str1);
		elm2 >> pwr;
		elm2 >> cft;                        //присвоєння
		pol->emplace_back(make_pair(pwr, cft));
	}
	return pol;
} 

void main() 
{ 
	istringstream sin("2 5; 0 1; 1 2; 2 5; 3 4; 1 -0.5; 0 3");
	

	Poly* pol1 = new Poly;
	pol1= GetPolynom(sin);
	cout << "Origin \n";
	PrintPolynom(pol1);
	NormPolynom(pol1);
	cout << "\nNormalized \n";
	PrintPolynom(pol1);

	
}
