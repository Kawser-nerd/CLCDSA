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
		
		int rr = R + O + V;
		int yy = Y + O + G;
		int bb = B + G + V;
		
		int maj = new int[]{rr,yy,bb}.Max();
		if(maj > (N/2)){
			Console.WriteLine("IMPOSSIBLE");
			return;
		}
		if(rr == maj){
			//int rr = R + O + V;
			//int yy = Y + O + G;
			//int bb = B + G + V;
			char[] res = new char[N];
			for(int i=0;i<N;i++) res[i] = '?';
			
			for(int i=0;i<R;i++){
				res[2*i] = 'R';
			}
			for(int i=0;i<O;i++){
				res[2*R + 2*i] = 'O';
			}
			for(int i=0;i<V;i++){
				res[2*R + 2*O + 2*i] = 'V';
			}
			for(int i=0;i<G;i++){
				res[1+ 2*i] = 'G';
			}
			if(Y > B){
				for(int i=0;i<(Y-B);i++){
					res[1+ 2*G + 2*i] = 'Y';
				}
				int bw = 0;
				for(int i=0;i<N;i++){
					if(res[i] != '?') continue;
					res[i] = bw == 0 ? 'B' : 'Y';
					bw ^= 1;
				}
			} else {
				for(int i=0;i<(B-Y);i++){
					res[1+ 2*G + 2*i] = 'B';
				}
				int bw = 0;
				for(int i=0;i<N;i++){
					if(res[i] != '?') continue;
					res[i] = bw == 0 ? 'Y' : 'B';
					bw ^= 1;
				}
			}
			
			Console.WriteLine(new String(res));
			return;
		}
		if(yy == maj){
			//int yy = Y + O + G;
			//int rr = R + O + V;
			//int bb = B + G + V;
			char[] res = new char[N];
			for(int i=0;i<N;i++) res[i] = '?';
			
			for(int i=0;i<Y;i++){
				res[2*i] = 'Y';
			}
			for(int i=0;i<O;i++){
				res[2*Y + 2*i] = 'O';
			}
			for(int i=0;i<G;i++){
				res[2*Y + 2*O + 2*i] = 'G';
			}
			for(int i=0;i<V;i++){
				res[1+ 2*i] = 'V';
			}
			if(R > B){
				for(int i=0;i<(R-B);i++){
					res[1+ 2*V + 2*i] = 'R';
				}
				int bw = 0;
				for(int i=0;i<N;i++){
					if(res[i] != '?') continue;
					res[i] = bw == 0 ? 'B' : 'R';
					bw ^= 1;
				}
			} else {
				for(int i=0;i<(B-R);i++){
					res[1+ 2*V + 2*i] = 'B';
				}
				int bw = 0;
				for(int i=0;i<N;i++){
					if(res[i] != '?') continue;
					res[i] = bw == 0 ? 'R' : 'B';
					bw ^= 1;
				}
			}
			
			Console.WriteLine(new String(res));
			return;
		}
		if(bb == maj){
			//int bb = B + G + V;
			//int yy = Y + O + G;
			//int rr = R + O + V;
			char[] res = new char[N];
			for(int i=0;i<N;i++) res[i] = '?';
			
			for(int i=0;i<B;i++){
				res[2*i] = 'B';
			}
			for(int i=0;i<G;i++){
				res[2*B + 2*i] = 'G';
			}
			for(int i=0;i<V;i++){
				res[2*B + 2*G + 2*i] = 'V';
			}
			for(int i=0;i<O;i++){
				res[1+ 2*i] = 'O';
			}
			if(Y > R){
				for(int i=0;i<(Y-R);i++){
					res[1+ 2*O + 2*i] = 'Y';
				}
				int bw = 0;
				for(int i=0;i<N;i++){
					if(res[i] != '?') continue;
					res[i] = bw == 0 ? 'R' : 'Y';
					bw ^= 1;
				}
			} else {
				for(int i=0;i<(R-Y);i++){
					res[1+ 2*O + 2*i] = 'R';
				}
				int bw = 0;
				for(int i=0;i<N;i++){
					if(res[i] != '?') continue;
					res[i] = bw == 0 ? 'Y' : 'R';
					bw ^= 1;
				}
			}
			
			Console.WriteLine(new String(res));
			return;		}
		
		
	}
	int N,R,O,Y,G,B,V;
	public Sol(int T){
		Console.Write("Case #{0}: ",T);
		var d = ria();
		N = d[0];
		R = d[1];
		O = d[2];
		Y = d[3];
		G = d[4];
		B = d[5];
		V = d[6];
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