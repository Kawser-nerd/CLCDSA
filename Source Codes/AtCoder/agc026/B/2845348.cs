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
		
		for(;T>0;T--){
			Read();
			var chk = Check();
			Console.WriteLine(chk ? "Yes" : "No");
		}
	}
	
	bool Check(){
		long a = A, b = B, c = C, d = D;
		
		if(b > a){
			return false;
		}
		a -= b;
//Console.WriteLine("a:{0}",a);		
		if(a > c){
			a -= (((a - c) + b - 1)/b) * b;
		}
//Console.WriteLine("a:{0}",a);		
		
		if(a < 0) return false;
//Console.WriteLine("1");
		//if(a <= C - D) return false;
//Console.WriteLine("2");
		if(D < B) return false;
		//if(D == B) return true;
		
		var unit = gcd(D, B);
//Console.WriteLine("unit:{0}",unit);
		a += (((C - a + 1) + unit - 1)/unit) * unit;
//Console.WriteLine("a:{0}",a);		
		return (a - B >= Math.Max(0,C - D));
		
	}
	
	long gcd (long a, long b){
		return a == 0 ? b : gcd(b % a, a);
	}
	
	void Read(){
		var d = rla();
		A = d[0]; B = d[1]; C = d[2]; D = d[3];
	}
	
	int T;
	long A, B, C, D;
	public Sol(){
		T = ri();
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