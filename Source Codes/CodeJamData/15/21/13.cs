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
		int x=ri();
		int[] A=new int[1000001];
		for(int i=0;i<=1000000;i++)A[i]=2000000;
		A[0]=0;
		A[1]=1;
		for(int i=1;i<1000000;i++){
			A[i+1]=Math.Min(A[i+1],A[i]+1);
			var ca=i.ToString().ToCharArray();
			Array.Reverse(ca);
			int r=int.Parse(new String(ca));
			A[r]=Math.Min(A[r],A[i]+1);
		}
		Console.WriteLine(A[x]);
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