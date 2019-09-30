using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            using(StreamReader sr = new StreamReader("in.txt"))
            {
                using (StreamWriter sw = new StreamWriter("out.txt"))
                {
                    IEnumerator<string> tokenizer = Tokens(sr, new char[] { ' ', '\t' }).GetEnumerator();
                    long T = GetLong(tokenizer);
                    for (int t = 0; t < T; t++)
                    {
                        long N = GetLong(tokenizer);
                        long K = GetLong(tokenizer);
                        long mask = (((long)1) << ((int)N)) - 1;

                        sw.Write("Case #{0}: ", t+1);
                        if ((K & mask) == mask)
                        {
                            sw.WriteLine("ON");
                        }
                        else
                        {
                            sw.WriteLine("OFF");
                        }
                    }
                }
            }
        }



        static long GetLong(IEnumerator<string> tokenizer)
        {
            long ret;
            if (tokenizer.MoveNext() && long.TryParse(tokenizer.Current, out ret))
                return ret;
            else
            {
                throw new Exception("Not parsable");
            }
        }

        static IEnumerable<string> Tokens(StreamReader reader, char[] delimit)
        {
            while (!reader.EndOfStream)
            {
                string[] tokens = reader.ReadLine().Split(delimit, StringSplitOptions.RemoveEmptyEntries);
                foreach (string str in tokens)
                {
                    yield return str;
                }
            }
        }
    }
}
