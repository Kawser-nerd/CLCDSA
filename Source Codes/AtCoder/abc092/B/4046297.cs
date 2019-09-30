using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{
    class Atcoderrrrrr
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            string[] s = Console.ReadLine().Split(' ');
            int D = int.Parse(s[0]);
            int X = int.Parse(s[1]);

            int ans = 0;
            for(int i = 1; i <= N; i++)
            {
                int tmp = int.Parse(Console.ReadLine());
                if(D%tmp !=0)
                {
                    ans += (D / tmp) + 1;
                }
                else
                {
                    ans += D / tmp;
                }
                
            }
            Console.WriteLine(ans + X);
        }
    }
}