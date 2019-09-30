using System;

class Atcoder29
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        float W = float.Parse(input[0]);
        float H = float.Parse(input[1]);
        float aspect = W / H;

        if (aspect > 1.7) {
            Console.WriteLine("16:9");
        }
        else {
            Console.WriteLine("4:3");
        }
    }
}