import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;

public class Main {

	public static int ALPHA = 256;
	public static void main(String[] args) {
		IO io = new IO();
		char[] s = io.next().toCharArray();
		int n = s.length;
		int[] pairId = new int[n];
		char[] attr = new char[n];
		int[] count = new int[ALPHA];
		for(int i=0;i<n;i++) {
			count[s[i]]++;
		}
		boolean odd = false;
		char oddC = '*';
		int oddI = -1;
		for(int i=0;i<ALPHA;i++) {
			if (count[i] % 2 != 0) {
				if (!odd) {
					odd = true;
					oddC = (char) i;
					oddI = i;
				}else{
					System.out.println(-1);
					return;
				}
			}
		}

		int[] count2 = new int[ALPHA];
		int pairN = 0;
		HashMap<Pair,Integer> hm = new HashMap<>();
		for(int i=0;i<n;i++) {
			if (count2[s[i]] < count[s[i]] / 2) {
				attr[i] = 'L';
				pairId[i] = pairN;
				hm.put(new Pair(s[i], count2[s[i]]), pairN);
				pairN++;
			}else if(s[i] == oddC && count2[s[i]] == count[s[i]] / 2){
				attr[i] = 'M';
			}else{
				attr[i] = 'R';
				pairId[i] = hm.get(new Pair(s[i], count[s[i]] - 1 - count2[s[i]]));
			}
			count2[s[i]]++;
		}
		
//		System.err.println(Arrays.toString(pairId));
//		System.err.println(Arrays.toString(attr));
		
		//L < M < R
		long ans1 = 0;
		long countM = 0;
		long countR = 0;
		ArrayList<Integer> al = new ArrayList<>();
		for(int i=0;i<n;i++) {
			if (attr[i] == 'L') {
				ans1 += countM + countR;
			}else if(attr[i] == 'M') {
				ans1 += countR;
				countM++;
			}else{
				al.add(pairId[i]);
				countR++;
			}
		}
		Collections.reverse(al);
//		System.err.println(ans1);
//		System.err.println(al);
//		
		int[] d = new int[al.size()];
		for(int i=0;i<al.size();i++) {
			d[i] = al.get(i);
		}
		long ans2 = inversion(n, 0, d.length, d);
//		System.err.println(ans2);
		
		System.out.println(ans1 + ans2);

	}
	public static int[] temp = new int[200100];
	public static long inversion(int n,int l,int r,int[] d) {
		if (r - l <= 1) {
			return 0;
		}
		int c = (r + l) / 2;
		long ans = inversion(n, l, c, d) + inversion(n, c, r, d);
		//merge sort + count
		int p = l;
		int q = c;
		for(int i=l;i<r;i++) {
			if (p == c) {
				temp[i] = d[q++];
			}else if(q == r) {
				temp[i] = d[p++];
			}else{
				if (d[p] <= d[q]) { //ayashii
					temp[i] = d[p++];
				}else{
					temp[i] = d[q++];
					ans += (c - p);
				}
			}
		}
		for(int i=l;i<r;i++) {
			d[i] = temp[i];
		}
		return ans;
	}
}
class Pair {
	char c;
	int i;
	public Pair(char c, int i) {
		super();
		this.c = c;
		this.i = i;
	}
	@Override
	public int hashCode() {
		return i * 256 + c;
	}
	@Override
	public boolean equals(Object obj) {
		Pair other = (Pair) obj;
		if (c != other.c)
			return false;
		if (i != other.i)
			return false;
		return true;
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