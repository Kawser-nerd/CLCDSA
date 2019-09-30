using System;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        long ans = 0;
        for (long i = 1; i < 1000000001; i++)
        {
            long tmp = i * i;
            if (tmp > n)
            {
                Console.WriteLine(ans);
                break;
            }
            ans = tmp;
        }
    }
}