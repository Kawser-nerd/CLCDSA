using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        char[] s = Console.ReadLine().ToCharArray();
        int[] nums = new int[n + 1];
        for (int i = 1; i <= n; i++)
            nums[i] = nums[i - 1] + ((s[i - 1] == 'W') ? 1 : 0);
        int wn = s.Count(p => p == 'W');
        int ans = int.MaxValue;
        for (int i = 1; i <= n; i++)
            ans = Math.Min(ans, 2 * nums[i - 1] + n - i - wn + ((s[i - 1] == 'W') ? 1 : 0));
        Console.WriteLine(ans);
    }
}