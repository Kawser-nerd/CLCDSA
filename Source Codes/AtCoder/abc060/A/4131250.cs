using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{
    class Atcoderrrrrrr
    {
        static void Main(string[] args)
        {
          string[] s = Console.ReadLine().Split(' ');
          string ans = "NO";
          if(s[1].StartsWith(s[0].Substring(s[0].Length-1,1))){
              if(s[2].StartsWith(s[1].Substring(s[1].Length-1,1))){
                ans = "YES";
              }
          }
          Console.WriteLine(ans);
        }
    }
}