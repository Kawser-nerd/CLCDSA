using System;
using System.Linq;

namespace A___Sharing_Cookies
{
    class Program
    {
        static void Main(string[] args)
        {
            var A_B = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int A = A_B[0], B = A_B[1];

            Console.WriteLine(((A + B) % 3  == 0| A % 3 == 0| B % 3 == 0) ? "Possible" : "Impossible");
        }
    }
}