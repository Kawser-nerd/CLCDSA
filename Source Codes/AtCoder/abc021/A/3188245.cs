using System;

class Program
{
    static void Main(string[] args)
    {
        var num = Convert.ToInt32(Console.ReadLine());

        var counter = 0;
        while (num - 1 >= 0)
        {
            counter++;
            num--;
        }

        Console.WriteLine(counter);
        for(int i = 0; i < counter; i++)
        {
            Console.WriteLine(1);
        }
    }
}