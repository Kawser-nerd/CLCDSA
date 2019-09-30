import java.util.*;
import java.io.*;
import java.math.*;

class Main {
	void solve () {
		
		int w = nextInt(), h = nextInt();
		int big = Math.max(w, h) - 1;
		int small = Math.min(w, h) - 1;
		
		BigInteger divisor = bigFactorial2(2, small-1);
		BigInteger dividend = bigFactorial2(big+1, small);
		
		BigInteger ans = dividend.divide(divisor);
		ans = ans.mod(BigInteger.valueOf(MOD));
		
		
		out.println(ans);


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
				}
			}
			t = t<<1;
		}
		return ar[0];
	}
	
	static BigInteger bigFactorial2 (int s, int leng) {
		BigInteger[] ar = new BigInteger[leng];
		for (int i=0; i<leng; i++) {
			ar[i] = BigInteger.valueOf(i+s);
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
	

	static void merge (BigInteger[] ar, int n) {
		int t = (int)Math.pow(2, n-1);
		if (t > ar.length) {
			return;
		}
		for (int i=0; i<ar.length; i+=(t<<1)) {
			if (t+i < ar.length) {
				ar[i] = ar[i].multiply(ar[i+t]);
			}
		}
		merge(ar, n+1);
	}


	static void printBigIntegerArray (BigInteger[] ar) {
		out.print("ar=");
		for (int i=0; i<ar.length; i++) {
			out.print((i==0?"":" ")+ar[i]);
		} out.println();
	}


	// <Main Method>
	public static PrintWriter out;
	public static void main(String[] args) {
		out = new PrintWriter(System.out);
		new Main().solve();
		out.flush();
	}

	// <Default Field>
	static int MAX_INT = Integer.MAX_VALUE, MIN_INT = Integer.MIN_VALUE;
	static double PI = Math.PI;
	static int MOD = 1000000007;

	// <Default Method>
	static int max (int... ar) {Arrays.sort(ar);return ar[ar.length-1];}
	static int min (int... ar) {Arrays.sort(ar);return ar[0];}
	static void printIntArray (int[] ar) {
		for (int i=0; i<ar.length; i++) {
			out.print((i==0?"":" ")+ar[i]);
		}
		out.println();
	}
	static void printlnIntArray (int[] ar) {
		for (int i=0; i<ar.length; i++) {
			out.println(ar[i]);
		}
	}
	static void printChar2DArray (char[][] ar) {
		for (int i=0; i<ar.length; i++) {
			for (int j=0; j<ar[0].length; j++) {
				out.print(ar[i][j]);
			}
			out.println();
		}
	}

	// <Fast Scanner>
	static InputStream in = System.in;
	static  byte[] buffer = new byte[1024];
	static int length = 0, p = 0;
	public static boolean hasNextByte () {
		if (p < length) return true;
		else {
			p = 0;
			try {length = in.read(buffer);}
			catch (Exception e) {e.printStackTrace();}
			if (length <= 0) return false;
		}
		return true;
	}
	public static int readByte () {
		if (hasNextByte() == true) return buffer[p++];
		return -1;
	}
	public static boolean isPrintable (int n) {return 33<=n&&n<=126;}
	public static void skip () {
		while (hasNextByte() && !isPrintable(buffer[p])) p++;
	}
	public static boolean hasNext () {skip(); return hasNextByte();}
	public static String next () {
		if (!hasNext()) throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		int temp = readByte();
		while (isPrintable(temp)) {
			sb.appendCodePoint(temp);
			temp = readByte();
		}
		return sb.toString();
	}
	public static int nextInt () {return Math.toIntExact(nextLong());}
	public static int[] nextIntArray (int n) {
		int[] ar = new int[n];
		for (int i=0; i<n; i++) ar[i] = nextInt();
		return ar;
	}
	public static long nextLong () {
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
	public static double nextDouble () {
		return Double.parseDouble(next());
	}
}

class Point{
	private int x;
	private int y;

	Point(int a, int b) {x=a; y=b;}

	int getX() {return x;}
	int getY() {return y;}
	void setX(int n) {x = n;}
	void setY(int n) {y = n;}
}