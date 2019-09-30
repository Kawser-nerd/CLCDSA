using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());

            for (int i = 0; i < T; i++)
            {

                Console.WriteLine("Case #{0}: {1}", i + 1, new Solver().Solve());
            }
        }
    }

    class Solver
    {



        public string Solve()
        {
            var an = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
            
            var A = an[0];
            var N = an[1];
            var motes = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).OrderBy(x => x).ToList();

            EatAll(motes, ref A);

            int upTo = motes.Count;
            int minMoves = upTo;
            for (int i = 0; i < upTo; i++)
            {
                A += A - 1;


                EatAll(motes, ref A);

                minMoves = Math.Min(minMoves, i+1+motes.Count);
            }

            return minMoves.ToString();
        }

        void EatAll(List<long> motes, ref long A)
        {
            int i;
            for (i = 0; i < motes.Count; i++)
            {
                var x = motes[i];
                if (x < A)
                    A += x;
                else
                {
                    break;
                }
            }
            if (i > 0)
                motes.RemoveRange(0, i);
        }

    }
}
