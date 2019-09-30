using System;
class Program
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        Console.WriteLine((n == 100) ? "Perfect" : (n >= 90) ? "Great" : (n >= 60) ? "Good" : "Bad");
    }
}