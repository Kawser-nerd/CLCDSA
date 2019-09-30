using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var wigth = Convert.ToInt32(input[0]);
        var height = Convert.ToInt32(input[1]);

        var ratio = (double)wigth / height;
        if (ratio == (double)4/3) Console.WriteLine("4:3");
        else Console.WriteLine("16:9");
    }
}