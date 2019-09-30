using System;

class Atcoder24
{
    public static void Main()
    {
        string doubledigit = Console.ReadLine();
        char former = doubledigit[0];
        char latter = doubledigit[1];

        string f = former.ToString();
        string l = latter.ToString();

        int ff = int.Parse(f);
        int ll = int.Parse(l);

        Console.WriteLine(ff + ll);
    }
}