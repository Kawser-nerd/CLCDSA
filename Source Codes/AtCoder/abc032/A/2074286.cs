using System;
class Program
{
    public static void Main()
    {
        int a, b, n;
        a = int.Parse(Console.ReadLine());
        b = int.Parse(Console.ReadLine());
        n = int.Parse(Console.ReadLine());
        for (int i = Math.Max(Math.Max(a, b), n); ; i++)
        {
            if (i % a == 0 && i % b == 0)
            {
                Console.WriteLine(i);
                break;
            }
        }
    }
}