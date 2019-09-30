using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;


public class C
{
	public static void Main()
	{
		string[] args;
		
		args = Console.ReadLine().Split(' ');
		int N = Int32.Parse(args[0]);
		int Q = Int32.Parse(args[1]);
		
		string S = Console.ReadLine();
		int[] csum = new int[N+1];
		csum[0] = 0;
		
		int counter = 0;
		bool aFlag = false;
		for(int i = 0; i < N; i++)
		{			
			switch(S[i])
			{
				case 'A':
					aFlag = true;
					break;
					
				case 'C':
					if(aFlag)
						counter++;					
					aFlag = false;
					break;
					
				default:
					aFlag = false;
					break;
			}
			csum[i+1] = counter;
		}
		
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < Q; i++)
		{
			args = Console.ReadLine().Split(' ');
			int l = Int32.Parse(args[0]);
			int r = Int32.Parse(args[1]);
			sb.AppendLine((csum[r] - csum[l]).ToString());
		}
		Console.WriteLine(sb);			
	}
}