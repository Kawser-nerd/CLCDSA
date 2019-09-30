using System;
class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(' ');
        ulong x = ulong.Parse(input[1]);
        ulong y = ulong.Parse(input[0]) - x;
        ulong sum = 0;
        sum += x;
        sum += y;
        while (x != 0)
        {
            sum += (2 * x) * (y / x);
            ulong tmp = y;
            y = x;
            x = tmp % x;
        } 
        sum -= y;
        Console.WriteLine(sum);
    }
}