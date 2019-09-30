using System;

class Atcoder112
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split('/');
        int year = int.Parse(input[0]);
        int month = int.Parse(input[1]);
        int day = int.Parse(input[2]);

        if (year < 2019)
            Console.WriteLine("Heisei");
        else if (year == 2019 && month < 4)
            Console.WriteLine("Heisei");
        else if (year == 2019 && month == 4 && day <= 30)
            Console.WriteLine("Heisei");
        else
            Console.WriteLine("TBD");
    }
}