import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;

public class Main {
	static final int MOD = (int)1e9+7;
	int N,M;
	long[] x,y;

	public void solve() {
		N = nextInt();
		M = nextInt();

		x = new long[N];
		y = new long[M];

		for(int i = 0;i < N;i++){
			x[i] = nextInt();
		}

		for(int i = 0;i < M;i++){
			y[i] = nextInt();
		}

		long xsum = 0L,ysum = 0L;

		for(int i = 0;i < N;i++){
			xsum += (x[i] * i) - (x[i] * (N-i-1));
			xsum %= MOD;
		}

		for(int i = 0;i < M;i++){
			ysum += (y[i] * i) - (y[i] * (M-i-1));
			ysum %= MOD;
		}

		out.println(xsum * ysum % MOD);
	}

	public static void main(String[] args) {
		out.flush();
		new Main().solve();
		out.close();
	}

	/* Input */
	private static final InputStream in = System.in;
	private static final PrintWriter out = new PrintWriter(System.out);
	private final byte[] buffer = new byte[2048];
	private int p = 0;
	private int buflen = 0;

	private boolean hasNextByte() {
		if (p < buflen)
			return true;
		p = 0;
		try {
			buflen = in.read(buffer);
		} catch (IOException e) {
			e.printStackTrace();
		}
		if (buflen <= 0)
			return false;
		return true;
	}

	public boolean hasNext() {
		while (hasNextByte() && !isPrint(buffer[p])) {
			p++;
		}
		return hasNextByte();
	}

	private boolean isPrint(int ch) {
		if (ch >= '!' && ch <= '~')
			return true;
		return false;
	}

	private int nextByte() {
		if (!hasNextByte())
			return -1;
		return buffer[p++];
	}

	public String next() {
		if (!hasNext())
			throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		int b = -1;
		while (isPrint((b = nextByte()))) {
			sb.appendCodePoint(b);
		}
		return sb.toString();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}