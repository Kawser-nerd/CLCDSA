import java.util.*;
import java.io.*;
import java.math.*;
import java.text.*;

class Main {
	void solve () {
		
		int[][] ar = new int[3][3];
		for (int i=0; i<3; i++) {
			for (int j=0; j<3; j++) {
				ar[i][j] = nextInt();
			}
		}
	
		int a = ar[1][0]-ar[0][0], b = ar[1][1]-ar[0][1], c = ar[1][2]-ar[0][2];
		int d = ar[2][0]-ar[1][0], e = ar[2][1]-ar[1][1], f = ar[2][2]-ar[1][2];
		
		if (a==b && b==c && a==c) {
			if (d==e && e==f && d==f) {
				out.println("Yes"); return;
			}
		}
		
		out.println("No");

		
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