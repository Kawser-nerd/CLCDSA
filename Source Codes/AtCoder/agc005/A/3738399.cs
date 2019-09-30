using System;
class c
{
    static void Main()
    {
        var inp = Console.ReadLine();
        int s = 0;
        for (int i = 0; i < inp.Length; i++)
        {
            if (inp[i] == 'S') s++;
            else if (s > 0) s--;
        }
        Console.WriteLine(2 * s);
    }
}