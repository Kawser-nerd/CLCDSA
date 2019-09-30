using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using static System.Console;
using static System.Math;

namespace NotFounds
{
    public class Program
    {
        public static void Main(string[] args)
        {
            new Program().Solve();
        }

        public void Solve()
        {
            var cin = new MyInputStream();
            var N = cin.ri();
            var s = new int[N];

            for (int i = 0; i < N; ++i)
                s[i] = cin.ri();

            Array.Sort(s);

            var sum = s.Sum();

            if (sum % 10 != 0)
            {
                WriteLine(sum);
                return;
            }
            else
            {
                for (int i = 0; i < N; ++i)
                {
                    if ((sum - s[i]) % 10 != 0)
                    {
                        WriteLine(sum - s[i]);
                        return;
                    }
                }
            }
            WriteLine(0);
        }
    }

    public class MyInputStream
    {
        private char separator = ' ';
        private Queue<string> inputStream;
        public MyInputStream(char separator = ' ')
        {
            this.separator = separator;
            inputStream = new Queue<string>();
        }

        public string Read()
        {
            if (inputStream.Count != 0) return inputStream.Dequeue();
            string[] tmp = Console.ReadLine().Trim().Split(separator);
            for (int i = 0; i < tmp.Length; i++)
            {
                inputStream.Enqueue(tmp[i]);
            }
            return inputStream.Dequeue();
        }
        public string ReadLine() => Console.ReadLine();
        public int ReadInt() => int.Parse(Read());
        public long ReadLong() => long.Parse(Read());
        public double ReadDouble() => double.Parse(Read());
        public string r() => Read();
        public int ri() => ReadInt();
        public long rl() => ReadLong();
        public double rd() => ReadDouble();
    }
}