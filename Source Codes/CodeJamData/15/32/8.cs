using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace MONKEY
{
    class Helper
    {
        internal static double[] ReadDoubles(StreamReader read)
        {
            string line = read.ReadLine();
            string[] tokens = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            double[] arr = new double[tokens.Length];
            int j = 0;
            for (int i = 0; i < tokens.Length; i++)
            {
                if (!string.IsNullOrWhiteSpace(tokens[i]))
                {
                    arr[j++] = double.Parse(tokens[i]);
                }
            }
            return arr;
        }


        internal static long[] ReadNumbersLine(StreamReader read)
        {
            string line = read.ReadLine();
            string[] tokens = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            long[] arr = new long[tokens.Length];
            int j = 0;
            for (int i = 0; i < tokens.Length; i++)
            {
                if (!string.IsNullOrWhiteSpace(tokens[i]))
                {
                    arr[j++] = long.Parse(tokens[i]);
                }
            }
            return arr;
        }

        internal static long ReadNumber(StreamReader read)
        {
            string line = read.ReadLine();

            long n = long.Parse(line);
            return n;
        }
    }
    class Program
    {

        static void Main(string[] args)
        {
            StreamReader read = new StreamReader("Input.txt");
            StreamWriter output = new StreamWriter("Output.txt");
            long T = long.Parse(read.ReadLine());

            for (int i = 0; i < T; i++)
            {
                long[] KLS = Helper.ReadNumbersLine(read);
                long K = KLS[0];
                long L = KLS[1];
                long S = KLS[2];

                string kb = read.ReadLine();
                string word = read.ReadLine();

                bool missing = false;
                double p = 1.0;
                for (int j = 0; j < word.Length; j++)
                {
                    char c = word[j];
                    long cnt = Count(c, kb);
                    if (cnt == 0) missing = true;
                    double odds = (double)cnt / (double)kb.Length;
                    p *= odds;
                }

                int patch = 0;
                for (int k = 0; k < word.Length; k++)
                {
                    if (word.Substring(0, k) == word.Substring(word.Length - k, k))
                    {
                        patch = k;
                    }
                }


                double total = (S - L + 1) * p;

                double bringBanana = (S-L) / (L-patch) + 1;
                if (missing) bringBanana = 0;

                double remain = bringBanana - total;

                output.WriteLine("Case #" + (i + 1) + ": " + remain);
            }
            read.Close();
            output.Close();
        }

        private static long Count(char c, string kb)
        {
            long cnt = 0;
            for (int i = 0; i < kb.Length; i++)
            {
                if (c == kb[i]) cnt++;
            }
            return cnt;
        }
    }
}
