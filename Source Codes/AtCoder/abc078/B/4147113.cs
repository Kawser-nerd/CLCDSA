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
            int X = int.Parse(s[0]);
            int Y = int.Parse(s[1]);
            int Z = int.Parse(s[2]);

            int ans = 0;
            for (int i = 0; X>=0; i++)
            {
                if (i == 0)
                {
                    X -= Z;
                }
                X -= (Y + Z);
                if(X>=0){
                    ans++;
                }
            }
            Console.WriteLine(ans);
        }
    }
}