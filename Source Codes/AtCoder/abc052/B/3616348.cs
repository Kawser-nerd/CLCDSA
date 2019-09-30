using System;
using System.Linq;

class p{
  static void Main(){
    int n = int.Parse(Console.ReadLine());
    string s = Console.ReadLine();
    int tmp = 0, ans = 0;
    for(int k = 0; k < n; k++){
      if(s[k] == 'I') tmp++;
      if(s[k] == 'D') tmp--;
      if(tmp > ans) ans = tmp;
    }
    Console.WriteLine(ans);
   }
}