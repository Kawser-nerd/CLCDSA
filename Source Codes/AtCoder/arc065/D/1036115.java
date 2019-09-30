import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;

public class Main {
	static final int MOD = (int)1e9 + 7;
	int N,M;
	char[] ch;
	int[] r,l,newR,sum;
	long[][] dp;

	public void solve() {
		N = nextInt();
		M = nextInt();
		ch = next().toCharArray();

		l = new int[M];
		r = new int[M];
		for(int i = 0;i < M;i++){
			l[i] = nextInt() - 1;
			r[i] = nextInt() - 1;
		}

		newR = new int[N];
		for(int i = 0;i < N;i++){
			newR[i] = i;
		}
		for(int i = 0;i < M;i++){
			newR[l[i]] = Math.max(newR[l[i]],r[i]);
		}

		for(int i = 1;i < N;i++){
			newR[i] = Math.max(newR[i], newR[i-1]);
		}

		sum = new int[N];
		for(int i = 0;i < N;i++){
			sum[i] = ch[i] - '0';
		}
		for(int i = 0;i < N - 1;i++){
			sum[i + 1] += sum[i];
		}

		dp = new long[N + 1][N + 1];
		dp[0][0] = 1L;

		//i = ?????S???
		for(int i = 0;i < N;i++){

			//j = ????????1??
			for(int j = 0;j <= i;j++){

				if(dp[i][j] == 0)continue;

				/*
				 * j <= sum[newR[i]] j?newR[i]]??????????1????(?????????????1?????????????)
				 * sum[newR[i]] - j <= newR[i] - i ??????????????1?? <= newR[i]??????????0or1??(?????????1??????????)
				 *
				 * ????????????dp[i + 1][j]?????(i????0????????????)
				 */
				if(j <= sum[newR[i]] && sum[newR[i]] - j <= newR[i] - i){
					dp[i + 1][j] += dp[i][j]%MOD;
					dp[i + 1][j] %= MOD;
				}

				/*
				 * j <= sum[newR[i]] - 1 i????1???????sum[newR[i]]??????????j?????(???j?????????????????)
				 * sum[newR[i]] - j - 1 <= newR[i] - i ?i?????????(-1)??????????(j)?sum[newR[i]]?????????(???newR[i]?????????????????1??)?
				 * ??????????????(?????????????????????1????????)
				 */
				if(j  + 1<= sum[newR[i]] && sum[newR[i]] - j - 1 <= newR[i] - i){
					dp[i + 1][j + 1] += dp[i][j]%MOD;
					dp[i + 1][j + 1] %= MOD;
				}
			}
		}

		out.println(dp[N][sum[N-1]]);
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