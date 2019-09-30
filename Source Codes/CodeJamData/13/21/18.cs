using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj13qr
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = System.IO.File.ReadAllLines(@"C:\GCJ\A-large.in");
            int idx = 0;
            int t = int.Parse(lines[idx++]);
            TextWriter tw = new StreamWriter(@"C:\GCJ\A-large.out");
            for (int a = 0; a < t; a++)
            {
                string[] firstline = lines[idx++].Split(' ');
                int A = int.Parse(firstline[0]);
                int N = int.Parse(firstline[1]);
                List<int> motes = new List<int>();
                string[] secondline = lines[idx++].Split(' ');

                for (int i = 0; i < N; i++)
                {
                    motes.Add(int.Parse(secondline[i]));
                }
                motes.Sort();

                int curSize = A;
                int numMoves = 0;
                
                int MinSteps = N;
                if (A > 1)
                {
                    for (int i = 0; i < N; i++)
                    {
                        int numMovesInStep;
                        curSize = calc(curSize, motes[i], out numMovesInStep);
                        numMoves += numMovesInStep;
                        if (numMoves + (N - i - 1) < MinSteps)
                        {
                            MinSteps = numMoves + (N - i - 1);
                        }
                    }
                }
                tw.WriteLine("Case #{0}: {1}", a + 1, MinSteps);
            }
            tw.Close();
            //Console.ReadLine();
        }

        private static int calc(int curSize, int nextMote, out int numMovesInStep)
        {
            numMovesInStep = 0;
            while (nextMote >= curSize)
            {
                curSize += curSize - 1;
                numMovesInStep++;
            }
            return curSize + nextMote;
        }
    }
}
