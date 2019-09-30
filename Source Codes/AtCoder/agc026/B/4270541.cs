using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder_Grand_Contest_026_B
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(System.Console.ReadLine());
            string[] line;
            long A, B, C, D;
            long X;

            for( int i = 0; i < T; i++)
            {
                line = Console.ReadLine().Split(' ');
                A = long.Parse(line[0]);
                B = long.Parse(line[1]);
                C = long.Parse(line[2]);
                D = long.Parse(line[3]);

                string ans = "Yes";

                if( A < B )
                {
                    ans = "No";
                }
                else if( B > D )
                {
                    ans = "No";
                }
                else if( C < (B - gcd( B, D ) + ( A % gcd( B, D ) ) ) )
                {
                    ans = "No";
                }

                Console.WriteLine(ans);

            }
            
        }

         static long gcd(long A, long B)
        {
            if (B == 0)
            {
                return A;
            }
            else
            {
                return gcd(B, A % B);
            }
            

        }
    }

}