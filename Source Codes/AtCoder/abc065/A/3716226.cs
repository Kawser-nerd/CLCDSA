using System;
 
class Program
{
    static void Main()
    {
        var data = Console.ReadLine().Split();
        var x = int.Parse(data[0]);
        var a = int.Parse(data[1]);
        var b = int.Parse(data[2]);
 
        if (b - a <= x)
        {
            if (b - a <= 0)
            {
                Console.WriteLine("delicious");
            }
            else
            {
                Console.WriteLine("safe");
            }
        }
        else
        {
            Console.WriteLine("dangerous");
        }
    }
}