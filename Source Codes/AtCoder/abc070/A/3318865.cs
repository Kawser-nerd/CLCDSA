using System;

class Atcoder58
{
    public static void Main()
    {
        string n = Console.ReadLine();
        int nint = int.Parse(n);

        char dig3 = n[0];
        char dig2 = n[1];
        char dig1 = n[2];

        string str3 = dig3.ToString();
        string str2 = dig2.ToString();
        string str1 = dig1.ToString();

        string nrev = str1 + str2 + str3;
        int nrevint = int.Parse(nrev);

        if (nint == nrevint)
            Console.WriteLine("Yes");
        else
            Console.WriteLine("No");
    }
}