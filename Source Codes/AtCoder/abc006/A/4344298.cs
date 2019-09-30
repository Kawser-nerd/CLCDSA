using System;

class Atcoder111
{
    public static void Main()
    {
        string num = Console.ReadLine();
        int numi = int.Parse(num);

        if (numi % 3 == 0)
            Console.WriteLine("YES");
        else
            Console.WriteLine("NO");
    }
}