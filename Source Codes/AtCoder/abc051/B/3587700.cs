using System;
using System.Collections;
using System.Linq;


public class Test
{
	public static void Main()
	{
		string[] str = Console.ReadLine().Split(' ');
		int max = int.Parse(str[0]);
		int mokuhyou = int.Parse(str[1]);
		int cnt = 0;

		for(int i = 0 ; i <= max ; i++){
			for(int j = 0 ; j <= max ; j++){
				if(mokuhyou - i - j <= max && mokuhyou - i - j >= 0){
					cnt++;
				}
			}
		}
		
		Console.WriteLine(cnt);
	}
}