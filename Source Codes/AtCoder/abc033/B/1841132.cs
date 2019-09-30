using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

public class Program
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        string[] s = new string[n];
        int[] num = new int[n];

        string[] str;
        for (int i = 0; i < n; i++) {
            str = Console.ReadLine().Split(' ');
            s[i] = str[0];
            num[i] = int.Parse(str[1]);
        }

        int max = num.Sum();
        string ans = "atcoder";
        for (int i = 0; i < n; i++) {
            if (max < num[i] * 2) {ans = s[i]; break; }
        }
        Console.WriteLine(ans);
    }

}