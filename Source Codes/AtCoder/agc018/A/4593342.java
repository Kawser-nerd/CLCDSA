import java.util.*;
import java.io.*;
import java.math.*;

public class Main {

	void solve (FastScanner in, PrintWriter out) {

		int n = in.nextInt(), k = in.nextInt();
		int[] balls = new int[n];

		int max = Integer.MIN_VALUE;
		for (int i=0; i<n; i++) {
			balls[i] = in.nextInt();
			max = Math.max(max, balls[i]);
		}
		
		out.println(k<=max && k%gcdAll(balls)==0? "POSSIBLE" : "IMPOSSIBLE");

	}

	static BigInteger bigFactorial (int n) {
		BigInteger[] ar = new BigInteger[n];
		for (int i=0; i<n; i++) {
			ar[i] = BigInteger.valueOf(i+1);
		}
		int t = 1, length = ar.length;
		while (t <= length) {
			for (int i=0; i<length; i+=(t<<1)) {
				if (t+i < length) {
					ar[i] = ar[i].multiply(ar[i+t]);
					ar[i+t] = null;
				}
			}
			System.gc();
			t = t<<1;
		}
		return ar[0];
	}

	static int gcdAll (int... ar) {
		int t = 1, length = ar.length;
		while (t <= length) {
			for (int i=0; i<length; i+=(t<<1)) {
				if (t+i < length) {
					//ar[i], ar[i+t] ?gcd
					int temp;
					while ((temp=ar[i]%ar[i+t]) != 0) {
						ar[i] = ar[i+t];
						ar[i+t] = temp;
					}
					ar[i] = ar[i+t];
				}
			}
			t = t<<1;
		}
		return ar[0];
	}

	static int gcd (int a, int b) {return b>0?gcd(b,a%b):a;}
	static int lcm (int a, int b) {return a/gcd(a,b)*b;}


	void print (Object... ar) {
		System.out.println(Arrays.deepToString(ar));
	}

	public static void main(String[] args) {
		FastScanner in = new FastScanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		Main main = new Main();
		main.solve(in, out);
		in.close();
		out.close();
	}

	static class FastScanner {

		private InputStream in;
		private byte[] buffer = new byte[1024];
		private  int length = 0, p = 0;

		public FastScanner (InputStream stream) {
			in = stream;
		}
		public boolean hasNextByte () {
			if (p < length) return true;
			else {
				p = 0;
				try {length = in.read(buffer);}
				catch (Exception e) {e.printStackTrace();}
				if (length <= 0) return false;
			}
			return true;
		}
		public int readByte () {
			if (hasNextByte() == true) return buffer[p++];
			return -1;
		}
		public boolean isPrintable (int n) {return 33<=n&&n<=126;}
		public void skip () {
			while (hasNextByte() && !isPrintable(buffer[p])) p++;
		}
		public boolean hasNext () {skip(); return hasNextByte();}
		public String next () {
			if (!hasNext()) throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int t = readByte();
			while (isPrintable(t)) {
				sb.appendCodePoint(t);
				t = readByte();
			}
			return sb.toString();
		}
		public String[] nextArray (int n) {
			String[] ar = new String[n];
			for (int i=0; i<n; i++) ar[i] = next();
			return ar;
		}
		public int nextInt () {return Math.toIntExact(nextLong());}
		public int[] nextIntArray (int n) {
			int[] ar = new int[n];
			for (int i=0; i<n; i++) ar[i] = nextInt();
			return ar;
		}
		public long nextLong () {
			if (!hasNext()) throw new NoSuchElementException();
			boolean minus = false;
			int temp = readByte();
			if (temp == '-') {
				minus = true;
				temp = readByte();
			}
			if (temp<'0' || '9'<temp) throw new NumberFormatException();
			long n = 0;
			while (isPrintable(temp)) {
				if ('0'<=temp && temp<='9') {
					n *= 10;
					n += temp - '0';
				}
				else throw new NumberFormatException();
				temp = readByte();
			}
			return minus? -n : n;
		}
		public double nextDouble () {
			return Double.parseDouble(next());
		}
		public void close () {
			try {in.close();}
			catch(Exception e){}
		}
	}

}