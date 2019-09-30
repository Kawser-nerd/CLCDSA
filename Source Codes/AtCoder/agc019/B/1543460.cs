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
		int[] cnt = new int[26];
		for(int i=0;i<N;i++){
			cnt[S[i] - 'a']++;
		}
		
		long ans = 0;
		for(int i=0;i<26;i++){
			for(int j=i+1;j<26;j++){
				ans += (long)cnt[i] * (long) cnt[j];
			}
		}
		Console.WriteLine(ans+1);
	}
	
	String S;
	public Sol(){
		S = rs();
	}
	
	int[] Manachar(List<char> L){
		int[] Ret=new int[L.Count];
		int i=0;
		int j=0;
		while(i<L.Count){
			while(i-j>=0 && i+j <L.Count && L[i-j]==L[i+j])++j;
			Ret[i]=j;
			int k=1;
			while(i-k>=0 && i+k <L.Count && k+Ret[i-k]<j){Ret[i+k]=Ret[i-k];++k;}
			i+=k;j-=k;
		}
		return Ret;
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