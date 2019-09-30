using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Runtime.Remoting.Contexts;
using System.Security.Cryptography.X509Certificates;

namespace Contest
{
    class Scanner
    {
        private string[] line = new string[0];
        private int index = 0;
        public string Next()
        {
            if (line.Length <= index)
            {
                line = Console.ReadLine().Split(' ');
                index = 0;
            }
            var res = line[index];
            index++;
            return res;
        }
        public int NextInt()
        {
            return int.Parse(Next());
        }
        public long NextLong()
        {
            return long.Parse(Next());
        }
        public string[] Array()
        {
            line = Console.ReadLine().Split(' ');
            index = line.Length;
            return line;
        }
        public int[] IntArray()
        {
            var array = Array();
            var result = new int[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                result[i] = int.Parse(array[i]);
            }

            return result;
        }
        public long[] LongArray()
        {
            var array = Array();
            var result = new long[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                result[i] = long.Parse(array[i]);
            }

            return result;
        }
    }

    struct A
    {
        public int Value, Index;

        public A(int v, int i)
        {
            Value = v;
            Index = i;
        }
    }

    class Program
    {
        private int N;
        private int[] A;
        private void Scan()
        {
            var sc = new Scanner();
            N = sc.NextInt();
            A = sc.IntArray();
        }

        public void Solve()
        {
            Scan();
            Array.Sort(A);
            int b = A[N - 1];

            double min = double.MaxValue;
            int ans = -1;

            for (int i = 0; i < N - 1; i++)
            {
                if (min > Math.Abs((double) b / 2 - A[i]))
                {
                    ans = A[i];
                    min = Math.Abs((double) b / 2 - A[i]);
                }
            }
            Console.WriteLine($"{b} {ans}");
        }


        static void Main(string[] args)
        {
            new Program().Solve();
        }
    }
}