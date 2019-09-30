using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            var imp = Console.ReadLine().Split(' ');
            int N = int.Parse(imp[0]);
            int K = int.Parse(imp[1]);
            int ans = 1;
            for (int i = 0; i < N; ++i)
            {
                if(i==0)
                {
                    ans *= K;
                }
                else
                {
                    ans *= (K - 1);
                }
            }
            Console.Write(ans);

            //System.Threading.Thread.Sleep(1000);
        }
    }
}