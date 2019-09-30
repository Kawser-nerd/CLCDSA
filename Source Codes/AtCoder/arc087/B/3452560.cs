using System;
using System.Collections.Generic;
class Program{
	static void Main(){
		string s=Console.ReadLine()+"X";
		int[] a=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		List<int>[] li=new List<int>[2];
		int[] g=new int[]{0,0};
		li[0]=new List<int>();
		li[1]=new List<int>();
		int k=0;
		bool b=false;
		for(int i=0,j=0;i<s.Length;i++){
			if(s[i]=='F'){j++;}
			else if(!b){
				g[0]=j;
				j=0;
				b=true;
			}
			else{
				li[k%2].Add(j);
				k++;
				j=0;
			}
		}
		li[0].Sort((u,v)=>v-u);
		li[1].Sort((u,v)=>v-u);
		for(int i=0;i<k;i++){
			if(a[(i%2)^1]>g[(i%2)^1]){g[(i%2)^1]+=li[i%2][i/2];}
			else{g[(i%2)^1]-=li[i%2][i/2];}
		}
		Console.WriteLine("{0}",(g[0]==a[0]&&g[1]==a[1])?"Yes":"No");
	}
}