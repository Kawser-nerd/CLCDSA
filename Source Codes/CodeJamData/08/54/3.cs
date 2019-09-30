using System;

public class endless
{
    public static void Main(string[] args)
    {
        int CASES = int.Parse(Console.ReadLine());

        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            string[] parts = Console.ReadLine().Split();
            int H = int.Parse(parts[0]);
            int W = int.Parse(parts[1]);
            int R = int.Parse(parts[2]);
            bool[,] rock = new bool[H + 5, W + 5];
            for (int i = 0; i < R; i++)
            {
                parts = Console.ReadLine().Split();
                rock[int.Parse(parts[0]), int.Parse(parts[1])] = true;
            }
            int[,] ways = new int[H + 5, W + 5];
            ways[1, 1] = 1;
            for (int i = 1; i <= H; i++)
            {
                for (int j = 1; j <= W; j++)
                {
                    if (rock[i, j]) continue;
                    ways[i, j] %= 10007;
                    ways[i + 1, j + 2] += ways[i, j];
                    ways[i + 2, j + 1] += ways[i, j];
                }
            }
            Console.WriteLine("Case #" + CASE + ": " + ways[H, W]);
        }
    }
}