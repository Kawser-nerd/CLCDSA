using System;
class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(' ');
        int A = int.Parse(input[0]);
        int B = int.Parse(input[1]);
        if (B % A == 0)
            Console.WriteLine(A + B);
        else
            Console.WriteLine(B - A);
    }
}