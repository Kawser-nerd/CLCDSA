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
		int N,K;
		var d = ria();
		N = d[0]; K =d[1];
		double[] P = rda();
		
		double max =0.0;
		int[] BCnt=new int[1<<N];
		for(int i=0;i<(1<<N);i++){
			for(int j=0;j<25;j++){
				if(((i>>j)&1)==1)BCnt[i]++;
			}
		}
		
		
		for(int s=0;s<(1<<N);s++){
			if(BCnt[s]!=K)continue;
			List<double> L = new List<double>();
			for(int j=0;j<N;j++){
				if(((s>>j)&1)==1){
					L.Add(P[j]);
				}
			}
			double p = 0.0;
			for(int ss = 0;ss<(1<<K);ss++){
				if(BCnt[ss] != K/2)continue;
				double p0 = 1;
				for(int k=0;k<K;k++){
					if(((ss>>k)&1)==0){
						p0 *= (1.0 - L[k]);
					}else{
						p0 *= L[k];
					}
				}
				p+=p0;
			}
			
			max = Math.Max(max,p);
		}
		
		Console.WriteLine("{0:F6}",max);
		
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