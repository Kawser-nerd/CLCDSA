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
		
		List<long> candi = new List<long>();
		for(long i=1;i<=999;i++) candi.Add(i);
		
		long keta = 10;
		long shimo = 9;
		
		for(long l=4;l<17;l++){
			for(long i=100;i<=999;i++){
				candi.Add(i * keta + shimo);
			}
			keta *= 10;
			shimo *= 10;
			shimo += 9;
		}
		
		int N = candi.Count;
		bool[] snuke = new bool[N];
		//double min = candi[N-1] / (double) candi[N-1].ToString().Select(c => c - '0').Sum();
		long minn = candi[N-1];
		long mind = candi[N-1].ToString().Select(c => c - '0').Sum();
		
		for(int i=N-2;i>=0;i--){
/*			double v = candi[i] / (double) candi[i].ToString().Select(c => c - '0').Sum();
			
			if(v <= min){
				snuke[i] = true;
				min = v;
			}
*/
			long vn = candi[i];
			long vd = candi[i].ToString().Select(c => c - '0').Sum();
			if(vn * mind <= minn * vd){
				snuke[i] = true;
				minn = vn; mind = vd;
			}
			
			
		}
		
		List<long> ans = new List<long>();
		for(int i=0;ans.Count < K;i++){
			if(!snuke[i]) continue;
			ans.Add(candi[i]);
		}
		
		Console.WriteLine(String.Join("\n",ans));
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