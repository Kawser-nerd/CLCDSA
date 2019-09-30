using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

public class Program
{
    public static void Main()
    {
        //int[] num = Console.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
        //int[] num_ = Console.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
        string s = Console.ReadLine();
        int num = int.Parse(Console.ReadLine());
        Console.WriteLine(s[num % 5 == 0 ? num / 5 - 1 : num / 5] + "" + s[(num - num / 5 * 5 == 0 ? 4 : num - num / 5 * 5 - 1)]);
    }

}