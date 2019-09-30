using System;
using System.Collections;
using System.Linq;


public class Test
{
	public static double n = 0;
	public static double ans = 0;
	public static string str = "";
	public static void Main()
	{
		str = Console.ReadLine();
		string s = "";

		tansaku(0,s);
		Console.WriteLine(ans);
	}
	public static void tansaku (int i ,string s)
	{
		if(i == str.Length-1){
			keisan(s);
		}
		else
		{
			tansaku(i+1, s+"0");
			tansaku(i+1, s+"1");
		}
	}
	
	public static void keisan (string s)
	{
		string str2 = "";
		char[] nums = str.ToCharArray();	
		char[] c = s.ToCharArray();

		str2 += nums[0].ToString();

		for(int i = 0 ; i < c.Length ; i++)
		{
			if(c[i]== '1')
			{	

				ans += double.Parse(str2);
				str2 = "";
			}
			str2 += nums[i+1].ToString();
		}

		ans += double.Parse(str2);
	//	Console.WriteLine(ans);
	}
}