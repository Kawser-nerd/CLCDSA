using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace Atcoder
{
    class aaaa
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int a = int.Parse(input[0]);int b = int.Parse(input[1]);

            if ((a + b) % 2 == 0){
                Console.WriteLine((a+b) / 2 );
            }else{
                Console.WriteLine((a+b)/2 +1);
            }
        }
    }
}