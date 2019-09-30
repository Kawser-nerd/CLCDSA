using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

public class Program
{
    public static void Main()
    {
        int[] num = Console.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
        //string s = Console.ReadLine();
        //int num = int.Parse(Console.ReadLine());
        Array.Sort(num);
        Console.WriteLine(num[0] == num[1] ? num[2] : num[0]);
    }

}