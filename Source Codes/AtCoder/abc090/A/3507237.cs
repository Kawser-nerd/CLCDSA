using System;

class Atcoder78
{
    public static void Main()
    {
        string a = Console.ReadLine();
        string b = Console.ReadLine();
        string c = Console.ReadLine();

        char a0 = a[0];
        char b1 = b[1];
        char c2 = c[2];

        string a00 = a0.ToString();
        string b01 = b1.ToString();
        string c02 = c2.ToString();

        Console.WriteLine(a00 + b01 + c02);
    }
}