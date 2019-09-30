using System;

class Atcoder25
{
    public static void Main()
    {
        int score = int.Parse(Console.ReadLine());

        if (score <= 59) {
            Console.WriteLine("Bad");
        }
        else if (score >= 60 && score <= 89) {
            Console.WriteLine("Good");
        }
        else if (score >= 90 && score <= 99) {
            Console.WriteLine("Great");
        }
        else {
            Console.WriteLine("Perfect");
        }
    }
}