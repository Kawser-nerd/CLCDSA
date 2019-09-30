using System;

public class Test
{
	public static void Main()
	{
		// your code goes here
	string a=Console.ReadLine();
	int ans=0;
	for(int i=0;i<a.Length;i++){
		char top=a[i];
		char at=i%2==0?'g':'p';
		if(at=='g'&&top=='p'){ans--;}
		else if(at=='p'&&top=='g'){ans++;}
	}
	Console.WriteLine(Math.Max(ans,0));
	
	}
}