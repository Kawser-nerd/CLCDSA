using System;
class c
{
    static void Main()
    {
        var ab = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        if (ab[0] > 0) Console.WriteLine("Positive");
        else if (ab[0] <= 0 && ab[1] >= 0) Console.WriteLine("Zero");
        else Console.WriteLine((ab[1] - ab[0]) % 2 == 0 ? "Negative" : "Positive");
    }
}