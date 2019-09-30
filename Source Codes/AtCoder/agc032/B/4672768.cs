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
		if(N == 3){
			Console.WriteLine(2);
			Console.WriteLine("1 3");
			Console.WriteLine("2 3");
			return;
		}
		if(N % 2 == 0){
			int[][] a = new int[N][];
			for(int i=0;i<N;i++) a[i] = new int[N];
			for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(i != j) a[i][j] = 1;
			for(int i=0;i<N;i++) a[i][N-1-i] = 0;
			int cnt = 0;
			for(int i=0;i<N;i++) for(int j=i+1;j<N;j++) cnt += a[i][j];
			Console.WriteLine(cnt);
			for(int i=0;i<N;i++){
				for(int j=i+1;j<N;j++){
					if(a[i][j] == 1) Console.WriteLine("{0} {1}",i+1, j+1);
				}
			}
		} else {
			int[][] a = new int[N][];
			for(int i=0;i<N;i++) a[i] = new int[N];
			for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(i != j) a[i][j] = 1;
			for(int i=0;i<N-1;i++) a[i][N-2-i] = 0;
			int cnt = 0;
			for(int i=0;i<N;i++) for(int j=i+1;j<N;j++) cnt += a[i][j];
			Console.WriteLine(cnt);
			for(int i=0;i<N;i++){
				for(int j=i+1;j<N;j++){
					if(a[i][j] == 1) Console.WriteLine("{0} {1}",i+1, j+1);
				}
			}
		}
	}
	int N;
	public Sol(){
		N = ri();
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