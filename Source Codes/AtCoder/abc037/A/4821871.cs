using System;
using System.Linq;
class Program
{
    static void Main()
    {
        double[] input = Console.ReadLine().Split().Select(i => double.Parse(i)).ToArray();
        //int a=int.Parse(Console.ReadLine());
        //string a = Console.ReadLine();
        int max = 0;
        for(int a = 0; a <= (int)input[2] / (int)input[0]; a++)
        {
            if (max<a+(int)((input[2]-a*input[0])/input[1]))
            {
                max = a + (int)((input[2] - a * input[0]) / input[1]);
            }
        }
        Console.WriteLine(max);
        Console.ReadLine();
    }
}