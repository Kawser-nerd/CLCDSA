using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var prices = new int[3];
        for(var i = 0; i < 3; i++)
        {
            prices[i]= Convert.ToInt32(input[i]);
        }
        
        var max = Math.Max(prices[0], prices[1]);
        max = Math.Max(max, prices[2]);
        var result = 0;
        var isSame = false;
        for (var i = 0; i < 3; i++)
        {
            if (prices[i] == max && !isSame)
            {
                isSame = true; continue;
            }
            result+=prices[i];
        }
        Console.WriteLine(result);
    }
}