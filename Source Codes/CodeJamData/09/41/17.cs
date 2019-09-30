using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;
using System.Diagnostics;

namespace QuestionA
{
    class Program
    {
        static void Main(string[] args)
        {
            string casename = "A-large";
            using (StreamReader reader = new StreamReader(casename + ".in"))
            {
                IOStream input = new IOStream(reader);
                using (StreamWriter writer = new StreamWriter(casename + ".out"))
                {
                    int NumCases = input.ReadInt();
                    for (int testcase = 0; testcase != NumCases; ++testcase)
                    {
                        // parse testcase
                        int N = input.ReadInt();
                        List<int> data = new List<int>();
                        for (int i = 0; i != N; ++i)
                        {
                            int maxPos = -1;
                            string line = input.ReadString();
                            for (int j = 0; j != N; ++j)
                            {
                                if (line[j] == '1')
                                {
                                    maxPos = j;
                                }
                            }
                            data.Add(maxPos);
                        }

                        // solve testcase
                        int solution = Solve(data);

                        // write answer
                        Console.WriteLine("Case #{0}: {1}", testcase + 1, solution);
                        writer.WriteLine("Case #{0}: {1}", testcase + 1, solution);
                    }
                }
            }
        }

        private static int Solve(List<int> data)
        {
            int total = 0;
            for (int row = 0; row != data.Count; ++row)
            {
                for (int i = row; i != data.Count; ++i)
                {
                    if (data[i] <= row)
                    {
                        // row 'i' can go here.
                        total += (i - row);
                        int temp = data[i];
                        for (int j = i; j > row; --j)
                        {
                            data[j] = data[j - 1];
                        }
                        data[row] = temp;
                        break;
                    }
                }
            }
            return total;
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
