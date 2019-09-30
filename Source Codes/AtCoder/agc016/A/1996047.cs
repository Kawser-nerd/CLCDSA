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
		int N = S.Length;
		var h = new HashSet<char>();
		for(int i=0;i<N;i++) h.Add(S[i]);
		
		int min = N + 1;
		foreach(var c in h){
			int cnt = 0;
			var ca = S.ToCharArray();
			while(true){
				bool chk = true;
				for(int i=0;i<ca.Length;i++){
					chk &= ca[i] == c;
				}
				if(chk){
					break;
				}
				cnt++;
				var nca = new char[ca.Length - 1];
				for(int i=0;i<nca.Length;i++){
					if(ca[i] == c || ca[i+1] == c){
						nca[i] = c;
					} else {
						nca[i] = ca[i];
					}
				}
				ca = nca;
			}
			min = Math.Min(cnt, min);
		}
		
		
		
		
		Console.WriteLine(min);
		
	}
	String S;
	public Sol(){
		S = rs();
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