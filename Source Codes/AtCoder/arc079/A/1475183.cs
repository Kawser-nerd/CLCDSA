using System;
using System.Linq;

public class Test
{
	public static void Main()
	{
		// your code goes here
	int []n=Console.ReadLine().Split().Select(int.Parse).ToArray();
	int []a=new int[n[0]];
	for(int i=0;i<n[1];i++){
    int []s=Console.ReadLine().Split().Select(int.Parse).ToArray();
    if(s[0]==1){a[s[1]-1]+=3;}
    if(s[1]==n[0]){a[s[0]-1]+=2;}
	}
	for(int i=0;i<a.Length;i++){
		if(a[i]==5){Console.WriteLine("POSSIBLE");return;}
	}	
{Console.WriteLine("IMPOSSIBLE");}
	
	
	}
}