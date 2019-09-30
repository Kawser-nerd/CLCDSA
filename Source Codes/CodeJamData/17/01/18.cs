using System;
using System.IO;
using System.Linq;

namespace pancakes
{
    public class Program
    {
        static void Main(string[] args)
        {

            //Console.SetIn(new StreamReader("A-large.in"));
            int cases = int.Parse(Console.ReadLine());
            for (int i = 0; i < cases; i++)
            {
                string[] tokens = Console.ReadLine().Split(new char[] {' ', '\t'});
                bool[] pancakes = tokens[0].Select(x => x == '+').ToArray();
                int k = int.Parse(tokens[1]);
                int solution = Solve(pancakes, k);
                Console.WriteLine("Case #{0}: {1}", (i+1), (solution == -1 ? "IMPOSSIBLE" : ""+solution));
            }
        }

        public static int Solve(bool[] pancakes, int k)
        {
            int steps = 0;
            for (int i = 0; i <= pancakes.Length-k; i++)
            {
                // Try to flip i though i+k-1
                if (pancakes[i] == false)
                {
                    for (int j = 0; j < k; j++)
                    {
                        pancakes[i + j] = !pancakes[i + j];                        
                    }
                    steps++;
                }
            }

            if (pancakes.All(x => x))
                return steps;
            else
                return -1;
        }
    }
}
