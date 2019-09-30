using System;

class Program
{
    static void Main(string[] args)
    {
        var num = Convert.ToInt32(Console.ReadLine());
        var input = Console.ReadLine().Split(' ');
        var result = 0;
        for(var i = 0; i < num; i++)
        {
            var flower = Convert.ToInt32(input[i]);
            while (flower % 2 == 0 || flower % 3 == 2)
            {
                flower--;
                result++;
            }
        }
        Console.WriteLine(result);
        
    }
}