using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ProblemC
{
    public class ProblemC
    {
        Queue<Queue<string>> chunks = new Queue<Queue<string>>();
        void ReadChunks(TextReader tr) { string l; while ((l = tr.ReadLine()) != null) chunks.Enqueue(new Queue<string>(l.Split(' '))); }
        string rc() { var q = chunks.Peek(); if (q.Count == 1) chunks.Dequeue(); return q.Dequeue(); }
        int ri() { return int.Parse(rc()); }
        long rlong() { return long.Parse(rc()); }

        static void Main(string[] args) { new ProblemC().Run(); }

        void Run()
        {
            using (var sr = new StreamReader("C-large.in"))
            using (var sw = new StreamWriter("out.txt"))
            {
                ReadChunks(sr);

                var tCase = ri();

                for (var tiCase = 1; tiCase <= tCase; ++tiCase)
                {
                    sw.WriteLine("Case #{0}: {1}", tiCase, Solve());
                }
            }
        }

        private int[,] M = new int[4, 4]
        {
            {0, 1, 2, 3},
            {1, 0+4, 3, 2+4},
            {2, 3+4, 0+4, 1},
            {3, 2, 1+4, 0+4}
        };

        private int Mult(int a, int b)
        {
            var s = (a & 4) ^ (b & 4);
            a &= 3;
            b &= 3;
            return M[a, b] ^ s;
        }

        private string Solve()
        {
            long L = rlong(), X = rlong();

            var input = rc().Select(c => c - 'i' + 1).ToArray();
            
            int iindex;
            int kindex;
            int irep = 0, krep = 0;
            int product;

            var repetitions = new HashSet<int>();
            product = 0;
            while (true)
            {
                for (iindex = 0; iindex < input.Length; iindex++)
                {
                    product = Mult(product, input[iindex]);
                    if (product == 1)
                        break;
                }
                if (iindex == input.Length)
                {
                    if (!repetitions.Add(product))
                        return "NO";
                    irep++;
                }
                else
                    break;
            }

            repetitions.Clear();
            product = 0;
            while (true)
            {
                for (kindex = input.Length - 1; kindex >= 0; kindex--)
                {
                    product = Mult(input[kindex], product);
                    if (product == 3)
                        break;
                }

                if (kindex == -1)
                {
                    if (!repetitions.Add(product))
                        return "NO";
                    krep++;
                }
                else
                    break;
            }

            if (irep + krep >= X || (irep + krep + 1 == X && iindex >= kindex))
                return "NO";


            if (irep + krep + 1 == X)
            {
                for (product = 0, iindex++; iindex < kindex; iindex++)
                    product = Mult(product, input[iindex]);
            }
            else
            {
                var inputProduct = input.Aggregate(0, Mult);
                
                int iproduct = 0, kproduct = 0;
                for (int i = iindex+1; i < input.Length; i++)
                    iproduct = Mult(iproduct, input[i]);
                for (int i = 0; i < kindex; i++)
                    kproduct = Mult(kproduct, input[i]);

                product = iproduct;
                var cycle = new List<int>(new[]{product});
                int cycleLength;
                int cyclePrefix;
                while(true)
                {
                    product = Mult(product, inputProduct);
                    if (cycle.Contains(product))
                    {
                        cyclePrefix = cycle.IndexOf(product);
                        cycleLength = cycle.Count - cyclePrefix;
                        break;
                    }
                        
                    cycle.Add(product);
                }

                product = iproduct;
                X = X - irep - krep - 2;
                for (int i = 0; i < Math.Min(X, cyclePrefix); i++)
                    product = Mult(product, inputProduct);

                X -= Math.Min(X, cyclePrefix);
                X = X%cycleLength;

                for (int i = 0; i < X; i++)
                    product = Mult(product, inputProduct);

                product = Mult(product, kproduct);
            }

            return product == 2 ? "YES" : "NO";
        }
    }
}
