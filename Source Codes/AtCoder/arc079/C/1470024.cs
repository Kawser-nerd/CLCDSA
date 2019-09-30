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
		
		
		long cnt = 0;
		while(true){
			Array.Sort(A);
			Array.Reverse(A);
//Console.WriteLine(String.Join(" ",A) + ":" + cnt);
			if(A[0] <= N-1){
				Console.WriteLine(cnt);
				return;
			}
			if(A[0] < 3*N){
				cnt++;
				A[0] -= N;
				for(int i=1;i<N;i++){
					A[i]++;
				}
				continue;
			}
			
			if(A[0] - A[N-1] < N){
				cnt += N * (A[N-1] - N);
				long di = A[N-1] - N;
				for(int i=0;i<N;i++) A[i] -= di;
				continue;
			}
			
			int mem = 1;
			for(int i=1;i<N;i++){
				if(A[0] - A[i] < N){
					mem++;
					continue;
				}
				break;
			}
			if(mem == N){
				cnt++;
				A[0] -= N;
				for(int i=1;i<N;i++){
					A[i]++;
				}
				continue;
			}
			
			int l = mem-1;
			int r = mem;
			long diff = A[l] - A[r];
			long k = diff / (N+1);
//Console.WriteLine("diff: {0} , k:{1},cnt:{2},mem:{3}",diff,k,cnt,mem);
			if(k == 0){
				cnt++;
				A[0] -= N;
				for(int i=1;i<N;i++){
					A[i]++;
				}
				continue;
			}
			cnt += mem * k;
			for(int i=0;i<N;i++){
				if(i < mem){
					A[i] -= k * N;
					A[i] += (mem - 1) * k;
				} else {
					A[i] += k * mem;
				}
			}
			
			
		}
	}
	int N;
	long[] A;
	public Sol(){
		N = ri();
		A = rla();
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