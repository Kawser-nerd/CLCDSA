using System;

class Atcoder33
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int n = int.Parse(input[0]);
        int x = int.Parse(input[1]);

        int former = x - 1;
        int latter = n - x;

        if (former < latter) {
            Console.WriteLine(former);
        }
        else {
            Console.WriteLine(latter);
        }
    }
}