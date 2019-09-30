import java.io.*;
import java.util.*;

public class Main implements Runnable{
	public static void main (String[] args) {new Thread(null, new Main(), "_cf", 1 << 28).start();}

	int res;

	public void run() {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		System.err.println("Go!");

		int n = fs.nextInt();
		int x = fs.nextInt();
		boolean[] bad = new boolean[10];
		for(int i = 0; i < x; i++) bad[fs.nextInt()] = true;

		res = Integer.MAX_VALUE;
		find("", n, bad);
		out.println(res);
		out.close();
	}

	void find(String s, int n, boolean[] bad) {
		if(s.length() > 0) {
			int parse = Integer.parseInt(s);
			if(parse >= n) {
				res = Math.min(res, parse);
				return;
			}
		}
		for(int i = 0; i < bad.length; i++) if(!bad[i]) {
			if(i == 0 && s.length() > 0) {
				find(s + "" + i, n, bad);
			}
			else if(i > 0) {
				find(s + "" + i, n, bad);
			}
		}
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