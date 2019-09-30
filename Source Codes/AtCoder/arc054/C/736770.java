import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;

public class Main {

	public static void main(String[] args) {
		IO io = new IO();
		int n = io.nextInt();
		long[][] e = new long[n][n];
		for(int i=0;i<n;i++) {
			String s = io.next();
			for(int j=0;j<n;j++) {
				e[i][j] = s.charAt(j) - '0';
			}
		}
		System.out.println(new MatrixMod(e).rank() == n ? "Odd" : "Even");
	}

}
class MatrixMod {
	public static long MOD = 2;
	long[][] e;
	int n,m;
	public MatrixMod(long[][] e) {
		this.e = e;
		this.n = e.length;
		this.m = e[0].length;
	}
	//O(n m^2)
	public int rank() {
		long[][] x = new long[n][];
		for(int i=0;i<n;i++) {
			x[i] = Arrays.copyOf(e[i], m);
		}
		int rank = 0;
		for(int j=0;j<m;j++) {
			int ind = -1;
			for(int i=rank;i<n;i++) {
				if (x[i][j] != 0) {
					ind = i;
					break;
				}
			}
			if (ind == -1) {
				continue;
			}
			long[] temp = x[ind];
			x[ind] = x[rank];
			x[rank] = temp;
			long a = inverse(x[rank][j], MOD);
			for(int k=j;k<m;k++) {
				x[rank][k] = x[rank][k] * a % MOD;
			}
			for(int i=rank+1;i<n;i++) {
				long b = (MOD - x[i][j]) % MOD;
				for(int k=j;k<m;k++) {
					x[i][k] = (x[rank][k] * b + x[i][k]) % MOD;
				}
			}
			rank++;
		}
		return rank;
	}
	public static long inverse(long a,long mod) {
		long b = mod, u = 1, v = 0;
		while(b > 0) {
			long temp;
			long t = a / b;
			a -= t * b;
			temp = a; a = b; b = temp;
			u -= t * v;
			temp = u; u = v; v = temp;
		}
		return (u % mod + mod) % mod;
	}
	public String toString() {
		return Arrays.deepToString(e);
	}
}
class IO extends PrintWriter {
	private final InputStream in;
	private final byte[] buffer = new byte[1024];
	private int ptr = 0;
	private int buflen = 0;
	
	public IO() { this(System.in);}
	public IO(InputStream source) { super(System.out); this.in = source;}
	private boolean hasNextByte() {
		if (ptr < buflen) {
			return true;
		}else{
			ptr = 0;
			try {
				buflen = in.read(buffer);
			} catch (IOException e) {
				e.printStackTrace();
			}
			if (buflen <= 0) {
				return false;
			}
		}
		return true;
	}
	private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
	private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
	private static boolean isNewLine(int c) { return c == '\n' || c == '\r';}
	public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
	public boolean hasNextLine() { while(hasNextByte() && isNewLine(buffer[ptr])) ptr++; return hasNextByte();}
	public String next() {
		if (!hasNext()) {
			throw new NoSuchElementException();
		}
		StringBuilder sb = new StringBuilder();
		int b = readByte();
		while(isPrintableChar(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	public char[] nextCharArray(int len) {
		if (!hasNext()) {
			throw new NoSuchElementException();
		}
		char[] s = new char[len];
		int i = 0;
		int b = readByte();
		while(isPrintableChar(b)) {
			if (i == len) {
				throw new InputMismatchException();
			}
			s[i++] = (char) b;
			b = readByte();
		}
		return s;
	}
	public String nextLine() {
		if (!hasNextLine()) {
			throw new NoSuchElementException();
		}
		StringBuilder sb = new StringBuilder();
		int b = readByte();
		while(!isNewLine(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	public long nextLong() {
		if (!hasNext()) {
			throw new NoSuchElementException();
		}
		long n = 0;
		boolean minus = false;
		int b = readByte();
		if (b == '-') {
			minus = true;
			b = readByte();
		}
		if (b < '0' || '9' < b) {
			throw new NumberFormatException();
		}
		while(true){
			if ('0' <= b && b <= '9') {
				n *= 10;
				n += b - '0';
			}else if(b == -1 || !isPrintableChar(b)){
				return minus ? -n : n;
			}else{
				throw new NumberFormatException();
			}
			b = readByte();
		}
	}
	public int nextInt() {
		long nl = nextLong();
		if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) {
			throw new NumberFormatException();
		}
		return (int) nl;
	}
	public char nextChar() {
		if (!hasNext()) {
			throw new NoSuchElementException();
		}
		return (char) readByte();
	}
	public double nextDouble() { return Double.parseDouble(next());}
	public int[] nextIntArray(int n) { int[] a = new int[n]; for(int i=0;i<n;i++) a[i] = nextInt(); return a;}
	public long[] nextLongArray(int n) { long[] a = new long[n]; for(int i=0;i<n;i++) a[i] = nextLong(); return a;}
	public double[] nextDoubleArray(int n) { double[] a = new double[n]; for(int i=0;i<n;i++) a[i] = nextDouble(); return a;}
	public void nextIntArrays(int[]... a) { for(int i=0;i<a[0].length;i++) for(int j=0;j<a.length;j++) a[j][i] = nextInt();}
	public int[][] nextIntMatrix(int n,int m) { int[][] a = new int[n][]; for(int i=0;i<n;i++) a[i] = nextIntArray(m); return a;}
	public char[][] nextCharMap(int n,int m) { char[][] a = new char[n][]; for(int i=0;i<n;i++) a[i] = nextCharArray(m); return a;}
	public void close() { super.close(); try {in.close();} catch (IOException e) {}}
}