using System;

class Atcoder27
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int atk = int.Parse(input[0]);
        int dif = int.Parse(input[1]);

        if (atk > dif) {
            Console.WriteLine(atk * (dif + 1));
        }
        else if (atk < dif) {
            Console.WriteLine((atk + 1) * dif);
        }
        else {
            Console.WriteLine(atk * (dif + 1));
        }
    }
}