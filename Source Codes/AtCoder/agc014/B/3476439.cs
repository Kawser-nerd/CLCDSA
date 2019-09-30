using System;
using System.Collections.Generic;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[] h=new int[s[0]+1];
		string ans="YES";
		for(int i=0;i<s[1];i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			h[q[0]]++;
			h[q[1]]++;
		}
		for(int i=0;i<s[0];i++){
			if(h[i]%2==1){ans="NO";break;}
		}
		Console.WriteLine(ans);
	}
}