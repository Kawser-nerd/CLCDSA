using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

public class Hello
{
    public static void Main()
    {
        int[] n = Console.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
        int box = 0;
        int ans = 0;
        int end = 0;
        for (int i = 0; i < n[0]; i++)
        {
            box = int.Parse(Console.ReadLine());
            if (end <= box)
            {
                //???????
                ans += n[1];
                end = box + n[1];
            }
            else if (box < end)
            {
                //???????
                ans += box - (end - n[1]);
                end = box + n[1];
            }
        }
        Console.WriteLine(ans);
    }
}