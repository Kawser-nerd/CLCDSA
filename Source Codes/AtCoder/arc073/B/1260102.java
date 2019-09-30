import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.TreeMap;

public class Main {

	int N,W;
	int[] w,v;

	TreeMap<Integer,Integer>[] map;

	public int dfs(int n,int weight){

		if(n == N)return 0;

		if(map[n].containsKey(weight)){
			return map[n].get(weight);
		}

		int ret = 0;

		if(weight+w[n] <= W)ret = Math.max(ret,dfs(n+1,weight+w[n]) + v[n]);
		ret = Math.max(ret,dfs(n+1,weight));


		map[n].put(weight,ret);
		return ret;
	}

	@SuppressWarnings("unchecked")
	public void solve() {
		N = nextInt();
		W = nextInt();

		w = new int[N];
		v = new int[N];

		for(int i = 0;i < N;i++){
			w[i] = nextInt();
			v[i] = nextInt();
		}

		map = new TreeMap[N];
		for(int i = 0;i < N;i++){
			map[i] = new TreeMap<Integer,Integer>();
		}

		out.println(dfs(0,0));
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