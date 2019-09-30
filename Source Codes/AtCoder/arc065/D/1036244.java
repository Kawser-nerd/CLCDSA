import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main {
	static final int MOD = (int)1e9 + 7;
	int N,M;
	char[] ch;
	int[] r,l,newR,sum;
	long[][] dp;


	public long dfs(int L,int R,int C){

		if(L == N){
			return 1;
		}

		if(dp[L][C] != -1)return dp[L][C];

		long ret = 0;
		int add = 0;

		if(R < newR[L+1]){
			add = sum[newR[L+1]] - sum[R];
		}

		//1???
		if(C > 0){
			ret += dfs(L + 1,newR[L+1],C - 1 + add) % MOD;
		}

		//0???
		if(C < R - L  + 1){
			ret += dfs(L + 1,newR[L+1],C + add) % MOD;
		}
		ret %= MOD;
		return dp[L][C] = ret;

	}

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

		newR = new int[N + 1];
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
		for(int i = 0;i < N + 1;i++){
			Arrays.fill(dp[i], -1);
		}

		out.println(dfs(0,newR[0],sum[newR[0]]));
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