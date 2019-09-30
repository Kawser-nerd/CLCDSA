import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;

public class Main {
	int N;
	char[] s;
	int[] a;

	public boolean check(){
		for(int i = 2;i < N;i++){
			int l = (i-1+N)%N;
			int r = (i+1)%N;

			if(s[i] == 'o'){
				if(a[i] == 0)a[r] = a[l];
				else a[r] = (a[l] == 0 ? 1 : 0);
			}else{
				if(a[i] == 0)a[r] = (a[l] == 0 ? 1 : 0);
				else a[r] = a[l];
			}
		}

		for(int i = 0;i < N;i++){
			int l = (i-1+N)%N;
			int r = (i+1)%N;

			if(s[i] == 'o'){
				if(a[i] == 0 && a[l] != a[r])return false;
				if(a[i] == 1 && a[l] == a[r])return false;
			}else{
				if(a[i] == 0 && a[l] == a[r])return false;
				if(a[i] == 1 && a[l] != a[r])return false;
			}
		}
		return true;
	}

	public void solve() {
		N = nextInt();
		s = next().toCharArray();

		for(int i = 0;i < 1 << 3;i++){
			a = new int[N];
			for(int j = 0;j < 3;j++){
				a[j] = (i>>j&1);
			}

			if(check()){
				for(int j = 0;j < N;j++){
					if(a[j] == 0){
						out.print("S");
					}else{
						out.print("W");
					}
				}
				out.println();
				return;
			}
		}

		out.println(-1);
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