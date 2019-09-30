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
            int K = int.Parse(Console.ReadLine());
            double ans = double.MaxValue;
            for (int i = 0; i <= N; i++)
            {
                for (int j = 0; j <= N; j++)
                {
                    if(i + j ==N){
                        double obj = Math.Pow(2,i) + (K * j);
                        if (ans>obj)
                        {
                            ans = obj;
                        }
                    }
                }
            }
            Console.WriteLine(ans);
        }
    }
}