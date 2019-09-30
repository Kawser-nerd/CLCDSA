using System;
class Prpgram
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int k = int.Parse(Console.ReadLine());
        string[] xs = Console.ReadLine().Split(' ');
        int[] x = new int[n];
        for (int i = 0; i < n; i++)
            x[i] = int.Parse(xs[i]);
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += Math.Min(x[i], Math.Abs(k - x[i]));
        Console.WriteLine(sum * 2);
    }
}