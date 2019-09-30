using System;

class program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split();
        int a = int.Parse(input[0]);
        int b = int.Parse(input[1]);
        int c = a * b;
        string answer;
        if (c % 2 == 0)
        {
            answer = "Even";
        }
        else
        {
            answer = "Odd";
        }

        Console.WriteLine(answer);
    }
}