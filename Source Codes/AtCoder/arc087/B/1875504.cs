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
		
		var ss = S.Split('T').ToArray();
		List<int> xa = new List<int>();
		List<int> ya = new List<int>();
		for(int i=0;i<ss.Length;i++){
			if(i % 2 == 0) xa.Add(ss[i].Length);
			if(i % 2 == 1) ya.Add(ss[i].Length);
		}
		
		var H = new HashSet<int>();
		H.Add(xa[0]);
		for(int i=1;i<xa.Count;i++){
			var nxt = new HashSet<int>();
			foreach(var k in H){
				nxt.Add(k + xa[i]);
				nxt.Add(k - xa[i]);
			}
			H = nxt;
		}
		if(!H.Contains(X)){
			Console.WriteLine("No");
			return;
		}
		
		H = new HashSet<int>();
		H.Add(0);
		for(int i=0;i<ya.Count;i++){
			var nxt = new HashSet<int>();
			foreach(var k in H){
				nxt.Add(k + ya[i]);
				nxt.Add(k - ya[i]);
			}
			H = nxt;
		}
		if(!H.Contains(Y)){
			Console.WriteLine("No");
			return;
		}
		
		Console.WriteLine("Yes");
		
		
		
	}
	String S;
	int X,Y;
	public Sol(){
		S = rs();
		var d = ria();
		X = d[0]; Y = d[1];
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