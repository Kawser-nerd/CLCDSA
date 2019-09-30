using System;
class c
{
    static void Main()
    {
        var inp = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);
        Console.WriteLine((inp[0] - inp[1]) * (inp[3] % 2 == 0 ? 1 : -1));
    }
}