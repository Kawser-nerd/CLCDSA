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
            int A = int.Parse(input[0]);int B = int.Parse(input[1]);

            string ans = "Impossible";
            if(A%3 ==0){
                ans ="Possible";
            }else if(B%3 ==0){
                ans = "Possible";
            }else if ((A+B) %3 ==0){
                ans = "Possible";
            }
            Console.WriteLine(ans);
        }
    }
}