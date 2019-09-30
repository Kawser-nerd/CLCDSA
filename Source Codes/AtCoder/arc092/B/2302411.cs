using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;

class TEST{
	static void Main(){
		Sol mySol =new Sol();
		mySol.Solve();
	}
}

class Sol{
	public void Solve(){
		
		int[] ans = new int[29];
		Parallel.For(0,29,p => {
			int[] a = new int[N];
			int[] b = new int[N];
			for(int i=0;i<N;i++){
				int mask = (1 << (p + 1)) - 1;
				a[i] = A[i] & mask;
				b[i] = B[i] & mask;
			}
			Array.Sort(b);
			
			long cnt = 0;
			int l0 = 1 << p;
			int r0 = l0 + (1 << p);
			int l1 = r0 + (1 << p);
			int r1 = l1 + (1 << p);
//Console.WriteLine("{0} {1} {2} {3}",l0,r0,l1,r1);
//Console.WriteLine("a:{0}",String.Join(" ",a));
//Console.WriteLine("b:{0}",String.Join(" ",b));
			
			foreach(var na in a){
				int l = 0, r = N;
				int li0 = 0, ri0 = 0, li1 = 0, ri1 = 0;
				
				if(na + b[0] >= l0){
					li0 = -1;
				} else {
					l = 0; r = N;
					while(r - l > 1){
						int c = (l + r) / 2;
						if(na + b[c] < l0){
							l = c;
						} else {
							r = c;
						}
					}
					li0 = l;
				}
				
				if(na + b[0] >= r0){
					ri0 = -1;
				} else {
					l = 0; r = N;
					while(r - l > 1){
						int c = (l + r) / 2;
						if(na + b[c] < r0){
							l = c;
						} else {
							r = c;
						}
					}
					ri0 = l;
				}
				
				if(ri0 != -1 && ri0 > li0) cnt += ri0 - li0;
				
				if(na + b[0] >= l1){
					li1 = -1;
				} else {
					l = 0; r = N;
					while(r - l > 1){
						int c = (l + r) / 2;
						if(na + b[c] < l1){
							l = c;
						} else {
							r = c;
						}
					}
					li1 = l;
				}
				
				if(na + b[0] >= r1){
					ri1 = -1;
				} else {
					l = 0; r = N;
					while(r - l > 1){
						int c = (l + r) / 2;
						if(na + b[c] < r1){
							l = c;
						} else {
							r = c;
						}
					}
					ri1 = l;
				}
				
				if(ri1 != -1 && ri1 > li1) cnt += ri1 - li1;
				cnt &= 1;
//Console.WriteLine("na:{0}, li0:{1}, ri0:{2}, li1:{3}, ri1:{4}",na, li0, ri0, li1, ri1);
				
			}
			
			ans[p] = ((int)(cnt % 2) << p);
//Console.WriteLine("{0} {1}",cnt, ans);
			
		});
		Console.WriteLine(ans.Sum());
/*		
		List<long> dbg = new List<long>();
		foreach(var x in A) foreach(var y in B) dbg.Add(x + y);
		long v = 0;
		foreach(var xy in dbg) v ^= xy;
		Console.WriteLine(v);
*/		
		
	}
	int N;
	int[] A,B;
	public Sol(){
		using( var r = new FastIn()){
			N = r.ReadInt();
			A = new int[N];
			for(int i=0;i<N;i++) A[i] = r.ReadInt();
			B = new int[N];
			for(int i=0;i<N;i++) B[i] = r.ReadInt();
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
	public uint ReadUint() {
		uint ret = 0;
		uint sig = 1;
		while (ptr < rsize && Mem[ptr] != ' ' && Mem[ptr] != '\n' && Mem[ptr] != '\r' ) {
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
	
	public double ReadDouble() {
		double ret = 0;
		double sig = 1;
		bool dot = false;
		double keta = 0.1;
		while (ptr < rsize && Mem[ptr] != ' ' && Mem[ptr] != '\n' && Mem[ptr] != '\r' ) {
			if(ret==0 && Mem[ptr] == '-'){
				sig *= -1; ptr++;
				if (ptr == Size) Next();
				continue;
			}
			if(Mem[ptr] == '.'){
				dot = true;
				ptr++;
				if (ptr == Size) Next();
				continue;
			}
			if(!dot){
				ret = ret * 10 + Mem[ptr++] - '0';
				if (ptr == Size) Next();
			}else{
				ret = ret + (Mem[ptr++] - '0')*keta;
				keta /= 10.0;
				if (ptr == Size) Next();
			}
		}
		while (ptr < rsize && (Mem[ptr] == ' ' || Mem[ptr] == '\n' || Mem[ptr] == '\r') ) {
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