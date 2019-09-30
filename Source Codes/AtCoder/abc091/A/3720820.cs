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
            string[] rawinput = Console.ReadLine().Split(' ');

            int A = int.Parse(rawinput[0]);int B = int.Parse(rawinput[1]);int C = int.Parse(rawinput[2]);

            if ((A + B) >= C){
                Console.WriteLine("Yes");
            }else{
                Console.WriteLine("No");
            }
        }
    }
}