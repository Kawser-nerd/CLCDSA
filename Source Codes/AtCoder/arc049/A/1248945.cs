using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC049Emphasis
{
    class Program
    {
        static void Main(string[] args)
        {
            string S = Console.ReadLine();
            int[] A = new int[4];
            string[] vals = Console.ReadLine().Split(' ');
            for (int i = 0; i < 4; i++)
                A[i] = int.Parse(vals[i]);
            
            for(int i=0; i < S.Length; i++)
            {
                for(int j=0; j < 4; j++)
                {
                    if(A[j] == i)
                    {
                        Console.Write("\"");
                        break;
                    }
                }
                Console.Write(S[i]);
            }

            for(int j=0; j < 4; j++)
            {
                if(A[j] == S.Length)
                {
                    Console.Write("\"");
                    break;
                }
            }

            Console.WriteLine();

        }
    }
}