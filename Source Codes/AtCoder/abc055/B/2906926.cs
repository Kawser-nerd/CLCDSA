using System;
using System.Linq;
using System.Collections.Generic;

public class Test
{
    
	public static void Main()
	{
        int n = int.Parse(Console.ReadLine());
        long ans = 1;
        long divide = 1000000007;
        for(int i = 1; i <= n ; i++){
            ans = i * ans % divide;
        }
        Console.WriteLine(ans);
    }                                                                                                                                   
}