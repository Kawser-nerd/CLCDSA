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
            char[] inputs = Console.ReadLine().ToCharArray();;
            char X = inputs[0]; char Y = inputs[2];
            int Xint = (int)X; int Yint = (int)Y;
            if(X ==Y){
                Console.WriteLine("=");
            }else{
                Console.WriteLine(Xint>Yint ? ">":"<");
            }
        }
    }
}