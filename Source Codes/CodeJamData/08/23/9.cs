using System;
using System.Collections;

public class mousetrap
{
    public static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        for (int cs = 1; cs <= N; cs++)
        {
            int K = int.Parse(Console.ReadLine());
            int[] deck = new int[0];
            for (int i = 1; i <= K; i++)
            {
                int insert = K - i + 1;
                int size = i;
                int pos = (insert - 1) % size;
                int[] tmpdeck = new int[size];
                tmpdeck[pos] = insert;
                for (int j = 0; j < size - 1; j++)
                    tmpdeck[(pos + j + 1) % size] = deck[j];
                deck = tmpdeck;
            }

            Console.Write("Case #" + cs + ": ");
            string[] parts = Console.ReadLine().Split();
            for (int i = 1; i < parts.Length; i++)
            {
                if (i > 1) Console.Write(" ");
                Console.Write(deck[int.Parse(parts[i]) - 1]);
            }
            Console.WriteLine();
        }
    }
}