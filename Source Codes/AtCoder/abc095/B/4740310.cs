using System;
using System.Linq;

namespace WA055B
{
    class Program
    {
        static void Main(string[] args)
        {
            var line = Console.ReadLine().Split(' ').ToArray();

            var N = int.Parse(line[0]); var X = int.Parse(line[1]);

            int[] m = new int[N];

            int total = 0;

            for(var i = 0; i < N; i++)
            {
                m[i] = int.Parse(Console.ReadLine());

                total += m[i];
            }

            X -= total;

            Array.Sort(m);

            Console.WriteLine(N + (X / m[0]));
            
        }
    }
}