using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader("C-small-attempt2.in"))
            {
                using (StreamWriter sw = new StreamWriter("C-small-practice111.out"))
                {
                    SolveIt(sr, sw);
                }
            }
        }

        private static void SolveIt(StreamReader sr, StreamWriter sw)
        {
            int T = int.Parse(sr.ReadLine());
            for (int t = 0; t < T; t++)
            {
                Console.WriteLine("Doing {0}", t);
                var splitted = sr.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                int C = splitted[0];
                int D = splitted[1];
                int V = splitted[2];
                int[] denom = sr.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();

                bool[] vTest = new bool[V + 1];
                vTest[0] = true;
                /// D == 3, 
                int limit = 1 << D;
                int sum = 0;
                for (int i = 1; i < limit; i++)
                {
                    int val = convertToVal(i, denom);

                    if (val <= V)
                    {
                        vTest[val] = true;
                    }
                }

                int min = TryAddAllMissing(vTest);

                sw.WriteLine("Case #{0}: {1}", t + 1, min);
            }
        }

        private static int TryAddAllMissing(bool[] vTest)
        {
            if (vTest.All(v => v == true))
            {
                return 0;
            }

            int res = int.MaxValue;

            for (int i = 0; i < vTest.Length; i++)
            {
                if (vTest[i] == false)
                {
                    int bestNotAdding = GetMin(vTest, i, true);
                    if (bestNotAdding != int.MaxValue)
                    {
                        res = Math.Min(bestNotAdding + 1, res);
                    }
                }
            }

            return res;
        }

        private static int GetMin(bool[] vTest, int indexToAdd, bool addingCurrent)
        {
            int V = vTest.Length - 1;

            bool[] newTest = new bool[vTest.Length];
            newTest[0] = true;
            newTest[indexToAdd] = true;

            for (int i = 1; i < vTest.Length; i++)
            {
                if (newTest[i] == false)
                {
                    newTest[i] = vTest[i];
                }

                if (indexToAdd + i <= V && vTest[i] == true)
                {
                    newTest[indexToAdd + i] = true;
                }
            }

            if (newTest.All(v => v == true))
            {
                return 0;
            }

            int res = int.MaxValue;

            for (int k = indexToAdd + 1; k < V + 1; k++)
            {
                if (newTest[k] == false)
                {
                    int bestAdding = GetMin(newTest, k, true);
                    if(bestAdding != int.MaxValue){
                        res = Math.Min(bestAdding+1, res);
                    }
                }
            }

            return res;
        }

        private static int convertToVal(int i, int[] denom)
        {
            int res = 0;
            for (int j = 0; j < denom.Count(); j++)
            {
                if (i % 2 == 1)
                {
                    res += denom[j];
                }
                i = i / 2;
            }

            return res;
        }
    }
}
