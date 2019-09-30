using System;

class Atcoder80
{
    public static void Main()
    {
        int a = int.Parse(Console.ReadLine());
        int b = int.Parse(Console.ReadLine());
        int c = int.Parse(Console.ReadLine());
        int d = int.Parse(Console.ReadLine());

        if (a <= b && c <= d)
            Console.WriteLine(a + c);
        else if (a <= b && c > d)
            Console.WriteLine(a + d);
        else if (a > b && c <= d)
            Console.WriteLine(b + c);
        else
            Console.WriteLine(b + d);
    }
}