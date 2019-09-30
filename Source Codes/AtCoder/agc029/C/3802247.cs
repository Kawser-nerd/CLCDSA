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
		
		
		int l = 0, r = N;
		while(r - l > 1){
			int c = (r + l) / 2;
			if(!isOK(c)){
				l = c;
			} else {
				r = c;
			}
		}
		Console.WriteLine(r);
	}
	
	bool isOK(int k){
		if(k == 0) return false;
		if(k == 1){
			for(int i=0;i<N-1;i++) if(A[i] >= A[i+1]) return false;
			return true;
		}
		
		int[] a = new int[33];
		
		for(int i=1;i<N;i++){
			
			if(A[i] >=33) continue;
			if(A[i] > A[i-1]){
				for(int j=A[i];j<33;j++){
					a[j] = 0;
				}
			} else if(A[i] == A[i-1]){
				a[A[i]]++;
				for(int j=A[i];j>0;j--){
					if(a[j] >= k){
						a[j] -= k;
						a[j-1] += 1;
					}
				}
				if(a[0] != 0) return false;
			} else {
				for(int j=A[i] + 1;j<33;j++) a[j] = 0;
				a[A[i]]++;
				for(int j=A[i];j>0;j--){
					if(a[j] >= k){
						a[j] -= k;
						a[j-1] += 1;
					}
				}
				if(a[0] != 0) return false;
			}
		}
		
		return true;
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