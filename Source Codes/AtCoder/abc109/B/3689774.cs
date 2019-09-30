using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            string[] W = new string[N];
            for(int i = 0; i < N; i++)
            {
                W[i] = Console.ReadLine();
            }

            bool judge = true;
            for(int i = 1; i < N; i++)
            {
                if(W[i - 1][W[i - 1].Length - 1] != W[i][0]) judge = false;
            }
            for(int i = 0; i < N; i++)
            {
                for(int j = i + 1; j < N; j++)
                {
                    if (W[i] == W[j]) judge = false;
                }
            }

            Console.WriteLine(judge ? "Yes" : "No");
        }
    }
}