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
		
		int[][] pr = new int[][]{
			new int[]{2,3,5},
			new int[]{2,3,7},
			new int[]{3,5,7},
			new int[]{2,3,11}
		};
		
		foreach(var ar in pr){
			int a = ar[0], b = ar[1], c = ar[2];
			List<long> l = new List<long>();
			for(long i=2;;i++){
				if(i % a == 0|| i % b == 0 || i % c == 0) l.Add(i);
				if(l.Count == N - 1) break;
			}
			
			var sum = l.Sum();
			for(long last = l[l.Count - 1] + 1;;last++){
				if(last > 30000) break;
				if((sum + last) % (a * b * c) == 0 && gcd(sum, last) != 1){l.Add(last); break;}
			}
			if(l.Count == N){
				Console.WriteLine(String.Join(" ",l));
				return;
			}
		}
	}
	
	int N;
	public Sol(){
		N = ri();
	}
	long gcd(long a, long b){
		if(a > b) return gcd(b , a);
		return a == 0 ? b : gcd(b % a, a);
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