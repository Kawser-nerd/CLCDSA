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
            int N = int.Parse(Console.ReadLine());
            int A = int.Parse(Console.ReadLine());

            int amari = N % 500;
            
            if ( amari <= A ){
                Console.WriteLine("Yes");
            }else{
                Console.WriteLine("No");
            }

        }
    }
}