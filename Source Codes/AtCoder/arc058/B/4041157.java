import java.io.*;
import java.util.*;

public class Main implements Runnable{
	public static void main (String[] args) {new Thread(null, new Main(), "_cf", 1 << 28).start();}

	int MOD = (int)1e9+7;
	int[] fact, invFact;

	public void run() {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		System.err.println("Go!");

		int H = fs.nextInt(), W = fs.nextInt();
		int A = fs.nextInt(), B = fs.nextInt();
		
		fact = new int[H+W+100];
		invFact = new int[fact.length];
		for(int i = 0; i < fact.length; i++) {
			if(i == 0) {
				fact[i] = 1;
				invFact[i] = power(fact[i], MOD-2);
				continue;
			}
			fact[i] = (int)(((long)fact[i-1]*i) % MOD);
			invFact[i] = power(fact[i], MOD-2);
		}
		
		int[] row = new int[W];
		for(int i = B; i < W; i++) {
			int ways = nChoosek(H-A-1+i, H-A-1);
			row[i] = ways;
		}
		int res = 0;
		for(int i = B; i < W; i++) {
			long ways = nChoosek(A - 1+ W-i-1, A - 1);
			long add = ways * row[i] % MOD;
			res += (int)add;
			res %= MOD;
		}
		out.println(res);
		out.close();
	}
	
	int nChoosek(int n, int k) {
		long den = (long)invFact[k] * invFact[n-k];
		den %= MOD;
		long res = (long)fact[n] * den;
		return (int)(res%MOD);
	}

	int power(long x, long y) {
		x %= MOD;
		long res = 1;
		while(y > 0) {
			if(y%2 == 1) {
				res = (res * x) % MOD;
				y--;
			}
			x = (x * x) % MOD;
			y /= 2;
		}
		return (int)res;
	}

	class FastScanner {
		public int BS = 1<<16;
		public char NC = (char)0;
		byte[] buf = new byte[BS];
		int bId = 0, size = 0;
		char c = NC;
		double num = 1;
		BufferedInputStream in;

		public FastScanner() {
			in = new BufferedInputStream(System.in, BS);
		}

		public FastScanner(String s) throws FileNotFoundException {
			in = new BufferedInputStream(new FileInputStream(new File(s)), BS);
		}

		public char nextChar(){
			while(bId==size) {
				try {
					size = in.read(buf);
				}catch(Exception e) {
					return NC;
				}                
				if(size==-1)return NC;
				bId=0;
			}
			return (char)buf[bId++];
		}

		public int nextInt() {
			return (int)nextLong();
		}

		public long nextLong() {
			num=1;
			boolean neg = false;
			if(c==NC)c=nextChar();
			for(;(c<'0' || c>'9'); c = nextChar()) {
				if(c=='-')neg=true;
			}
			long res = 0;
			for(; c>='0' && c <='9'; c=nextChar()) {
				res = (res<<3)+(res<<1)+c-'0';
				num*=10;
			}
			return neg?-res:res;
		}

		public double nextDouble() {
			double cur = nextLong();
			return c!='.' ? cur:cur+nextLong()/num;
		}

		public String next() {
			StringBuilder res = new StringBuilder();
			while(c<=32)c=nextChar();
			while(c>32) {
				res.append(c);
				c=nextChar();
			}
			return res.toString();
		}

		public String nextLine() {
			StringBuilder res = new StringBuilder();
			while(c<=32)c=nextChar();
			while(c!='\n') {
				res.append(c);
				c=nextChar();
			}
			return res.toString();
		}

		public boolean hasNext() {
			if(c>32)return true;
			while(true) {
				c=nextChar();
				if(c==NC)return false;
				else if(c>32)return true;
			}
		}

		public int[] nextIntArray(int n) {
			int[] res = new int[n];
			for(int i = 0; i < n; i++) res[i] = nextInt();
			return res;
		}

	}

}