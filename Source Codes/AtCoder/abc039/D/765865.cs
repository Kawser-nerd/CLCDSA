using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC039_D
{
    class Program
    {
        static void Main(string[] args)
        {
            var x = getsplit();
            int H = int.Parse(x[0]);
            int W = int.Parse(x[1]);

            //A:input B:output C:check
            var A = new char[H+2, W+2];
            var B = new char[H + 2, W + 2];
            var C = new char[H + 2, W + 2];

            for (int i = 0; i < H+2; i++)
            {
                for (int j = 0; j < W+2; j++)
                {
                    A[i, j] = '#';
                    B[i, j] = '.';
                    C[i, j] = '#';
                }
            }
            for (int i = 1; i < H+1; i++)
            {
                string s = Console.ReadLine();

                for (int j = 1; j < W+1; j++)
                {
                    A[i, j] = s[j - 1]; 
                }
            }
            for (int i = 1; i < H+1; i++)
            {
                for (int j = 1; j < W + 1; j++)
                {
                    if (A[i, j] == '#' && A[i - 1, j] == '#' &&
                        A[i - 1, j - 1] == '#' && A[i, j - 1] == '#' &&
                        A[i + 1, j + 1] == '#' && A[i + 1, j] == '#' &&
                        A[i + 1, j - 1] == '#' && A[i, j + 1] == '#' &&
                        A[i - 1, j + 1] == '#')
                    {
                        B[i, j] = '#';
                    }
                }
            }

            for (int i = 1; i < H+1; i++)
            {
                for (int j = 1; j < W+1; j++)
                {
                    if (B[i, j] == '.' && B[i - 1, j] == '.' &&
                        B[i - 1, j - 1] == '.' && B[i, j - 1] == '.' &&
                        B[i + 1, j + 1] == '.' && B[i + 1, j] == '.' &&
                        B[i + 1, j - 1] == '.' && B[i, j + 1] == '.' &&
                        B[i - 1, j + 1] == '.')
                    {
                        C[i, j] = '.';
                    }
                }
            }

            if (check(A,C,H,W))
            {
                var sb = new StringBuilder();
                sb.AppendLine("possible");
                for (int i = 1; i < H+1; i++)
                {
                    for (int j = 1; j < W+1; j++)
                    {
                        sb.Append(B[i, j]);
                    }
                    sb.AppendLine();
                }
                Console.Write(sb);
            }
            else
            {
                Console.WriteLine("impossible");
            }
        }
        static bool check(char[,] A,char[,] C,int H, int W)
        {
            for (int i = 1; i < H + 1; i++)
            {
                for (int j = 1; j < W + 1; j++)
                {
                    if (A[i, j] != C[i, j])
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        public static string[] getsplit()
        {
            string[] x = Console.ReadLine().Split(' ');
            return x;
        }
        public static int getint()
        {
            int x = int.Parse(Console.ReadLine());
            return x;
        }
    }
}