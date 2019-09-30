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
		
		Array.Sort(A);
		int cnt = 0;
		int a = (A[2] - A[0]) / 2;
		cnt += a;
		A[0] += 2 * a;
		int b = (A[2] - A[1]) / 2;
		A[1] += 2 * b;
		cnt += b;
		
		int min = A.Min();
		for(int i=0;i<3;i++) A[i] -= min;
		
		int sum = A.Sum();
		if(sum == 1){
			cnt += 1;
		} else if(sum == 2){
			cnt += 2;
		}
		Console.WriteLine(cnt);
		
	}
	int[] A;
	public Sol(){
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