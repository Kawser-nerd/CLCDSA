using System;
using System.Linq;
public class Hello
{
    public static void Main()
    {
        int[] s = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
        int A = s[0];
        int B = s[1];
        int C = s[2];
        bool can = false;
        for(int i = 1; i <= B; i++)
        {
            if(i * A % B == C) can = true;
        }
        
        if(can) Console.WriteLine("YES");
        else Console.WriteLine("NO");
    }
}