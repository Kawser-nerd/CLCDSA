using System;

class Atcoder100
{
    public static void Main()
    {
        int age = int.Parse(Console.ReadLine());

        if (age == 1)
            Console.WriteLine("Hello World");
        else
        {
            int a = int.Parse(Console.ReadLine());
            int b = int.Parse(Console.ReadLine());

            Console.WriteLine(a + b);
        }
    }
}