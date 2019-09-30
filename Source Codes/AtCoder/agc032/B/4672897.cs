using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Grand032B
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var isEven = N % 2 == 0;
            var pairNum = isEven ? 1 + N : N;
            var a = new int[10000];
            var b = new int[10000];
            var index = 0;
            for(int i = 0;i<N-1;i++)
            {
                for(int j = i+1;j<N;j++)
                {
                    if(i+j+2 != pairNum)
                    {
                        a[index] = i + 1;
                        b[index] = j + 1;
                        index++;
                    }
                }
            }
            Console.WriteLine(index);
            for(int i=0;i<index;i++)
            {
                Console.WriteLine(a[i] + " " + b[i]);
            }
        }
    }
}