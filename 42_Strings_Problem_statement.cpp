/*
Jay and Veeru are trying to solve a problem. They have a lowercase english letter string. 
Jay is trying to take a multiple z small substring of the given string with x as start index and y as end index. 
He then tries to repeats each letter in the subsegment p times, where p is the index of the corresponding letter in the alphabet (a=1, b=2....., z=26). 
so if substring is "abc", Jay converts it to "abbccc". Veeru wants to know the length of the new string obtained by jay. 
Kindly help Veeru to find length of new string given by Jay

Input Format-
The first line contains two integers n and z (1≤n≤10^5, 1≤z≤10^5) where n is length of string and z is number of substring
The second line contains one string consisting of lowercase letters of English letters whose length is n.
Next z line contains Jay start index x and end index y of substring

Constraints-
1≤n≤10^5 1≤z≤10^5 1≤x≤y≤n

Output Format-
Print z lines: for each question print the length of the string obtained by Jay

Sample Input-
7 3
abacaba
1 3
2 5
1 7

Sample Output-
4
7
11
*/



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  string s1 = "";
  int n;
  cin >> n;
  char x;
  int queries;
  cin >> queries;
  for (int i = 0; i < n; i++) {
    cin >> x;
    s1 = s1 + x;
  }

  while (queries--) {
    int a, b;
    cin >> a >> b;
    string r= s1.substr(a-1,b-a+1);

    //cout << "String is: " << r<<"\n";
    string ans = "";
    int z = r.length();
    for (int i = 0; i < z; i++) {
      char c = r.at(i);
      int count = c - 96;
      ans = ans + string(count, c);

    }
    //cout<<ans<<endl;
    cout << ans.length() << endl;
  }
  return 0;
}