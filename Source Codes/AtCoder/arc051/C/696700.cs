using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class TEST{
	static void Main(){
		Sol mySol =new Sol();
		mySol.Solve();
	}
}

class Sol{
	public void Solve(){
		if(a==1){
			Array.Sort(A);
			for(int i=0;i<N;i++){
				Console.WriteLine(A[i]);
			}
			return;
		}
		
		int cnt=0;
		int[] Count=new int[N];
		double[] LA=new double[N];
		for(int i=0;i<N;i++){
			LA[i]=Math.Log((double)A[i],2);
		}
		while(cnt<b){
			double max=-1e9;
			double min=1e9;
			int idx=-1;
			for(int i=0;i<N;i++){
				if(LA[i]<min){
					min=LA[i];
					idx=i;
				}
				if(LA[i]>max){
					max=LA[i];
				}
			}
			if(max-min<Math.Log(a,2))break;
			LA[idx]+=Math.Log(a,2);
			Count[idx]++;
			cnt++;
		}
//Console.WriteLine(String.Join(" ",Count));		
		if(cnt<b){
			int rest=(int)(b-cnt);
			for(int i=0;i<N;i++){
				Count[i]+=rest/N;
				cnt+=rest/N;
				LA[i]+=(rest/N)*Math.Log(a,2);
			}
//Console.WriteLine(String.Join(" ",Count));		
			rest=rest%N;
			while(rest>0){
				double max=-1e9;
				double min=1e9;
				int idx=-1;
				for(int i=0;i<N;i++){
					if(LA[i]<min){
						min=LA[i];
						idx=i;
					}
					if(LA[i]>max){
						max=LA[i];
					}
				}
				LA[idx]+=Math.Log(a,2);
				Count[idx]++;
				cnt++;
				rest--;
			}
		}
//Console.WriteLine(String.Join(" ",Count));		
		
		Pair[] P=new Pair[N];
		for(int i=0;i<N;i++){
			P[i]=new Pair(i,Count[i],LA[i]);
		}
		Array.Sort(P,(p,q)=>p.LA.CompareTo(q.LA));
		for(int i=0;i<N;i++){
			Console.WriteLine("{0}",(A[P[i].Idx]*ModPow(a,P[i].Count))%mod);
		}
		
		
		
		
	}
	
	class Pair{
		public int Idx;
		public int Count;
		public double LA;
		public Pair(int idx,int count,double la){
			Idx=idx;Count=count;LA=la;
		}
	}
	
	static long mod=(long)1e9+7;
	static long ModPow(long n,long k){
		
		if(k==0)return 1;
		if(n==0)return 0;
		long ret=1;
		long x=n;
		while(k>0){
			if((k&1)==1){ret*=x;ret%=mod;}
			
			x*=x;x%=mod;
			k>>=1;
		}
		return ret;
		
	}
	
	
	long[] A;
	long a,b;
	int N;
	public Sol(){
		var d=rla();
		N=(int)d[0];a=d[1];b=d[2];
		A=rla();
	}

	static String rs(){return Console.ReadLine();}
	static int ri(){return int.Parse(Console.ReadLine());}
	static long rl(){return long.Parse(Console.ReadLine());}
	static double rd(){return double.Parse(Console.ReadLine());}
	static String[] rsa(char sep=' '){return Console.ReadLine().Split(sep);}
	static int[] ria(char sep=' '){return Array.ConvertAll(Console.ReadLine().Split(sep),e=>int.Parse(e));}
	static long[] rla(char sep=' '){return Array.ConvertAll(Console.ReadLine().Split(sep),e=>long.Parse(e));}
	static double[] rda(char sep=' '){return Array.ConvertAll(Console.ReadLine().Split(sep),e=>double.Parse(e));}
}