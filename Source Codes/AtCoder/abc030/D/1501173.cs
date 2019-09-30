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
		
		int[] vis = new int[N];
		for(int i=0;i<N;i++) vis[i] = -1;
		int peri = 0;
		int lpstart = 0;
		int now = A;
		var L = new List<int>();
		
		for(int i=0;i<N+2;i++){
			if(vis[now] == -1){
				L.Add(now);
				vis[now] = i;
				now  = B[now];
				continue;
			}
			lpstart = vis[now];
			peri = i - vis[now];
			break;
		}
		//Console.WriteLine(String.Join(" ",L));
		if(K.Length < 8){
			int kl = int.Parse(K);
			if(kl < L.Count){
				Console.WriteLine(L[kl] + 1);
				return;
			}
		}
		
		long mm = 0;
		long keta = 1;
		for(int i=K.Length-1;i>=0;i--){
			mm += (keta * (K[i] - '0'));
			mm %= peri;
			keta *= 10;
			keta %= peri;
		}
		
		mm = (mm - lpstart) % peri;
		if(mm < 0) mm += peri;
		Console.WriteLine(L[(int)mm + lpstart] + 1);
		
		
	}
	int N,A;
	String K;
	int[] B;
	public Sol(){
		var d = ria();
		N = d[0]; A = d[1] - 1;//0-indexed
		K = rs();
		B = ria();
		for(int i=0;i<N;i++) B[i] = B[i] - 1;//0-indexed
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