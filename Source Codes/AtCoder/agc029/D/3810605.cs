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
		
		
		List<int>[] wall = new List<int>[W];
		for(int i=0;i<W;i++) wall[i] = new List<int>();
		for(int i=0;i<N;i++){
			wall[Y[i]].Add(X[i]);
		}
		for(int i=0;i<W;i++){
			wall[i].Sort();
			wall[i].Add(H);
		}
		
		
		int[] ptr = new int[W];
		int min = (H - 1) + 1;
		int r = 0, c = 0;
		int taka = 0;
		while(true){
//Console.WriteLine("{0} {1} {2}",r,c,taka);
			while(c < W && wall[c][ptr[c]] <= r) ptr[c]++;
			bool act = false;
			if(wall[c][ptr[c]] > r + 1){
				act = true;
				r++;
				taka++;
				min = Math.Min(min, taka + wall[c][ptr[c]] - r - 1 + 1);
			} else if(wall[c][ptr[c]] == r + 1){
				min = Math.Min(min, taka + wall[c][ptr[c]] - r - 1 + 1);
				break;
			}
			while(c + 1 < W && wall[c + 1][ptr[c + 1]] < r) ptr[c + 1]++;
			if(c + 1 < W && wall[c + 1][ptr[c + 1]] != r){
				c++;
				act = true;
			}
			if(!act) break;
		}
		Console.WriteLine(min);
	}
	
	int H,W;
	int N;
	int[] X,Y;
	public Sol(){
		var d = ria();
		H = d[0]; W = d[1];
		N = d[2];
		X = new int[N];
		Y = new int[N];
		for(int i=0;i<N;i++){
			d = ria();
			X[i] = d[0] - 1; Y[i] = d[1] - 1;
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