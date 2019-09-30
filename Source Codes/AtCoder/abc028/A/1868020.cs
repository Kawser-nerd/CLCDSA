using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

public class Program
{
    public static void Main()
    {
        //int[] num = Console.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
        //string s = Console.ReadLine();
        int num = int.Parse(Console.ReadLine());
        string ans = "";
        if (num < 60) ans = "Bad";
        else if (60 <= num && num < 90) ans = "Good";
        else if (90 <= num && num < 100) ans = "Great";
        else ans = "Perfect";
            Console.WriteLine(ans);
    }

}