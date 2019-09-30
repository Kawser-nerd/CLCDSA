using System;
using System.Collections.Generic;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[][] arr=new int[s[1]][];
		int[,] t=new int[s[0]+1,3];
		List<int> li=new List<int>();
		for(int i=0;i<s[1];i++){arr[i]=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}
		Array.Sort(arr,ca1);
		int q=int.Parse(Console.ReadLine());
		int[][] b=new int[q][];
		for(int i=0;i<q;i++){b[i]=Array.ConvertAll((i+" "+Console.ReadLine()+" 0").Split(),int.Parse);}
		Array.Sort(b,ca1);
		int p=0;
		
		for(int i=0;i<s[1];i++){
			while(p<q&&b[p][2]>=arr[i][2]){
				int j;
				for(j=b[p][1];t[j,0]!=0;j=t[j,0]){li.Add(j);}
				while(li.Count>0){
					t[li[0],0]=j;
					li.RemoveAt(0);
				}
				b[p][3]=t[j,2]+1;
				p++;
			}
			int n,m;
			for(n=arr[i][0];t[n,0]!=0;n=t[n,0]){li.Add(n);}
			for(m=arr[i][1];t[m,0]!=0;m=t[m,0]){li.Add(m);}
			while(li.Count>0){
				t[li[0],0]=n;
				li.RemoveAt(0);
			}
			if(n==m){continue;}
			if(t[n,1]<t[m,1]){n^=m;m^=n;n^=m;}
			t[m,0]=n;
			t[n,2]+=t[m,2]+1;
			t[n,1]=Math.Max(t[n,1],t[m,1]+1);
		}
		while(p<q){
			int j;
			for(j=b[p][1];t[j,0]!=0;j=t[j,0]){li.Add(j);}
			while(li.Count>0){
				t[li[0],0]=j;
				li.RemoveAt(0);
			}
			b[p][3]=t[j,2]+1;
			p++;
		}
		Array.Sort(b,ca2);
		for(int i=0;i<q;i++){Console.WriteLine("{0}",b[i][3]);}
	}
	static int ca1(int[] a,int[] b){
		if(a[2]<b[2]){return 1;}
		else if(a[2]>b[2]){return -1;}
		else{return 0;}
	}
	static int ca2(int[] a,int[] b){
		if(a[0]>b[0]){return 1;}
		else if(a[0]<b[0]){return -1;}
		else{return 0;}
	}
}