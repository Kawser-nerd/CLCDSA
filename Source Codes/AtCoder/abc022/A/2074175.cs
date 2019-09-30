using System;
class Program
{
    public static void Main()
    {
        string[] str = Console.ReadLine().Split(' ');
        int n = int.Parse(str[0]);
        int s = int.Parse(str[1]);
        int t = int.Parse(str[2]);
        int wei = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            wei += int.Parse(Console.ReadLine());
            if (wei >= s && wei <= t)
                count++;
        }
        Console.WriteLine(count);
    }
}