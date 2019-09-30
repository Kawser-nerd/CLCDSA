using System;

class Atcoder40
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        string a = input[0];
        string b = input[1];
        string c = input[2];

        char aa = a[0];
        char bb = b[0];
        char cc = c[0];

        string aaa = aa.ToString();
        string bbb = bb.ToString();
        string ccc = cc.ToString();

        Console.WriteLine(aaa + bbb + ccc);
    }
}