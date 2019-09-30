using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var num = Convert.ToInt32(input[0]);
        var set = Convert.ToInt32(input[1]);
        var input2 = Console.ReadLine().Split(' ');
        var result = 0;
        for(var i = 0; i < num; i++)
        {
            if ((int)(set / Math.Pow(2,i))%2 == 1) result += Convert.ToInt32(input2[i]);
        }

        Console.WriteLine(result);
    }
}