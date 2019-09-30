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
		
		long[] B = new long[] {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
		int NB = B.Length;
		
		bool[] yn = new bool[NB];
		for(int i=0;i<NB;i++){
			Console.WriteLine("? {0}",B[i]);
			Console.Out.Flush();
			var ret = Console.ReadLine();
			yn[i] = ret == "Y" ? true : false;
		}
		
		bool one = true;
		for(int i=0;i<NB;i++) one &= yn[i];
		if(one){
			bool[] yn2 = new bool[NB];
			for(int i=0;i<NB;i++){
				Console.WriteLine("? {0}",2 * B[i]);
				Console.Out.Flush();
				var ret = Console.ReadLine();
				yn2[i] = ret == "Y" ? true : false;
			}
			int idx = 0;
			for(int i=0;i<NB;i++){
				if(yn2[i]){ idx = i; break;}
			}
			Console.WriteLine("! {0}",B[idx]);
			return;
		}
		
		int lidx = -1;
		for(int i=0;i<NB;i++){
			if(yn[i]) lidx = i;
		}
		
		int N = lidx + 1;
		int[] ans = new int[N];
		for(int i=0;i<N-1;i++){
			int l = i == 0 ? 1 : 0;
			int r = 10;
			while(r - l > 1){
				int c = (l+r) / 2;
				ans[i] = c;
				String s = String.Join("",ans).Substring(0,N-1);
				Console.WriteLine("? {0}",s);
				Console.Out.Flush();
				var res = Console.ReadLine();
				if(res == "Y"){
					l = c;
				} else {
					r = c;
				}
			}
			ans[i] = l;
		}
		
		bool[] yn3 = new bool[10];
		for(int i=0;i<10;i++){
			if(N == 1 && i == 0) continue;
			ans[N-1] = i;
			String s = String.Join("",ans).Substring(0,N) + "0";
			Console.WriteLine("? {0}",s);
			Console.Out.Flush();
			var res = Console.ReadLine();
			if(res == "Y"){
				Console.WriteLine("! {0}",String.Join("",ans));
				return;
			}
		}
		
		
	}

	public Sol(){
		
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