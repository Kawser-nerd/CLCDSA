using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp62
{
    class Program
    {
        static void Main(string[] args)
        {
            string[]NM = Console.ReadLine().Split(' ');
            int N = int.Parse(NM[0]);
            int M = int.Parse(NM[1]);

            string[] A = new string[N];
            for (int i = 0; i < N; i++)
            {
                A[i] = Console.ReadLine();
            }

            string[] B = new string[M];
            for(int i = 0; i < M; i++)
            {
                B[i] = Console.ReadLine();
            }

            for(int n = 0; n <=N-M  ; n++)
            {
                for(int m = 0; m <= N-M; m++)
                {
                    bool maru = true;
                    for(int j = 0; j < M; j++)
                    {
                        for(int k = 0; k < M; k++)
                        {
                            if (A[n+j][m+k] != B[j][k])
                            {
                                maru = false;
                                break;
                            }
                        }
                        if (maru == false)
                        {
                            break;
                        }
                    }
                    if (maru)
                    {
                        Console.WriteLine("Yes");
                        return;
                    }
                }
            }
            Console.WriteLine("No");
            return;
        }
    }
}