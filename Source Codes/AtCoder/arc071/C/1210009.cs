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
		int M = T.Length;
		var BTSA = new BIT(N);
		var BTSB = new BIT(N);
		var BTTA = new BIT(N);
		var BTTB = new BIT(N);
		for(int i=0;i<N;i++){
			if(S[i] == 'A') BTSA.Add(i+1,1);
			if(S[i] == 'B') BTSB.Add(i+1,1);
		}
		for(int i=0;i<M;i++){
			if(T[i] == 'A') BTTA.Add(i+1,1);
			if(T[i] == 'B') BTTB.Add(i+1,1);
		}
		
		int[][] jud = new int[3][];
		jud[0] = new int[]{0,-1,1};
		jud[1] = new int[]{1,0,-1};
		jud[2] = new int[]{-1,1,0};
		
		
		var sbd = new StringBuilder();
		for(int q=0;q<Q;q++){
			int a = Query[q][0];
			int b = Query[q][1];
			int c = Query[q][2];
			int d = Query[q][3];
			int sa = BTSA.Sum(b) - BTSA.Sum(a-1);
			int sb = BTSB.Sum(b) - BTSB.Sum(a-1);
			int ta = BTTA.Sum(d) - BTTA.Sum(c-1);
			int tb = BTTB.Sum(d) - BTTB.Sum(c-1);
			
			sa %= 3;
			sb %= 3;
			ta %= 3;
			tb %= 3;
			
			if(jud[sa][sb] == jud[ta][tb]){
				sbd.AppendLine("YES");
			} else {
				sbd.AppendLine("NO");
			}
		}
		Console.Write(sbd.ToString());
	}
	
	String S,T;
	int Q;
	int[][] Query;
	public Sol(){
		S = rs();
		T = rs();
		Q = ri();
		Query = new int[Q][];
		for(int i=0;i<Q;i++) Query[i] = ria();
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
class BIT{
	int MM;
	int n;
	long[] bit;
	public BIT(int n_){
		n=n_;
		MM=1<<18;
		while(MM<n*2)MM<<=1;
		bit=new long[MM+1];
	}
	//1-origin!!
	public void Add(int i,int x){
		while(i<=n){
			bit[i]+=x;
			i+=(i&-i);
		}
	}
	
	// i=>sum(a_1,...,a_i)
	// i=0 -> return 0;
	public int Sum(int i){
		long s=0;
		while(i>0){
			s+=bit[i];
			i-= (i&-i);
		}
		return (int)s;
	}
}