using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

class TEST{
	static void Main(){
		int T=int.Parse(Console.ReadLine());
		for(int i=1;i<=T;i++){
			Sol mySol =new Sol(i);
			mySol.Solve();
		}
	}
}

class Sol{
	public void Solve(){
		int N=ri();
		List<Pair> L=new List<Pair>();
		for(int i=0;i<N;i++){
			var d=ria();
			int s=d[0];
			int nn=d[1];
			int m=d[2];
			for(int j=0;j<nn;j++)L.Add(new Pair(s,m+j));
		}
		
		L.Sort((x,y)=>
			x.Strt>y.Strt?1:(x.Strt<y.Strt?-1:(x.M>y.M?-1:x.M<y.M?1:0))
			);//‹ß‚¢‡A’x‚¢‡
		
		if(L[0].M==L[1].M){
			Console.WriteLine(0);
			return;
		}
		if(L[0].M<L[1].M){//Žè‘O‚ª‘¬‚¢
			double t=(double)(L[1].Strt-L[0].Strt)/(360.0/L[0].M-360.0/L[1].M);
			if(t*360.0/L[1].M+L[1].Strt>360){
				Console.WriteLine(0);
				return;
			}
			double rest=360.0-(t*360.0/L[1].M+L[1].Strt);
			double t2=360.0/(360.0/L[0].M-360.0/L[1].M);
			if(rest<t2*(360.0/L[1].M)){
				Console.WriteLine(0);
				return;
			}else{
				Console.WriteLine(1);
				return;
			}
		}
		
		double dist=360-(L[1].Strt-L[0].Strt);
		double t3=dist/(360.0/L[1].M-360.0/L[0].M);
		if(L[0].Strt+t3*(360.0/L[0].M)>360.0){
			Console.WriteLine(0);
			return;
		}
		Console.WriteLine(1);
		
		
		
		
		
		
	}
	class Pair{
		public int Strt;
		public int M;
		public Pair(int s,int m){
			Strt=s;M=m;
		}
	
	
	}
	public Sol(int T){
		Console.Write("Case #{0}: ",T);
	}




	static String rs(){return Console.ReadLine();}
	static int ri(){return int.Parse(Console.ReadLine());}
	static long rl(){return long.Parse(Console.ReadLine());}
	static double rd(){return double.Parse(Console.ReadLine());}
	static String[] rsa(){return Console.ReadLine().Split(' ');}
	static int[] ria(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>int.Parse(e));}
	static long[] rla(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>long.Parse(e));}
	static double[] rda(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>double.Parse(e));}

}

struct Pair{
	public char C;
	public int N;
	public Pair(char c,int n){
		this.N=n;
		this.C=c;
	}
}