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

            int A = int.Parse(input[0]); int B = int.Parse(input[1]); int C = int.Parse(input[2]); int D = int.Parse(input[3]); 
        
            int L = A + B; int R = C + D;

            if (L>R){
                Console.WriteLine("Left");
            }else if ( L==R){
                Console.WriteLine("Balanced");
            }else{
                Console.WriteLine("Right");
            }
        }
    }
}