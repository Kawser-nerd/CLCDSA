using System;
using System.Linq;
public class Hello{
    public static void Main()
    {
        // Your code here!
        int[] s = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
        int A = s[0];
        int B = s[1];
        int C = s[2];
        int D = s[3];
        int ans = -1;
        if(D <= A || B <= C) ans = 0;
        else if((C <= A && A <= D) && D <= B) ans = D - A;
        else if(A <= C && D <= B) ans = D - C;
        else if((A <= C && C <= B) && B <= D) ans = B - C;
        else if(C <= A && B <= D) ans = B - A;
        
        Console.WriteLine(ans);
    }
}