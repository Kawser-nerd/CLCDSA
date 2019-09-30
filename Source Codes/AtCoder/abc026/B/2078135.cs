using System;
class Program
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] r = new int[n];
        for (int i = 0; i < n; i++)
            r[i] = int.Parse(Console.ReadLine());
        Array.Sort(r);
        Array.Reverse(r);
        double s = 0;
        for (int i = 0; i < n; i++)
            s += Math.Pow(-1, i) * Math.Pow(r[i], 2);
        Console.WriteLine(s * Math.PI);
    }
}