import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;

public class Main {
	int N;
	int[] x,y,c;
	public void solve() {
		N = nextInt();
		x = new int[N];
		y = new int[N];
		c = new int[N];
		for(int i = 0;i < N;i++){
			x[i] = nextInt();
			y[i] = nextInt();
			c[i] = nextInt();
		}


		double low = 0.0;
		double high = Integer.MAX_VALUE;
		for(int i = 0;i < 100;i++){
			double t = (low + high) / 2;

			boolean flag = true;

			for(int j = 0;j < N;j++){
				for(int k = j + 1;k < N;k++){
					int ny = Math.abs(y[j] - y[k]);
					int nx = Math.abs(x[j] - x[k]);
					double d = (t / c[j] + t / c[k]);

					if(ny <= d && nx <= d)continue;
					flag = false;
					break;
				}

				if(!flag)
					break;
			}

			if(flag)
				high = t;
			else
				low = t;
		}

		out.println(String.format("%.7f",(high + low) / 2));

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