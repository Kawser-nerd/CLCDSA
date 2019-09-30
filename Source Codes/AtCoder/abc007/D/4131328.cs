using System;
using System.Linq;
using System.IO;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder {
    public class Program {
        static int[] getKeys(char delimiter) {
            var Keys = Console.ReadLine().Split(' ');
            int N = Keys.Length;
            int[] Ns = new int[N];
            for (int i = 0; i < N; i++) {
                Ns[i] = int.Parse(Keys[i]);
            }
            return Ns;
        }
        public static void Show<T>(T[,] map) {
            int H = map.GetLength(0);
            int W = map.GetLength(1);
            Console.WriteLine("-------------------------");
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    Console.Write(map[i, j] + " ");
                }
                Console.WriteLine();
            }
            Console.WriteLine("-------------------------");
        }
        public static void Show<T>(T[,] map, string delimiter) {
            int H = map.GetLength(0);
            int W = map.GetLength(1);
            Console.WriteLine("-------------------------");
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    Console.Write(map[i, j] + delimiter);
                }
                Console.WriteLine();
            }
            Console.WriteLine("-------------------------");
        }
        public static void Show<T>(IEnumerable<T> ts) {
            foreach (var item in ts) {
                Console.Write(item + " ");
            }
            Console.WriteLine();
        }
        public static void Show<T>(IEnumerable<T> ts, string delimiter) {
            foreach (var item in ts) {
                Console.Write(item + delimiter);
            }
            Console.WriteLine();
        }

        //F[n] = (n+1)?????????????????(d[2]??010???)
        static long[] Forbidden;
        static void Main() {
            var inputs = Console.ReadLine().Split(' ');
            long[] Key = new long[2];
            Key[0] = long.Parse(inputs[0]);
            Key[1] = long.Parse(inputs[1]);
            Forbidden = new long[Key[1].ToString().Length];
            Forbidden[0] = 2;
            for (int i = 1; i < Forbidden.Length; i++) {
                Forbidden[i] = 7 * Forbidden[i - 1] + 2 * (long)Math.Pow(10, i) + Forbidden[i - 1];
            }
            Console.WriteLine(RecCount(Key[1]) - RecCount(Key[0] - 1));
            
        }


        static long RecCount(long n) {
            long Digits = n.ToString().Length;
            long answer = 0;
            bool end = false;
            for (int i = 0; i < Digits; i++) {
                int top = (i == 0) ? 0 : n.ToString()[i - 1] - '0';
                if (i != 0 && top == 0) continue;
                answer += Count(long.Parse(n.ToString().Substring(i)), top, out end);
                if (end) break;
            }
            return answer;
        }
        static long Count(long n, int top,out bool stop) {
            if (top == 4 || top == 9) {
                stop = true;
                return n + 1;
            } else {
                stop = false;
                if (n < 10) {
                    return getCount(n);
                }
                long nn = n - n % (long)Math.Pow(10, n.ToString().Length - 1);
                return getCount(nn - 1);
            }
        }

        //1?N???????
        //N?499?????????9?????????
        static long getCount(long N) {
            if (N < 10) {
                if (N < 4) {
                    return 0;
                } else if (N < 9) {
                    return 1;
                } else {
                    return 2;
                }
            }
            int TopDigit = int.Parse(N.ToString()[0].ToString());
            long Length = N.ToString().Length;
            if (TopDigit < 4) {
                return (TopDigit + 1) * Forbidden[Length - 2];
            } else if (TopDigit < 9) {
                return TopDigit * Forbidden[Length - 2] + (long)Math.Pow(10, Length - 1);
            } else {
                return 8 * Forbidden[Length - 2] + 2 * (long)Math.Pow(10, Length - 1);
            }
        }
    }
}