import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;

public class Main {
	public static long MOD = 1000000007;
	public static int INF = 1000000;
	
	public static void main(String[] args) {
		IO io = new IO();
//		int n = 40;
//		long a = 1;
//		long b = 1;
//		long[] s = new long[n];
//		for(int i=0;i<n;i++) {
//			s[i] = 2 * i + 1;
//		}
		int n = io.nextInt();
		long a = io.nextLong();
		long b = io.nextLong();
		long[] s = io.nextLongArray(n);
		int[] ra = right(n,s,a);
		int[] rb = right(n,s,b);
		int[] la = left(n,s,a);
		int[] lb = left(n,s,b);
		BIT bita = new BIT(n+1);
		BIT bitb = new BIT(n+1);
		bita.accumulate(1, 2, 1);
		bitb.accumulate(1, 2, 1);
		long ans = 0;
		for(int i=1;i<n;i++) {
			//a?i??,b?i-1??????
			{
				long x = bita.get(i);
				if (ra[i-1] == n - 1) {
					ans += x;
					if (ans >= MOD) ans -= MOD;
				}
				int l = Math.max(i, (i == 1 ? 0 : lb[i-2]));
				int r = Math.min(ra[i-1]+1, n-1);
				if (l <= r) {
					bitb.accumulate(l+1, r+1+1, x);
				}
			}
			{
				long x = bitb.get(i);
				if (rb[i-1] == n - 1) {
					ans += x;
					if (ans >= MOD) ans -= MOD;
				}
				int l = Math.max(i, (i == 1 ? 0 : la[i-2]));
				int r = Math.min(rb[i-1]+1, n-1);
				if (l <= r) {
					bita.accumulate(l+1, r+1+1, x);
				}
			}
		}
		ans += bita.get(n);
		ans += bitb.get(n);
		ans %= MOD;
		System.out.println(ans);
	}
	
	public static int[] right(int n,long[] s,long a) {
		int[] res = new int[n];
		for(int i=n-1;i>=0;i--) {
			if(i != n-1 && s[i] + a <= s[i+1]){
				res[i] = res[i+1];
			}else{
				res[i] = i;
			}
		}
		return res;
	}
	
	public static int[] left(int n,long[] s,long a) {
		int[] res = new int[n];
		int j = 0;
		for(int i=0;i<n;i++) {
			while(j < n && s[i] + a > s[j]) {
				j++;
			}
			if (j < n) {
				res[i] = j;
			}else{
				res[i] = INF;
			}
		}
		return res;
	}
}
class BIT {
	public static long MOD = Main.MOD;
	private int n;
	private long[] bit;
	public BIT(int n) {
		this.n = n;
		bit = new long[n+2];
	}

	public void accumulate(int begin,int end,long num) {
		accumulate(begin, num);
		accumulate(end, (MOD-num) % MOD);
	}

	private void accumulate(int index,long num) {
		index++;
		while(index<=n+1) {
			bit[index] += num;
			if (bit[index] >= MOD) bit[index] -= MOD;
			index+=index&-index;
		}
	}

	private long sum(int i) {
		long s = 0;
		while(i>0) {
			s+=bit[i];
			if (s >= MOD) s -= MOD;
			i-=i&-i;
		}
		return s;
	}

	public long get(int index) {
		return sum(index+1);
	}

//	public void set(int index,long num) {
//		accumulate(index,index+1,num-get(index));
//	}

	public String toString() {
		long[] value = new long[n];
		for(int i=0;i<n;i++) {
			value[i] = get(i);
		}
		return Arrays.toString(value);
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