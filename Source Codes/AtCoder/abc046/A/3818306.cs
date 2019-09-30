using System;
    using System.Linq;
     
    public class Test
    {
    	public static void Main()
    	{
    		string[] str = Console.ReadLine().Split(' ');
    		string[] ans = str.Distinct().ToArray();
    		Console.WriteLine(ans.Length);
    	}
    }