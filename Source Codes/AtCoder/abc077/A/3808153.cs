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
            string input1 = Console.ReadLine();
            string input2 = Console.ReadLine();

            if (input1[0] == input2[2] && input1[1] == input2[1] && input1[2] == input2[0]){
                Console.WriteLine("YES");
            }else{
                Console.WriteLine("NO");
            }
        }
    }
}