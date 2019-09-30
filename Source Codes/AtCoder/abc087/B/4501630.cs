using System;

class Program
{
    static void Main()
    {
		var A = int.Parse(Console.ReadLine());
        var B = int.Parse(Console.ReadLine());
        var C = int.Parse(Console.ReadLine());
        var X = int.Parse(Console.ReadLine());
        var answer = 0;
        for (int a=0; a<=A; a++)
        {
            for (int b=0; b<=B; b++)
            {
                for(int c=0; c<=C; c++)
                {
                    if ( a*500 + b*100 +c*50 == X ) answer += 1;
                }
            }
        }
        Console.WriteLine(answer);
    }
}