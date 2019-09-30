using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BC121D
{
    class Program
    {
        static void Main(string[] args)
        {
            // ?????
            //int a = int.Parse(Console.ReadLine());
            // ?????????????
            string[] input = Console.ReadLine().Split(' ');
            long A = long.Parse(input[0]);
            long B = long.Parse(input[1]);
            long ans = xor_fromZero(A - 1) ^ xor_fromZero(B);
            
            Console.WriteLine(ans);
        }
        public static long xor_fromZero(long n)
        {
            if (n <= 0)
                {
                    return 0;
                }
            //
            if (n % 2 == 1) // n?????
            {

                if (((n + 1) / 2) % 2 == 0)
                {
                    return 0;
                }
                else
                {
                    return 1;
                }
            }
            else // n?????
            {
                if ((n / 2)% 2 == 0){
                    return n;
                }
                else
                {
                return n+1;
                }
            }
        } 
    }
}