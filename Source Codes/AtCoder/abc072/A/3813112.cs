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
            string[] input = Console.ReadLine().Split(' ');
            int X = int.Parse(input[0]);int t = int.Parse(input[1]);

            int ans = X-t;
            if(ans>0){
                Console.WriteLine(ans);
            }else{
                Console.WriteLine(0);
            }

        }
    }
}