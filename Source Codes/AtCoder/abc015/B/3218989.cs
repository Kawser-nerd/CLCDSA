using System;

class Program
{
    static void Main(string[] args)
    {
        var num = Convert.ToInt32(Console.ReadLine());
        var input = Console.ReadLine().Split(' ');
        var ave = 0;
        for(var i = 0; i < input.Length; i++)
        {
            if (input[i] == "0") num--;
            ave += Convert.ToInt32(input[i]);
        }
        if (ave / num == (double)ave / num) Console.WriteLine(ave / num);
        else Console.WriteLine(ave / num + 1);
    }
}