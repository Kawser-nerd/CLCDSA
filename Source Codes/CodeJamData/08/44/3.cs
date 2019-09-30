using System;
using System.Collections.Generic;

public class permrle
{
    public static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());

        for (int cs = 1; cs <= N; cs++)
        {
            int k = int.Parse(Console.ReadLine());
            string S = Console.ReadLine();
            int[] perm = new int[k];
            int best = int.MaxValue;
            for (int i = 0; i < k; i++)
                perm[i] = i;
            do
            {
                int blocks = 0;
                char last = '_';
                for (int i = 0; i < S.Length; i++)
                {
                    if (S[perm[i % k] + i - (i % k)] == last)
                        continue;
                    blocks++;
                    last = S[perm[i % k] + i - (i % k)];
                }
                best = Math.Min(blocks, best);
            } while (Permutation<int>.NextPermutation(perm));
            Console.WriteLine("Case #" + cs + ": " + best);
        }
    }


    public static class Permutation<T>
    {
        public static bool NextPermutation(T[] array)
        {
            Comparer<T> comp = Comparer<T>.Default;

            for (int i = array.Length - 2; i >= 0; i--)
            {
                if (comp.Compare(array[i], array[i + 1]) < 0)
                {
                    int j = array.Length - 1;
                    while (comp.Compare(array[i], array[j]) >= 0)
                        j--;
                    T tmp = array[i];
                    array[i] = array[j];
                    array[j] = tmp;
                    System.Array.Reverse(array, i + 1, array.Length - i - 1);
                    return true;
                }
            }
            return false;
        }
    }
}