using System;
using System.Collections;
using System.Collections.Generic;


public class A
{
	public static void Main()
	{
		char b = Console.ReadLine()[0];
		char result = '\0';
		switch(b)
		{
			case 'A':
				result = 'T';
				break;
				
			case 'C':
				result = 'G';
				break;
				
			case 'G':
				result = 'C';
				break;
				
			case 'T':
				result = 'A';
				break;
				
			default:
				throw new Exception();			
		}
			
		Console.WriteLine(result);
	}	
}