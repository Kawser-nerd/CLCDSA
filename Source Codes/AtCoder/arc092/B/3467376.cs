using System;
using System.Collections.Generic;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		int[] a=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[] b=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[] m=new int[n+1];
		Dictionary<int,int>[] hs=new Dictionary<int,int>[29];
		long ans=0;
		for(int i=0;i<29;i++){
			hs[i]=new Dictionary<int,int>();
			for(int j=0;j<n;j++){m[j]=b[j]%(1<<(i+1));}
			m[n]=int.MaxValue;
			Array.Sort(m);
			long t=(long)Math.Pow(2,i),o=0;
			for(int j=0;j<n;j++){
				int q=a[j]%(1<<(i+1));
				if(hs[i].ContainsKey(q)){o+=hs[i][q];}
				else{
					int[] h=new int[4];
					for(int k=1;k<=4;k++){
						int lb=-1,ub=n,mid=0;
						while(ub-lb>1){
							mid=(ub+lb)/2;
							if(m[mid]+q>t*k-(1)){ub=mid;}
							else{lb=mid;}
						}
						h[k-1]=ub;
					}
					hs[i].Add(q,h[1]-h[0]+h[3]-h[2]);
					o+=h[1]-h[0]+h[3]-h[2];
				}
			}
			ans|=(o%2)<<i;
		}
		Console.WriteLine("{0}",ans);
	}
}