import java.io.*;
import java.util.*;

public class Main implements Runnable{
	public static void main (String[] args) {new Thread(null, new Main(), "_cf", 1 << 28).start();}

	int MOD = (int)1e9+7;

	public void run() {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		System.err.println("Go!");

		int n = fs.nextInt();
		int c = fs.nextInt();
		int[][] ranges = new int[n][2];
		for(int i = 0; i < n; i++) {
			ranges[i][0] = fs.nextInt();
		}
		for(int i = 0; i < n; i++) {
			ranges[i][1] = fs.nextInt();
		}
		
		int[][] sums = new int[n][c+1];
		for(int i = 0; i < n; i++) {
			int[] curVals = new int[401];
			Arrays.fill(curVals, 1);
			sums[i][0] = ranges[i][1]-ranges[i][0]+1;
			for(int give = 1; give <= c; give++) {
				int sum = 0;
				for(int j = ranges[i][0]; j <= ranges[i][1]; j++) {
					curVals[j] = mult(curVals[j], j);
					sum = add(sum, curVals[j]);
				}
				sums[i][give] = sum;
			}
		}
		
		int oo = (int)2e9;
		int[][] dp = new int[c+1][n+1];
		for(int i = 0; i <= c; i++) {
			for(int j = 0; j <= n; j++) {
				dp[i][j] = 0;
			}
		}
		dp[0][n] = 1;
		for(int kid = n-1; kid >= 0; kid--) {
			for(int have = c; have >= 0; have--) {
				for(int give = 0; give <= have; give++) {
					int it = dp[have-give][kid+1];
					dp[have][kid] = add(dp[have][kid], mult(it, sums[kid][give]));
				}
			}
		}
		out.println(dp[c][0]);
		out.close();
	}
	
	int add(int a, int b) {
		a += b;
		a %= MOD;
		return a;
	}

	int mult(long a, long b) {
		a *= b;
		a %= MOD;
		return (int)a;
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