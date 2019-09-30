using System;
class c
{
    static void Main()
    {
        var inp = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        int dx = inp[2] - inp[0], dy = inp[3] - inp[1];
        Console.WriteLine("{0} {1} {2} {3}", inp[2] - dy, inp[3] + dx, inp[2] - dy - dx, inp[3] + dx - dy);
    }
}