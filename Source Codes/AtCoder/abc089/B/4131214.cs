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
          int N = int.Parse(Console.ReadLine());
          string[] s = Console.ReadLine().Split(' ');
          int ans = 0;
          for (int i = 0; i <N; i++)
          {
              if(s[i] == "Y"){
                  ans++;
                  break;
              }
          }
          Console.WriteLine(ans ==0?"Three":"Four");
        }
    }
}