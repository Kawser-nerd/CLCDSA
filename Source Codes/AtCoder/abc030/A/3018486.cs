using System;

class Atcoder26
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        float tgame = float.Parse(input[0]);
        float twin = float.Parse(input[1]);
        float agame = float.Parse(input[2]);
        float awin = float.Parse(input[3]);

        float twp = twin / tgame;
        float awp = awin / agame;

        if (twp > awp) {
            Console.WriteLine("TAKAHASHI");
        }
        else if (awp > twp) {
            Console.WriteLine("AOKI");
        }
        else {
            Console.WriteLine("DRAW");
        }
    }
}