using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Collections;

namespace QuestionC
{
    class Program
    {
        static void Main(string[] args)
        {
            string casename = "C-small-attempt0";
            using (StreamReader reader = new StreamReader(casename + ".in"))
            {
                IOStream input = new IOStream(reader);
                using (var writer = new StreamWriter(casename + ".out"))
                {
                    int T = input.ReadInt();
                    for (int t = 0; t != T; ++t)
                    {
                        // parse test case
                        int A1 = input.ReadInt();
                        int A2 = input.ReadInt();
                        int B1 = input.ReadInt();
                        int B2 = input.ReadInt();

                        // solve
                        int count = 0;
                        for (int a = A1; a <= A2; ++a)
                        {
                            for (int b = B1; b <= B2; ++b)
                            {
                                if (Winning(a, b))
                                {
                                    ++count;
                                }
                            }
                        }
                        
                        writer.WriteLine("Case #{0}: {1}", t + 1, count);
                    }
                }
            }
        }

        private static bool Winning(int a, int b)
        {
            var k = new List<int>();
            if (a > b)
            {
                Euclid(a, b, k);
            }
            else
            {
                Euclid(b, a, k);
            }
            return IsWinning(k, 0);
        }

        private static bool IsWinning(List<int> K, int pos)
        {
            if (pos + 1 == K.Count)
            {
                // next step is 0 and lost, just a question of whether enough K's to put other player there!
                return K[pos] > 1;
            }
            bool next = IsWinning(K, pos + 1);

            if (!next) return true; // next position is losing - put other player there
            return K[pos] > 1; // next position is winning - if K > 1 at this step, can reduce to K = 1 and force them to put us in next position
        }

        private static void Euclid(int a, int b, List<int> k)
        {
            if (b == 0)
            {
                return;
            }
            k.Add(a / b);
            Euclid(b, a % b, k);
        }
    }

    class IOStream
    {
        public IOStream(StreamReader reader)
        {
            this.reader = reader;
        }

        public int ReadInt()
        {
            return int.Parse(ReadString());
        }

        public long ReadLong()
        {
            return long.Parse(ReadString());
        }

        public string ReadString()
        {
            if (parts == null || partNum >= parts.Length)
            {
                ReadMore();
            }
            string rtn = parts[partNum];
            ++partNum;
            return rtn;
        }

        private void ReadMore()
        {
            parts = reader.ReadLine().Split(' ');
            partNum = 0;
        }

        StreamReader reader;
        string[] parts;
        int partNum;
    }
}
