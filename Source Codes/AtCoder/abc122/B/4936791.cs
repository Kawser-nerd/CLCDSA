using System;
using System.Collections.Generic;


public class B
{	
	public static void Main()
	{
		string S = Console.ReadLine();
		
		int result = 0;
		int counter = 0;
		for(int i = 0; i < S.Length; i++)
		{
			switch(S[i])
			{
				case 'A':
				case 'C':
				case 'G':
				case 'T':
					counter++;
					break;
				
				default:					
					counter = 0;
					break;
			}
			result = Math.Max(result, counter);
		}
		Console.WriteLine(result);
	}
}