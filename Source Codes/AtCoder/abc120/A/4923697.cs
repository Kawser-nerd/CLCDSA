using System;
class Program
{
    static void Main(string[] args)
    {
        string[] input1 = Console.ReadLine().Split(' ');
        int A = int.Parse(input1[0]);
        int B = int.Parse(input1[1]);
        int C = int.Parse(input1[2]);

        if (A * C > B)
            Console.WriteLine(B / A);
        else
            Console.WriteLine(C);
    }
}