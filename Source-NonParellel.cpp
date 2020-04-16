//Solution for 1 & 3

#include  <iostream>
#include <string>
using namespace std;

//This function can process any given 1000-digit string and works for any
//number of adjacents such as 4/6/8
void calculateEuler(string numString, int numOfAdjacents, long &product, string &final_sequence)
{
	product = 0;
	final_sequence = "";
	for (unsigned int i = 0; i < numString.size(); ++i)
	{
		long prod = 1;
		if (i + numOfAdjacents <= numString.size())
		{
			string substr = numString.substr(i, numOfAdjacents);
			string sequence = "";
			for (char num : substr)
			{
				prod *= num - '0';
				sequence += num;
				if (prod > product)
				{
					product = prod;
					final_sequence = sequence;
				}
			}
		}
	}
}

int main()
{
	string numstring = "3766581235885941622054540050228447514162777869412307699482907769113268717216818322831603491835999456015306915009196661427591452909871214219792485776087253286386945942663949956280302377388971714236415605168862773550156548824873689737766284562457836197902674997734737908387650371844408009421100914050765521827781655182806129058522352838472989652688571683680665438395803243794489830567998343203397981373552644309879795957322883020671901669290704497751685870539575543632177623725028726840870016429503564354896057020404025619555440159796686935523081354355119387766201895202371147907112778884969266539280935452003712638970422340890791962244529017494651550289995762505866212386393472458374741386036991340760970327022447106502711257671708182087831698677130077927731626466195021513131952322762659409302452718743061757527857578831917621650745174966732316231446870605534431568974878576006012026939455247174486040603096495646182217557200423380237313587369836078574982810508277521659834594761360129982400036745363";
	long product = 0;
	string final_sequence = "";
	int adjacentDigits = 8;
	calculateEuler(numstring, adjacentDigits, product, final_sequence);
	cout << endl<<"********* Finished Processing. *********"<<endl;
	cout << "Maximum Product:" << product << " | Sequence:" << final_sequence << endl;
	getchar();

	return 0;
}