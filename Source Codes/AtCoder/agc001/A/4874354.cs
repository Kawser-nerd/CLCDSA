using System;
class Program
{
    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        string[] input = Console.ReadLine().Split(' ');
        int[] L = new int[2 * N];
        for(int i = 0; i < L.Length; i++)
        {
            L[i] = int.Parse(input[i]);
        }
        Array.Sort(L);
        int sum = 0;
        for(int i = 0; i < L.Length; i = i + 2)
        {
            sum += Math.Min(L[i], L[i + 1]);
        }
        Console.WriteLine(sum);
    }
}