import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.NoSuchElementException;
public class Main {
	int N;
	private class P{
		int a,b;
		public P(int a,int b){
			this.a = a;
			this.b = b;
		}
	}

	public void solve() {
		N = nextInt();
		List<P> front = new ArrayList<P>();
		List<P> back = new ArrayList<P>();
		for(int i = 0;i < N;i++){
			int a = nextInt();
			int b = nextInt();
			if(a - b < 0){
				front.add(new P(a,b));
			}else{
				back.add(new P(a,b));
			}
		}

		Collections.sort(front,new Comparator<P>(){
			public int compare(P p1, P p2) {
				return p1.a - p2.a;
			}

		});
		Collections.sort(back,new Comparator<P>(){
			public int compare(P p1, P p2) {
				return p1.b - p2.b;
			}
		});
		Collections.reverse(back);

		long ans = Long.MIN_VALUE;
		long now = 0;
		for(P p : front){
			now += p.a;
			ans = Math.max(ans, now);
			now -= p.b;
		}

		for(P p: back){
			now += p.a;
			ans = Math.max(ans, now);
			now -= p.b;
		}

		out.println(ans);
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