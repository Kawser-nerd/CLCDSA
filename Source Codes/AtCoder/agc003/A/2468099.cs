using System;
using System.Linq;
class Program{
    static void Main(){
       char[] s = Console.ReadLine().ToCharArray();
       bool f = true;
       int n = s.Count(p => p == 'N');
       int so = s.Count(p => p == 'S');
       int e = s.Count(p => p == 'E');
       int w = s.Count(p => p == 'W');
       f = f && ((n == 0 && so == 0) || (n != 0 && so != 0)) && ((e == 0 && w == 0) || (e != 0 && w != 0));
      string ans = f ? "Yes" : "No";
      Console.WriteLine(ans);
    }
}