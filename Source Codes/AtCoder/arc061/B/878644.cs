using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
class TEST{
	static void Main(){
		Sol mySol =new Sol();
		mySol.Solve();
	}
}

class Sol{
	public void Solve(){
		
		long m = (long)1e9+200; 
		
		int[] sum = new int[10];
		HashSet<long> Hs = new HashSet<long>();
		HashSet<long> Hp = new HashSet<long>();
		for(int i=0;i<N;i++){
			Hp.Add(A[i]*m+B[i]);
			for(int ii=-2;ii<=0;ii++){
				if(!InRange(A[i]+ii,1,H-2))continue;
				for(int jj=-2;jj<=0;jj++){
					if(!InRange(B[i]+jj,1,W-2))continue;
					Hs.Add((A[i]+ii)*m+(B[i]+jj));
				}
			}
		}
		
		foreach(var sq in Hs){
			long r = sq/m;
			long c = sq%m;
			int cnt = 0;
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(Hp.Contains((r+i)*m+(c+j))){
						cnt++;
					}
				}
			}
			sum[cnt]++;
		}
		
		long[] ans = new long[10];
		for(int i=0;i<10;i++){
			ans[i] = sum[i];
		}
		ans[0] = ((long)H-2)*((long)W-2);
		for(int i=1;i<10;i++)ans[0] -= ans[i];
		
		
		
		for(int i=0;i<10;i++){
			Console.WriteLine(ans[i]);
		}
		
	}
	long H;
	long W;
	int N;
	long[] A,B;
	
	static bool InRange(long n,long l,long u){
		return l <= n && n <= u ;
	}
	
	static long enc(int r,int c){ return ((long)r<<32)+(long)c ;}
	static int decR(long s){ return (int)(s>>32);}
	static int decC(long s){ return (int)(s&0xFFFFFFFF);}
	
	public Sol(){
		using(var r = new FastIn(1000000)){
			
			H = r.ReadInt(); W = r.ReadInt(); N = r.ReadInt();
			A = new long[N];
			B = new long[N];
			for(int i=0;i<N;i++){
				A[i] = r.ReadInt();
				B[i] = r.ReadInt();
			}
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

class FastIn:IDisposable {
	int Size;
	byte[] Mem;
	int ptr;
	int rsize;
	bool unfinished;
	Stream stdin;
	void Init(int n) {
		Size = n;
		Mem = new byte[Size];
		rsize=(stdin=Console.OpenStandardInput()).Read(Mem, 0, Size);
		ptr = 0;
		unfinished=(rsize == Size);
	}
	void Next() {
		if (unfinished == false) return;
		rsize=stdin.Read(Mem, 0, Size);
		ptr = 0;
		unfinished = (rsize == Size);
	}
	
	~FastIn(){
		stdin.Dispose();
	}
	void IDisposable.Dispose(){
		stdin.Dispose();
	}
	public void Dispose(){
		stdin.Dispose();
	}
	
	public FastIn() {
		Init(100000);
	}
	public FastIn(int n) {
		Init(n);
	}
	public int ReadInt() {
		int ret = 0;
		int sig = 1;
		while (ptr < rsize && Mem[ptr] != ' ' && Mem[ptr] != '\n' && Mem[ptr] != '\r' ) {
			if(ret==0 && Mem[ptr] == '-'){
				sig *= -1; ptr++; continue;
			}
			ret = ret * 10 + Mem[ptr++] - '0';
			if (ptr == Size) Next();
		}
		while (ptr < rsize && (Mem[ptr] == ' ' || Mem[ptr] == '\n' || Mem[ptr] == '\r') ) {
			ptr++;
			if (ptr == Size) Next();
		}
		return ret*sig;
	}
	public long ReadLong() {
		long ret = 0;
		long sig = 1;
		while (ptr < rsize && Mem[ptr] != ' ' && Mem[ptr] != '\n' && Mem[ptr] != '\r' ) {
			if(ret==0 && Mem[ptr] == '-'){
				sig *= -1; ptr++; continue;
			}
			ret = ret * 10 + Mem[ptr++] - '0';
			if (ptr == Size) Next();
		}
		while (ptr < rsize &&  (Mem[ptr] == ' ' || Mem[ptr] == '\n' || Mem[ptr] == '\r')  ) {
			ptr++;
			if (ptr == Size) Next();
		}
		return ret*sig;
	}
	public String ReadStr() {
		//2byte???NG
		StringBuilder sb = new StringBuilder();
		while (ptr < rsize && Mem[ptr] != ' ' && Mem[ptr] != '\n' && Mem[ptr] != '\r') {
			sb.Append((char)Mem[ptr++]);
			if (ptr == Size && unfinished) Next();
		}
		while (ptr < rsize &&  (Mem[ptr] == ' ' || Mem[ptr] == '\n' || Mem[ptr] == '\r') ) {
			ptr++;
			if (ptr == Size && unfinished) Next();
		}
		return sb.ToString();
	}
	public String ReadLine() {
		//??????(split/parse?????????????
		StringBuilder sb = new StringBuilder();
		while (ptr < rsize && Mem[ptr] != '\n' && Mem[ptr] != '\r') {
			sb.Append((char)Mem[ptr++]);
			if (ptr == Size && unfinished) Next();
		}
		while (ptr < rsize &&  (Mem[ptr] == ' ' || Mem[ptr] == '\n' || Mem[ptr] == '\r')) {
			ptr++;
			if (ptr == Size && unfinished) Next();
		}
		return sb.ToString();
	}
}