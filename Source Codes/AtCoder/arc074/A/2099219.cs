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
		
		long min = (long) 1e18;
		for(int t=0;t<2;t++){
		
			for(long x=1;x<=H;x++){
				long[] s = new long[3];
				s[0] = x * W;
				s[1] = (H - x) * (W / 2);
				s[2] = H * W - s[0] - s[1];
				
				Array.Sort(s);
				min = Math.Min(s[2] - s[0], min);
				
				s[0] = x * W;
				s[1] = ((H - x) / 2) * W;
				s[2] = H * W - s[0] - s[1];
				
				Array.Sort(s);
				min = Math.Min(s[2] - s[0], min);
			}
			
			var tmp = H; H = W; W = tmp;
		}
		Console.WriteLine(min);
		
		
	}
	long H,W;
	public Sol(){
		var d = rla();
		H = d[0]; W = d[1];
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