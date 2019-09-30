using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var dor = Convert.ToInt32(input[0]);
        var need = Convert.ToInt32(input[1]);
        
        for(var i = 1; i < int.MaxValue; i++)
        {
            if (dor * i >= need)
            {
                Console.WriteLine(i);break;
            }
        }
    }
}