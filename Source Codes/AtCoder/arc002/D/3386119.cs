using System;
using System.Collections.Generic;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		char[][] a=new char[s[0]][];
		char c;
		var hs=new Dictionary<char,int[]>();
		hs.Add('o',new int[]{0,0,0,10000});
		hs.Add('x',new int[]{0,0,0,10000,0});
		List<int[]> li=new List<int[]>();
		for(int i=0;i<s[0];i++){
			a[i]=Console.ReadLine().ToCharArray();
			c='.';
			int q=0;
			for(int j=0;j<s[1];j++){
				if(a[i][j]!='.'){
					if(c=='x'&&a[i][j]=='x'){hs['x'][2]+=hs['x'][4];}
					else if(c=='.'&&a[i][j]=='x'){hs['x'][3]=Math.Min(hs['x'][3],j);}
					else if(c=='o'&&a[i][j]=='x'){
						hs['o'][2]-=hs['o'][0]*(j-hs['o'][1]-1);
						q=j-hs['o'][1]-2;
					}
					else if(c=='x'&&a[i][j]=='o'){
						if(q>0){li.Add(new int[]{hs['o'][0],hs['x'][0],q});}
						hs['o'][0]=0;
						hs['x'][0]=0;
						hs['x'][4]=0;
					}
					c=a[i][j];
					hs[c][1]=j;
					hs[c][0]++;
				}
				else if(c=='o'){hs['o'][2]+=hs['o'][0];}
				else if(c=='x'){hs['x'][4]++;}
			}
			if(c=='o'){hs['o'][3]=Math.Min(hs['o'][3],s[1]-hs['o'][1]-1);}
			else{
				if(q>0){li.Add(new int[]{hs['o'][0],hs['x'][0],q});}
				hs['o'][0]=0;
				hs['x'][0]=0;
				hs['x'][4]=0;
			}
		}
		if(hs['o'][3]+hs['x'][3]!=20000){
			if(hs['o'][3]<=hs['x'][3]){Console.WriteLine("o");}
			else{Console.WriteLine("x");}
		}
		else{
			li.Sort((u,v)=>v[0]+v[1]-u[0]-u[1]);
			for(int i=0,j=0;i<li.Count;i++){
				if(j==0){
					hs['o'][2]+=(li[i][2]-li[i][2]/2)*li[i][0];
					hs['x'][2]+=li[i][2]/2*li[i][1];
				}
				else{
					hs['o'][2]+=li[i][2]/2*li[i][0];
					hs['x'][2]+=(li[i][2]-li[i][2]/2)*li[i][1];
				}
				if(li[i][2]%2==1){j^=1;}
			}
			if(hs['o'][2]>hs['x'][2]){Console.WriteLine("o");}
			else{Console.WriteLine("x");}
		}
	}
}