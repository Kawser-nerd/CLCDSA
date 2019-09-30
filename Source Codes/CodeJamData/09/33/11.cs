using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Bribe_the_Prisoners__Small_Input_
{
    using System.IO;

    public class Program
    {
        private static int[] state;

        private static int P;

        private static int SumOfBribes(int prisoner)
        {
            state[prisoner] = 1;
            int cur = prisoner + 1;
            int res = 0;
            while (cur < P && state[cur] == 0)
            {
                ++res;
                ++cur;
            }

            cur = prisoner - 1;
            while (cur >= 0 && state[cur] == 0)
            {
                ++res;
                --cur;
            }

            return res;
        }

        public static void Main(string[] args)
        {
            var reader = new StreamReader("c.txt");
            var writer = new StreamWriter("c_out.txt");
            int caseNumber = int.Parse(reader.ReadLine());
            for (int cas = 1; cas <= caseNumber; ++cas)
            {
                string[] str = reader.ReadLine().Split(' ');
                P = int.Parse(str[0]);
                var Q = int.Parse(str[1]);

                str = reader.ReadLine().Split(' ');
                var order = new int[Q];
                for (int i = 0; i < Q; ++i)
                {
                    order[i] = int.Parse(str[i])-1;
                }

                int res = int.MaxValue;
                foreach (IEnumerable<int> permutation in PermuteUtils.Permute<int>(order, Q))
                {
                    int s = 0;
                    state = new int[P];
                    foreach (var i in permutation)
                    {
                        s += SumOfBribes(i); 
                    }

                    res = Math.Min(res, s);
                }

                writer.WriteLine(String.Format("Case #{0}: {1}", cas, res));

            }



            reader.Close();
            writer.Close();
        }
    }

    public class PermuteUtils
    {
     public static IEnumerable<IEnumerable<T>> Permute<T>(IEnumerable<T> list, int count)
        {
            if (count == 0)
            {
                yield return new T[0];
            }
            else
            {
                int startingElementIndex = 0;
                foreach (T startingElement in list)
                {
                    IEnumerable<T> remainingItems = AllExcept(list, startingElementIndex);

                    foreach (IEnumerable<T> permutationOfRemainder in Permute(remainingItems, count - 1))
                    {
                        yield return Concat<T>(
                            new T[] { startingElement },
                            permutationOfRemainder);
                    }
                    startingElementIndex += 1;
                }
            }
        }

        public static IEnumerable<T> Concat<T>(IEnumerable<T> a, IEnumerable<T> b)
        {
            foreach (T item in a)
            {
                yield return item;
            }

            foreach (T item in b)
            {
                yield return item;
            }
        }

        public static IEnumerable<T> AllExcept<T>(IEnumerable<T> input, int indexToSkip)
        {
            int index = 0;
            foreach (T item in input)
            {
                if (index != indexToSkip)
                {
                    yield return item;
                }

                index += 1;
            }
        }
    }

}
