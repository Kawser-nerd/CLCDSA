using System;

class Atcoder91
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int a = int.Parse(input[0]);
        int b = int.Parse(input[1]);
        int c = int.Parse(input[2]);

        int[] tasks = { a, b, c };
        Array.Sort(tasks);

        Console.WriteLine((tasks[2] - tasks[1]) + (tasks[1] - tasks[0]));
    }
}