using System;

class Atcoder21
{
    public static void Main()
    {
        int natural = int.Parse(Console.ReadLine());

        if (natural < 2 && natural > 0) {
            Console.WriteLine("1");
            Console.WriteLine("1");
        }
        if (natural < 3 && natural > 1) {
            Console.WriteLine("1");
            Console.WriteLine("2");
        }
        if (natural < 4 && natural > 2) {
            Console.WriteLine("2");
            Console.WriteLine("1");
            Console.WriteLine("2");
        }
        if (natural < 5 && natural > 3) {
            Console.WriteLine("1");
            Console.WriteLine("4");
        }
        if (natural < 6 && natural > 4) {
            Console.WriteLine("2");
            Console.WriteLine("1");
            Console.WriteLine("4");
        }
        if (natural < 7 && natural > 5) {
            Console.WriteLine("2");
            Console.WriteLine("2");
            Console.WriteLine("4");
        }
        if (natural < 8 && natural > 6) {
            Console.WriteLine("3");
            Console.WriteLine("1");
            Console.WriteLine("2");
            Console.WriteLine("4");
        }
        if (natural < 9 && natural > 7) {
            Console.WriteLine("1");
            Console.WriteLine("8");
        }
        if (natural < 10 && natural > 8) {
            Console.WriteLine("2");
            Console.WriteLine("1");
            Console.WriteLine("8");
        }
        if (natural < 11 && natural > 9) {
            Console.WriteLine("2");
            Console.WriteLine("2");
            Console.WriteLine("8");
        }
    }
}