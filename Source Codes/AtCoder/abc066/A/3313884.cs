using System;

class Atcoder54
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int a = int.Parse(input[0]);
        int b = int.Parse(input[1]);
        int c = int.Parse(input[2]);

        int ab = a + b;
        int bc = b + c;
        int ca = c + a;

        if (ab <= bc && ab <= ca)
            Console.WriteLine(ab);
        else if (bc <= ab && bc <= ca)
            Console.WriteLine(bc);
        else
            Console.WriteLine(ca);
    }
}