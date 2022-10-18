#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int SPrefix(string str, string term)
{
    int index;
    index = str.rfind(term);
    return index;
}

vector<string> sortRegister(vector<string> registro){

    sort(registro.begin(), registro.end(), [](string a, string b){
      
      string point;
		  size_t position = 0;
		  string mark_delimiter = "-";

      // 
      vector<string> compare_a;
      vector<string> compare_b;
      
		  while ((position = a.find(mark_delimiter)) != string::npos) {
			  point = a.substr(0, position);
			  compare_a.push_back(point);
			  a.erase(0, position + mark_delimiter.length());
		  }
		  compare_a.push_back(a);
      
		  while ((position = b.find(mark_delimiter)) != string::npos) {
			  point = b.substr(0, position);
			  compare_b.push_back(point);
			  b.erase(0, position + mark_delimiter.length());
		  }
      
		  compare_b.push_back(b);
		  return pair<string, string>(compare_a[1], compare_a[0]) < 
		  pair<string, string>(compare_b[1], compare_b[0]); 
    });
  
    return registro;
}