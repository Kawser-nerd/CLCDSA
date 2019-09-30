using System;

class Program
{
    static void Main(string[] args)
    {
        double sum = 0;
        for(int i = 0; i < 3; i++)
        {
            var input = Console.ReadLine().Split(' ');
            var score = Convert.ToInt32(input[0]);
            var mag = Convert.ToDouble(input[1])/10;
            sum += score * mag;
        }
        Console.WriteLine((int)sum);
    }
}