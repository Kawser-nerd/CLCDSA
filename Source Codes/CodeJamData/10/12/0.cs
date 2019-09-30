using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam2010
{
    class b
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

        private static String readAndSolveCase()
        {
            var dimn = readIntIntIntInt();

            int INF = 1000000000;

            var D = dimn.Item1;
            var I = dimn.Item2;
            var M = dimn.Item3;
            var N = dimn.Item4;

            int[] values = readInts(N);

            int C = 256;
            int[] prices = new int[C];

            for (int i = 0; i < N; i++)
            {
                int[] newPrices = new int[C];
                for (int j = 0; j < C; j++)
                    newPrices[j] = INF;
                
                //try changing
                for (int newColor = 0; newColor < C; newColor++)
                    for (int oldColor = 0; oldColor < C; oldColor++)
                        if (Math.Abs(oldColor - newColor) <= M)
                            newPrices[newColor] = Math.Min(newPrices[newColor], prices[oldColor] + Math.Abs(newColor - values[i]));

                if (M != 0)
                {
                    //try inserting
                    for (int newColor = 0; newColor < C; newColor++)
                        for (int oldColor = 0; oldColor < C; oldColor++)
                        {
                            int distance = Math.Abs(oldColor - newColor);
                            int insertions = -((M * 10000 - distance) / M - 10000);
                            newPrices[newColor] = Math.Min(newPrices[newColor], newPrices[oldColor] + I * insertions);
                        }
                }

                //try deleting
                for (int newColor = 0; newColor < C; newColor++)
                    newPrices[newColor] = Math.Min(newPrices[newColor], D + prices[newColor]);

                prices = newPrices;
            }


            return prices.Min().ToString();
        }
    }
}
