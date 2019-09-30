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
		
		double maxP = -1;
		int mWater = 0, mSolt = 0;
		
		for(int i=0;i*100*A <= F;i++){
			for(int j=0;j*100*B <= F; j++){
				int water = i * 100 * A + j * 100 * B;
				if(water > F) break;
				int maxSolt = (i*A + j*B) * E;
				for(int k=0;k*C <= maxSolt;k++){
					for(int l=0;l*D <= maxSolt;l++){
						int solt = k*C + l*D;
						if(solt > maxSolt) break;
						if(solt + water > F) break;
						if(maxP < (solt / (double)(water + solt))){
							mWater = water;
							mSolt = solt;
							maxP = (solt / (double)(water + solt));
						}
					
					}
				}
			}
		}
		Console.WriteLine("{0} {1}",mSolt+mWater ,mSolt);
		
		
		
		
		
		
	}
	int A,B,C,D,E,F;
	public Sol(){
		var d = ria();
		A = d[0]; B = d[1]; C = d[2]; D = d[3]; E = d[4]; F  = d[5];
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