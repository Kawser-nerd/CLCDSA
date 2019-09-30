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
		
		var ca = new char[H][];
		for(int i=0;i<H;i++){
			ca[i] = S[i].ToCharArray();
		}
		
		for(int j=0;j<W;j++){
			for(int i=1;i<H;i++){
				if(ca[i][j] == '?'){
					ca[i][j] = ca[i-1][j];
				}
			}
		}
		
		for(int j=0;j<W;j++){
			for(int i=H-2;i>=0;i--){
				if(ca[i][j] == '?'){
					ca[i][j] = ca[i+1][j];
				}
			}
		}
		for(int j=1;j<W;j++){
			if(ca[0][j] == '?'){
				for(int i=0;i<H;i++){
					ca[i][j] = ca[i][j-1];
				}
			}
		}
		for(int j=W-2;j>=0;j--){
			if(ca[0][j] == '?'){
				for(int i=0;i<H;i++){
					ca[i][j] = ca[i][j+1];
				}
			}
		}
		
		Console.WriteLine();
		for(int i=0;i<H;i++){
			Console.WriteLine(new String(ca[i]));
		}
		
		
		
		
	}
	int H,W;
	String[] S;
	public Sol(int T){
		Console.Write("Case #{0}: ",T);
		var d = ria();
		H = d[0]; W = d[1];
		S = new String[H];
		for(int i=0;i<H;i++) S[i] = rs();
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