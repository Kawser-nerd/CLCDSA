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

            int ans = 0;
            for(int i = 1; i <= N; i++)
            {
                ans += i;
            }
            Console.WriteLine(ans);
        }
    }
}