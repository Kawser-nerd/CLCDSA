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
            int[] s = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            if(s[0]+s[1]>=10){
                Console.WriteLine("error");
            }else{
                Console.WriteLine(s[0]+s[1]);
            }
        }
    }
}