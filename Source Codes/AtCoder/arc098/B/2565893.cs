using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Net.Mail;

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
        private int N;
        private long[] A;
        private int MaxRight = 0;
        private void Scan()
        {
            var sc = new Scanner();
            N = sc.NextInt();
            A = sc.LongArray();
        }

        public void Solve()
        {
            Scan();
            long cnt = 0;
            int left = 0;
            int right = 0;
            long xor = 0;
            for (right = 0; right < N; right++)
            {
                if ((xor & A[right]) == 0)
                {
                    xor ^= A[right];
                }
                else
                {
                    cnt += Count(left, right);
                    while (left <= right)
                    {
                        xor ^= A[left];
                        left++;
                        if ((xor & A[right]) == 0)
                        {
                            break;
                        }
                    }

                    xor ^= A[right];
                }
            }
            cnt += Count(left, right);
            Console.WriteLine(cnt);
        }

        private long Count(int left, int right)
        {
            //right -= 1;
            int a = MaxRight - left;
            int b = right - MaxRight;
            long res = 0;
            res += (long)a * b;
            res += (long)b * (b + 1) / 2;
            //Console.WriteLine($"{a} {b}");
            //Console.WriteLine($"{left} {MaxRight} {right} {res}");

            MaxRight = right;
            return res;
        }

        static void Main() => new Program().Solve();
    }
}