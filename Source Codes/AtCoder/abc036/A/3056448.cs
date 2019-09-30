using System;

class Atcoder30
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int A = int.Parse(input[0]);
        int B = int.Parse(input[1]);

        if ( B % A == 0) {
            Console.WriteLine(B / A);
        }
        else {
            int dif = B % A;
            Console.WriteLine((B - dif) / A + 1);
        }
    }
}