using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder_Grand_Contest_026
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(System.Console.ReadLine());
            string[] a = System.Console.ReadLine().Split(' ');
            int X = 0;

            for (int i = 0; i < N-1; i++)
            {
                if(a[i] == a[i+1])
                {
                    X = X + 1;
                    i++;
                }
            }
            System.Console.Write(X);
        }
    }
}