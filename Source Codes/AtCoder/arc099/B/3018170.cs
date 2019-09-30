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
		
		long N = 1;
		List<long> ans = new List<long>();
		for(;ans.Count < K;){
			ans.Add(N);
			N = f(N + 1);
		}
		
		Console.WriteLine(String.Join("\n", ans));
		
		
	}
	
	long f(long n){
		char[] ca = String.Format("{0:D016}",n).ToCharArray();
		List<long> L = new List<long>();
		for(int i=ca.Length - 1;i>=0;i--){
			L.Add(long.Parse(new String(ca)));
			ca[i] = '9';
		}
		
		long minn = L[0];
		long mind = ds(L[0]);
		
		for(int i=0;i<L.Count;i++){
			long vn = L[i];
			long vd = ds(L[i]);
			if(vn  * mind < minn * vd){
				minn = vn;
				mind = vd;
			}
		}
		
		return minn;
	}
	
	long ds(long v){
		long ret = 0;
		while(v > 0){
			ret += v % 10;
			v /= 10;
		}
		return ret;
	}
	
	
	int K;
	public Sol(){
		K = ri();
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