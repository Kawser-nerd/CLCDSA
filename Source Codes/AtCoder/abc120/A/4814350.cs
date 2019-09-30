using System;
using System.Linq;
class Program
{
    static void Main()
    {
        int ans;
        int[] input = Console.ReadLine().Split().Select(i=>int.Parse(i)).ToArray();
        if (input[1]/input[0]>input[2])
        {
            ans = input[2];
        }
        else
        {
            ans = (input[1] / input[0]);
        }
        Console.WriteLine(ans);
        Console.ReadLine();
    }
}