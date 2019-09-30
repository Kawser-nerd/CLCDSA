using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC003SimplifiedMahjong
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int[] A = new int[N + 1];
            long numPairs = 0;
            long numCards = 0;

            for (int i=1; i <= N; i++)
            {
                A[i] = int.Parse(Console.ReadLine());
            }

            for(int i=1; i <= N; i++)
            {
                if(A[i] == 0)
                {
                    numPairs += numCards / 2;
                    numCards = 0;
                }
                else
                {
                    numCards += A[i];
                }
            }

            numPairs += numCards / 2;

            Console.WriteLine(numPairs);
        }
    }
}