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
		
		int diam = A.Max();
		int[] cnt = new int[diam + 1];
		for(int i=0;i<N;i++) cnt[A[i]]++;
		
		switch(diam % 2){
			
			case 0: {
				bool chk = true;
				for(int i=diam; i >= diam - diam / 2; i--){
					if(i > diam - diam / 2){
						chk &= cnt[i] >= 2;
					}
					if(i == diam - diam / 2){
						chk &= cnt[i] == 1;
					}
				}
				for(int i=diam - diam / 2 - 1; i >= 0; i--){
					chk &= cnt[i] == 0;
				}
				Console.WriteLine(chk ? "Possible" : "Impossible");
			
			} break;
			
			case 1: {
				bool chk = true;
				for(int i=diam; i >= diam - diam / 2; i--){
					if(i > diam - diam / 2){
						chk &= cnt[i] >= 2;
					}
					if(i == diam - diam / 2){
						chk &= cnt[i] == 2;
					}
				}
				for(int i=diam - diam / 2 - 1; i >= 0; i--){
					chk &= cnt[i] == 0;
				}
				Console.WriteLine(chk ? "Possible" : "Impossible");
			
			
			} break;
			
		}
		
	}
	int N;
	int[] A;
	public Sol(){
		N = ri();
		A = ria();
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