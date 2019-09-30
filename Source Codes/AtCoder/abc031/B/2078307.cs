using System;
using System.Linq;
class Program
{
    public static void Main()
    {
        string[] str = Console.ReadLine().Split(' ');
        int l = int.Parse(str[0]);
        int h = int.Parse(str[1]);
        int n = int.Parse(Console.ReadLine());
        int a, ans;
        int[] answer = new int[n];
        for (int i = 0; i < n; i++)
        {
            a = int.Parse(Console.ReadLine());
            ans = (a > h) ? -1 : (l <= a) ? 0 : l - a;
            answer[i] = ans;
        }
        for (int i = 0; i < n; i++)
            Console.WriteLine(answer[i]);
    }
}