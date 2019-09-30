using System;
using System.Linq;
 
class Amondai
{
    static void Main()
    {
        var num = Console.ReadLine().Split(' ').Select(x => Int64.Parse(x)).ToArray();
        var max = num[0] < num[1] ? num[1] : num[0];
        var min = max == num[0] ? num[1] : num[0];
        var ans = -1L;
        var line1 = Console.ReadLine().ToCharArray();
        var line2 = Console.ReadLine().ToCharArray();
        if (line1[0] != line2[0])
        {
            Console.WriteLine(ans);
            return;
        }
        ans = GetS(max, min);
        if (max * min != ans)
        {
            var kankaku1 = ans / num[0];
            var kankaku2 = ans / num[1];
            var kankaku = GetS(kankaku1, kankaku2);
            for (long i = kankaku; i < ans; i += kankaku)
            {
                if (line1[i / kankaku1] != line2[i / kankaku2])
                {
                    ans = -1;
                    break;
                }
            }
        }
        Console.WriteLine(ans);
    }
 
    static long GetS(long max, long min)
    {
        var r = 0L;
        var a = max;
        var b = min;
        while ((r = max % min) != 0)
        {
            max = min;
            min = r;
        }
        return a * b / min;
    }
}