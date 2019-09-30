using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace GCJ2010
{
    class Round1A
    {
        public void SloveFile(string inputfile)
        {
            using (StreamReader reader = new StreamReader(inputfile))
            using (StreamWriter writer = new StreamWriter(inputfile + ".out"))
            {
                int n = int.Parse(reader.ReadLine());
                for (int i = 1; i <= n; i++)
                {
                    string l = reader.ReadLine();
                    int N = int.Parse(l);

                    Pair[] inputs = new Pair[N];

                    for (int j = 0; j < N; j++)
                    {
                        var ss = reader.ReadLine().Split();
                        inputs[j] = new Pair()
                        {
                            Left = int.Parse(ss[0]),
                            Right = int.Parse(ss[1]),
                        };                    
                    }
                   
                    int r = SloveCase(N, inputs);

                    writer.WriteLine("Case #{0}: {1}", i, r);
                    Console.WriteLine("Case #{0}: {1}", i, r);
                }
            }
        }

        int SloveCase(int N, Pair[] inputs)
        {
            int r = 0;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (i == j)
                        continue;

                    int d = (inputs[i].Left - inputs[j].Left) * (inputs[i].Right - inputs[j].Right);
                    if (d < 0)
                        r++;
                }
            }

            return r;
        }

        private class Pair
        {
            public int Left;
            public int Right;
        }

    }
}
