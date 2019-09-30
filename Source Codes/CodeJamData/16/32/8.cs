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
		var d=rla();
		B=(int)d[0];
		M=d[1];
		if((1L<<(B-2))<M){
			Console.WriteLine("IMPOSSIBLE");
			return;
		}
		
		Console.WriteLine("POSSIBLE");
		int[][] A=new int[B][];
		for(int i=0;i<B;i++)A[i]=new int[B];
		
		for(int i=0;i<B-1;i++){
			for(int j=i+1;j<B;j++){
				A[i][j]=1;
			}
		}
		long minus=(1L<<(B-2))-M;
		for(int i=1;i<B;i++){
			if((minus&(1L<<(i-1)))>0){
				A[i][B-1]=0;
			}
		}
		for(int i=0;i<B;i++){
			Console.WriteLine(String.Join("",A[i]));
		}
		
		
		
		
	}
	int B;
	long M;
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