using System;

class Program
{
    static void Main(string[] args)
    {
        var trainPrice1 = Convert.ToInt32(Console.ReadLine());
        var trainPrice2 = Convert.ToInt32(Console.ReadLine());
        var busPrice1 = Convert.ToInt32(Console.ReadLine());
        var busPrice2 = Convert.ToInt32(Console.ReadLine());

        var trainMin = Math.Min(trainPrice1, trainPrice2);
        var busMin = Math.Min(busPrice1, busPrice2);
        Console.WriteLine(trainMin + busMin);
    }
}