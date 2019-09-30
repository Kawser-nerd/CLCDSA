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
		
		int[] TT = new int[K+1];
		int[] La = new int[K+1];
		int[] Lv = new int[K+1];
		int[] Ra = new int[K+1];
		int[] Rv = new int[K+1];
		
		for(int i=1;i<=K;i++){
			TT[i] = R[i - 1];
		}
		
		La[0] = 0;
		Lv[0] = 0;
		Ra[0] = X;
		Rv[0] = X;
		for(int i=1;i<=K;i++){
			int lose = TT[i] - TT[i-1];
			int l = Lv[i-1] - lose;
			La[i] = La[i-1];
			if(l <= 0) La[i] += (-l);
			Lv[i] = X - Math.Max(0, l);
			
			int r = Rv[i-1] - lose;
			Ra[i] = Ra[i-1];
			if(r <= 0) Ra[i] -= (-r);
			Rv[i] = X - Math.Max(0, r);
			
		}
		
//		Console.WriteLine(String.Join("\t",La));
//		Console.WriteLine(String.Join("\t",Lv));
//		Console.WriteLine(String.Join("\t",Ra));
//		Console.WriteLine(String.Join("\t",Rv));
		
		int[] ans = new int[Q];
		for(int q=0;q<Q;q++){
			int t = T[q];
			int a = A[q];
			
			int l = 0;
			int r = K + 1;
			while(r - l > 1){
				int c = (l + r) / 2;
				if(TT[c] <= t){
					l = c;
				} else {
					r = c;
				}
			}
			
			int iniTime = l;
			int lose = t - TT[iniTime];
			
			int iniValue = 0;
			if(Lv[iniTime] == Rv[iniTime]){
				iniValue = Lv[iniTime];
			} else {
				if(a <= La[iniTime]){
					iniValue = Lv[iniTime];
				} else if(a >= Ra[iniTime]){
					iniValue = Rv[iniTime];
				} else {
					if(Lv[iniTime] < Rv[iniTime]){
						iniValue = Lv[iniTime] + (a - La[iniTime]);
					} else {
						iniValue = Lv[iniTime] - (a - La[iniTime]);
					}
				}
			}
			
			ans[q] = iniTime % 2 == 0 ? Math.Max(0, iniValue - lose) : Math.Max(0, X -Math.Max(0, iniValue - lose));
		}
		
		
		Console.WriteLine(String.Join("\n",ans));
	}
	int X;
	int K;
	int[] R;
	int Q;
	int[] T;
	int[] A;
	
	
	public Sol(){
		X = ri();
		K = ri();
		R = ria();
		Q = ri();
		T = new int[Q];
		A = new int[Q];
		for(int i=0;i<Q;i++){
			var d = ria();
			T[i] = d[0]; A[i] = d[1];
		}
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