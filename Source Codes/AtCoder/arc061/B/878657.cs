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
		
		
		long[] sum = new long[10];
		sum[0] = (H-2)*(W-2);
		HashSet<long> Hs = new HashSet<long>();
		for(int i=0;i<N;i++){
			
			for(int rc=-2;rc<=0;rc++){
				if(!InRange(rc+A[i],1,H))continue;
				if(!InRange(rc+A[i]+2,1,H))continue;
				for(int cc=-2;cc<=0;cc++){
					if(!InRange(cc+B[i],1,W))continue;
					if(!InRange(cc+B[i]+2,1,W))continue;
					
					long br = A[i] + rc;
					long bc = B[i] + cc;
					int cnt = 1;
					for(int ii=0;ii<3;ii++){
						for(int jj=0;jj<3;jj++){
							if(br+ii == A[i] && bc+jj == B[i])continue;
							if(Hs.Contains(enc(br+ii,bc+jj)))cnt++;
						}
					}
					sum[cnt]++;
					sum[cnt-1]--;
				}
			}
			Hs.Add(enc(A[i],B[i]));
		}
		
		for(int i=0;i<10;i++){
			Console.WriteLine(sum[i]);
		}
		
	}
	long H;
	long W;
	int N;
	long[] A,B;
	
	bool InRange(long n,long l,long u){
		return l <= n && n <= u ;
	}
	
	long enc(long r,long c){ return (r*1000000200L)+c ;}
	long decR(long s){ return s/1000000200L;}
	long decC(long s){ return s%1000000200L;}
	
	public Sol(){
		var d = ria();
		H = d[0]; W = d[1]; N = d[2];
		A = new long[N];
		B = new long[N];
		for(int i=0;i<N;i++){
			var dd = rla();
			A[i] = dd[0];
			B[i] = dd[1];
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