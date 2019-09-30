using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Runtime.Remoting.Channels;

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

    class Program
    {
        private int[] A;

        public void Solve()
        {
            var sc = new Scanner();
            A = sc.IntArray();
            Array.Sort(A);
            int ans = 0;
            var bb = A[2] - A[1];
            A[0] += bb;
            A[1] = A[2];
            var aa = (A[2] - A[0]) / 2;
            A[0] += 2 * aa;
            ans = aa + bb;
            if (A[2] - A[0] == 1)
            {
                ans += 2;
            }
            Console.WriteLine(ans);
         
        }

        static void Main(string[] args)
        {
            new Program().Solve();
        }
    }
}