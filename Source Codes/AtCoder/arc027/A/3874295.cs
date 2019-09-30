using System;
class Program
{
    static void Main(string[] args)
    {
            string[] S = Console.ReadLine().Trim().Split(' ');
            Console.WriteLine((DateTime.Parse("18:00") - DateTime.Parse(S[0] + ":" + S[1])).TotalMinutes.ToString());
    }
}