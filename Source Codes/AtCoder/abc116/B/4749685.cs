using System;


public class B
{	
	public static void Main()
	{	
		bool[] exist = new bool[1000001];  // false
		
		int s = Int32.Parse(Console.ReadLine());
		int a = s;
		exist[a] = true;
		for(int i = 2; ; i++)
		{
			a = ((a % 2) == 0) ? (a / 2) : (3 * a + 1);
			if(exist[a])
			{
				Console.WriteLine(i);
				break;
			}
			else
			{
				exist[a] = true;
			}			
		}
	}
}