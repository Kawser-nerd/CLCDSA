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
            long N = long.Parse(Console.ReadLine());
            double ans = 0;
            for (int i = 1; i <= N; i++)
            {
                double obj = Math.Pow(i,2);
                if(obj<=N){
                    ans = obj;
                }else{
                    break;
                }
            }
            Console.WriteLine(ans);
        }
    }
}