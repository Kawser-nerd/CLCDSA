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
            int N = int.Parse(s[0]);
            int M = int.Parse(s[1]);
            int X = int.Parse(s[2]);
            int Y = int.Parse(s[3]);

            int[] xs = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int[] ys = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

            string ans = "War";
            
            for(int i = X+1;i<=Y;i++){
                if(xs.Max()<i && i<=ys.Min()){
                    ans = "No War";
                }
            }
            Console.WriteLine(ans);
        }
    }
}