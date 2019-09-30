using System;
class c
{
    static void Main()
    {
        var ni = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        Console.WriteLine(ni[0] - ni[1] + 1);
    }
}