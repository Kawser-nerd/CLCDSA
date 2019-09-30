import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;

public class Main {

	public static void main(String[] args) {
		IO io = new IO();
		int w = io.nextInt(); //???
		int h = io.nextInt();
		int n = io.nextInt();
		ArrayList<Cross>[] crosses = new ArrayList[h];
		for(int i=0;i<h;i++) {
			crosses[i] = new ArrayList<>();
		}
		for(int i=0;i<n;i++) {
			int x = io.nextInt() - 1;
			int y = io.nextInt() - 1;
			crosses[y].add(new Cross(x,y));
		}
		for(int i=0;i<h;i++) {
			crosses[i].add(new Cross(w,i));
		}
		for(int i=0;i<h;i++) {
			crosses[i].sort((c1,c2)->Integer.compare(c1.x, c2.x));
		}
		for(int i=0;i<h;i++) {
			System.err.println(crosses[i]);
		}
		crosses[0].get(0).lx = 0;
		for(int i=1;i<h;i++) {
			int bottomCrossJ = 0;
			for(int j=0;j<crosses[i].size();j++) {
				while(bottomCrossJ < crosses[i-1].size()) {
					Cross cur = crosses[i].get(j);
					Cross bottom = crosses[i-1].get(bottomCrossJ);
					int firstX = j == 0 ? 0 : (crosses[i].get(j-1).x + 1);
					int lastX = cur.x - 1;
					int bottomFirstX = bottom.lx + 1;
					int bottomLastX = bottom.x - 1;
					int intersectFirstX = Math.max(firstX, bottomFirstX);
					int intersectLastX = Math.min(lastX, bottomLastX);
					if (intersectFirstX <= intersectLastX) {
						cur.lx = Math.min(cur.lx,intersectFirstX);
					}
					if (bottomLastX > lastX) {
						break;
					}
					bottomCrossJ++;
				}
			}
		}
		for(int i=0;i<h;i++) {
			System.err.println(crosses[i]);
		}
		int ans = 10000000;
		for(int i=0;i<h;i++) {
			for(Cross c: crosses[i]) {
				if (c.lx < c.x) {
					ans = Math.min(ans, c.x);
				}
			}
		}
		System.out.println(ans);
	}

}
class Cross {
	int x,y;
	int lx;
	public Cross(int x, int y) {
		super();
		this.x = x;
		this.y = y;
		this.lx = 10000000;
	}
	@Override
	public String toString() {
		return "Cross [x=" + x + ", y=" + y + ", lx=" + lx + "]";
	}
}
class IO extends PrintWriter {
	private final InputStream in;
	private final byte[] buffer = new byte[1024];
	private int ptr = 0;
	private int buflen = 0;

	public IO() {
		this(System.in);
	}

	public IO(InputStream source) {
		super(System.out);
		this.in = source;
	}

	private boolean hasNextByte() {
		if (ptr < buflen) {
			return true;
		} else {
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

	private int readByte() {
		if (hasNextByte())
			return buffer[ptr++];
		else
			return -1;
	}

	private static boolean isPrintableChar(int c) {
		return 33 <= c && c <= 126;
	}

	private static boolean isNewLine(int c) {
		return c == '\n' || c == '\r';
	}

	public boolean hasNext() {
		while (hasNextByte() && !isPrintableChar(buffer[ptr]))
			ptr++;
		return hasNextByte();
	}

	public boolean hasNextLine() {
		while (hasNextByte() && isNewLine(buffer[ptr]))
			ptr++;
		return hasNextByte();
	}

	public String next() {
		if (!hasNext()) {
			throw new NoSuchElementException();
		}
		StringBuilder sb = new StringBuilder();
		int b = readByte();
		while (isPrintableChar(b)) {
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
		while (isPrintableChar(b)) {
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
		while (!isNewLine(b)) {
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
		while (true) {
			if ('0' <= b && b <= '9') {
				n *= 10;
				n += b - '0';
			} else if (b == -1 || !isPrintableChar(b)) {
				return minus ? -n : n;
			} else {
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

	public double nextDouble() {
		return Double.parseDouble(next());
	}

	public int[] nextIntArray(int n) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		return a;
	}

	public long[] nextLongArray(int n) {
		long[] a = new long[n];
		for (int i = 0; i < n; i++)
			a[i] = nextLong();
		return a;
	}

	public double[] nextDoubleArray(int n) {
		double[] a = new double[n];
		for (int i = 0; i < n; i++)
			a[i] = nextDouble();
		return a;
	}

	public void nextIntArrays(int[]... a) {
		for (int i = 0; i < a[0].length; i++)
			for (int j = 0; j < a.length; j++)
				a[j][i] = nextInt();
	}

	public int[][] nextIntMatrix(int n, int m) {
		int[][] a = new int[n][];
		for (int i = 0; i < n; i++)
			a[i] = nextIntArray(m);
		return a;
	}

	public char[][] nextCharMap(int n, int m) {
		char[][] a = new char[n][];
		for (int i = 0; i < n; i++)
			a[i] = nextCharArray(m);
		return a;
	}

	public void close() {
		super.close();
		try {
			in.close();
		} catch (IOException e) {
		}
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.