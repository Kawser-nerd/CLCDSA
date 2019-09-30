import java.awt.Point;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Random;
import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {
	static final long C =  1000000007;
	static final int CY = 1000000000;
	static final int INF = Integer.MAX_VALUE/2;
	StringBuilder sb;

	int[][] G;
	Map<Integer,List<Integer>> Genb = new HashMap<>();
	int V;
	int E;
	int Venb;
	int Eenb;
	long START_TIME;
	static final int LOOPNUM = 2;//?????
	int GenbSize;//Genb????1?
	int ansSize;//?????????????
	List<Integer> ansIndexs = new ArrayList<Integer>();
	Random rand = new Random();
	public static final int dx[] = { -1, 0, 0, 1 , 0 };
	public static final int dy[] = {  0,-1, 1, 0 , 0 };
	public static final String ds[] = { "U","L", "R", "D" ,""};

	public void calc() {

		sb = new StringBuilder();


		//????
		IO sc = new IO();
		int h=sc.nextInt();
		int w = sc.nextInt();
		int n = sc.nextInt();
		int[] xs= new int[n],ys =new int[n];
		ArrayList<Integer>[] lists = new ArrayList[w+1];
		for (int i=0;  i < n; i++) {
			 int x = sc.nextInt();
			 int y = sc.nextInt();
			 if (x < y) continue;
			 if (lists[y] == null) {
				 lists[y] = new ArrayList<Integer>();
			 }
			 lists[y].add(x);
		}
		long ans = 0;
		for (int i=1; i <= w; i++) {
			if (lists[i] == null) continue;
			Collections.sort(lists[i]);
		}
		int xi = 0;
		int minx = h;
		for (int y=1; y <= w; y++) {
			ArrayList<Integer> list = lists[y];
			xi++;
			if (list == null) {
				continue;
			}
			for (int x: list) {
				if (xi == x) {
					xi++;
					continue;
				}else if (xi > x) {
					continue;
				}else {
					minx = Math.min(x-1 ,minx);
					break;
				}
			}
			
		}
		ans = minx;
		
		
		
		
		//int[][] map = sc.nextIntMatrix(n, n);

		
		

		System.out.println(ans);

	}
	StringBuilder twoArrayToString(int[][] a) {
		StringBuilder s = new StringBuilder();
		
		for (int i=0; i < a.length; i++) {
			s.append( arrayToString(a[i]));
			if (i != a.length-1) {
				s.append("\n");
			}
		}
		return s ;
	}
	//???????????(??????????)
		StringBuilder arrayToString(int[] a) {
			StringBuilder s = new StringBuilder();

			for (int i=0; i < a.length; i++) {
				s.append( a[i]);
				if (i != a.length-1) {
					s.append(" ");
				}
			}
			return s ;
		}
		StringBuilder twoArrayToString(long[][] a) {
			StringBuilder s = new StringBuilder();
			
			for (int i=0; i < a.length; i++) {
				s.append( arrayToString(a[i]));
				if (i != a.length-1) {
					s.append("\n");
				}
			}
			return s ;
		}
		//???????????(??????????)
			StringBuilder arrayToString(long[] a) {
				StringBuilder s = new StringBuilder();

				for (int i=0; i < a.length; i++) {
					s.append( a[i]);
					if (i != a.length-1) {
						s.append(" ");
					}
				}
				return s ;
			}
	public static void main(String[] args) {
		Main main = new Main();
		main.calc();

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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.