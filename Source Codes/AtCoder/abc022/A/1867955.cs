using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

public class Program
{
    public static void Main()
    {
        //int num = int.Parse(Console.ReadLine());
        int[] num = Console.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
        //string s = Console.ReadLine();
        //string s_ = Console.ReadLine();
        int count = 0;
        int W = 0;
        for (int i = 0; i < num[0]; i++) {
            W += int.Parse(Console.ReadLine());
            if (num[1] <= W && W <= num[2]) count++;
        }
        Console.WriteLine(count);
    }

}