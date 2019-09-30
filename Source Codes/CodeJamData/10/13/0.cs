using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam2010
{
    class c
    {
        private static Tuple<int, int> readIntInt()
        {
            int[] arr = readInts(2);
            return Tuple.Create(arr[0], arr[1]);
        }

        private static Tuple<int, int, int> readIntIntInt()
        {
            int[] arr = readInts(3);
            return Tuple.Create(arr[0], arr[1], arr[2]);
        }

        private static Tuple<int, int, int, int> readIntIntIntInt()
        {
            int[] arr = readInts(4);
            return Tuple.Create(arr[0], arr[1], arr[2], arr[3]);
        }

        private static int[] readInts(int count)
        {
            int[] result = readInts();
            if (result.Length != count)
                throw new Exception(String.Format("input length mismatch: {0} numbers instead of {1}", result.Length, count));
            return result;
        }
        
        static void Main(string[] args)
        {
            int casesCount = Int32.Parse(Console.ReadLine());
            for (int cid = 0; cid < casesCount; cid++)
                Console.WriteLine("Case #{0}: {1}", cid + 1, readAndSolveCase());
        }

        private static int[] readInts()
        {
            return Console.ReadLine().Split(' ').Select(item => int.Parse(item)).ToArray();
        }

        static long countLess(int a1, int a2, int b1, int b2)
        {
            double golden = (1.0+Math.Sqrt(5))/2.0;
            long result = 0;
            for (int i = a1; i < a2; i++)
            {
                int badFrom = (int)Math.Ceiling(i / golden);
                int badTo = (int)Math.Ceiling(i * golden);
                if (badFrom < b1)
                    badFrom = b1;
                if (badTo < b1)
                    badTo = b1;
                if (badFrom > b2)
                    badFrom = b2;
                if (badTo > b2)
                    badTo = b2;
                result += b2 - b1 - (badTo - badFrom);
            }
            return result;
        }

        private static String readAndSolveCase()
        {
            var aabb = readIntIntIntInt();

            var a1 = aabb.Item1;
            var a2 = aabb.Item2+1;
            var b1 = aabb.Item3;
            var b2 = aabb.Item4+1;

            return countLess(a1, a2, b1, b2).ToString();
        }
    }
}
