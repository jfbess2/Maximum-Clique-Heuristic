//Jacob Besse
//Spring 2015


//Heuristic for solving clique problem

//This is the basic algorithm, I did not include my future possible solutions to this problem

#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>


using namespace std;

//procedure which finds the intersecion between to list
set<int> set_intersection ( set<int>::iterator first1, set<int>::iterator last1, set<int>::iterator first2, set<int>::iterator last2)
{ set<int> result;
  while (first1!=last1 && first2!=last2)
  {
    if (*first1<*first2) ++first1;
    else if (*first2<*first1) ++first2;
    else {
		result.insert(*first1);
		++first1; ++first2;}}
  return result;
}

int main(){

	*****************This part solves the NP complete Clique Problem in Polynomial Time***************************************/

	//m is the # of vertices, n would be read in from data given to program.
	//The inputs i am using are from a minimal spanning tree project in folder cs315pa2.2or3

	int m;
	cin>> m;
	int n;
	cin>>n;
	
	//formats given data into (vertx, set of all of vertices this vertx touches including itself)
	map<int, set<int> > mymap;

	///////////////////////////////////////////////////
	///////////////////////////////////////////////////
	///////////////////////////////////////////////////
	//Map of all the intersections of set's between each vertice
	// The definition is the number of times with exact intersection occurs
	// IF THE SIZE OF THE KEY IS EQUAL TO THE DEFINITION, YOU HAVE A CLIQUE OF THAT SIZE WITH THE VERTICES IN THE KEY SET
	///////////////////////////////////////////////////
	///////////////////////////////////////////////////
	///////////////////////////////////////////////////

	map< set<int>, int> inter_map;

	//This map is a hybird between a set and a map
	//in a set the key is also the definition
	//in a map the key and definition differ
	//in a map-set, the definition must at least have the definition of the key

	for( int i = 0; i<m; i++){
		set<int> a;
		a.insert(i);
		mymap[i] = a;};

	for( int i = 0; i<n; i++){

		int value_1;
		cin>> value_1;

		int value_2;
		cin>> value_2;

		//the key is the weight... this means nothing (was dealing with mst)
		//now the key is each vertex not the weight
		//int key;
		//cin>> key;

		//value_1 should already be in map[value_1] because of first for loop

		mymap[value_1].insert(value_2);
		mymap[value_2].insert(value_1);}

	for(int i = 0; i<m-1; i++){
		for(int j = i+1; j<m; j++){
			set<int> win;
			//trying to add the intersection set between the two vertices to the win map
			win = set_intersection (mymap[i].begin(), mymap[i].end(), mymap[j].begin(), mymap[j].end());
		
			//if set is not in map add it and initate it
			if(inter_map.count(win)==0 && win.count(i)!=0)
				inter_map[win] = 2;
			else if(inter_map.count(win)!=0 && *win.begin()==i)
				++inter_map[win];
			//if set is in map just add 1 to the definition
			else;}}

		//need to add 1 to the definition at this point.
		//when this is complete if the key size == definition number then we have that size clique)
		//sort by size in map then compare if larger are in smaller... if so add to it
	//need to add if statment when map is greater than one

if(inter_map.size()>1){
	map<set<int>, int>::iterator k = inter_map.end();
	for(map<set<int>, int>::iterator i = inter_map.begin(); i != prev(k); i++){
		for(map<set<int>,int>::iterator j = next(i); j != k; j++){
			set<int> win;
			win = set_intersection (i->first.begin(), i->first.end(), j->first.begin(), j->first.end());
			if(i->first == win)
				i->second++;
			else if(j->first == win)
				j->second++;
			else{
				
			}
			//trying to add the intersection set between the two vertices to the win map
		}}}

	for(map<set<int>, int>::iterator i = inter_map.begin(); i != inter_map.end(); i++){
		if(i->first.size() == i->second){
			cout<< "We have a clique size of " << i->second<< endl;
			cout<< "The vertices included in the clique are: ";
			for(set<int>::iterator it = i->first.begin(); it != i->first.end(); it++){
				cout <<*it<<"  ";}
			cout<< endl;}}


		int ok;
		cin >> ok;

			return 0;}
