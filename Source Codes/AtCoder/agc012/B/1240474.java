import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;

public class Main {

	int N,M,Q;
	int[] a,b,v,d,c;

	public void solve() {
		N = nextInt();
		M = nextInt();

		a = new int[M+N];
		b = new int[M+N];
		for(int i = 0;i < M;i++){
			a[i] = nextInt()-1;
			b[i] = nextInt()-1;
		}

		for(int i = 0;i < N;i++){
			a[M+i] = i;
			b[M+i] = i;
		}

		Q = nextInt();
		v = new int[Q];
		d = new int[Q];
		c = new int[Q+1];
		int[][] dp = new int[10+1][N];
		for(int i = 0;i < Q;i++){
			v[i] = nextInt()-1;
			d[i] = nextInt();
			c[i+1] = nextInt();

			dp[d[i]][v[i]] = i + 1;
		}

		for(int i = 10;i >= 1;i--){
			for(int j = 0;j < M+N;j++){
				dp[i-1][b[j]] = Math.max(dp[i-1][b[j]], dp[i][a[j]]);
				dp[i-1][a[j]] = Math.max(dp[i-1][a[j]], dp[i][b[j]]);
			}
		}

		for(int i = 0;i < N;i++){
			out.println(c[dp[0][i]]);
		}
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