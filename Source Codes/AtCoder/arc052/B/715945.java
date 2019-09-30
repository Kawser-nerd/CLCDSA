import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;

public class Main {
	int N,Q;
	int[] X,R,H;

	public double getVolume(int A,int B){

		double ret = 0.0;

		for(int i = 0;i < N;i++){
			//?????????????
			if(X[i] >= B || X[i] + H[i] <= A)continue;

			//???????????????
			if(X[i] >= A && X[i] + H[i] <= B){
				//?????????
				ret += (double)R[i] * R[i] * Math.PI * H[i] / 3;
			}//???????????????
			else if(X[i] < A && X[i] + H[i] > B){
				double a = (double)(X[i] + H[i] - B) / H[i];
				double b = (double)(X[i] + H[i] - A) / H[i];

				double c = (R[i] * a) * (R[i] * a) * Math.PI * (H[i] * a) / 3;
				double d = (R[i] * b) * (R[i] * b) * Math.PI * (H[i] * b) / 3;

				ret += d - c;
			}//?????????????????????????
			else if(X[i] < A && X[i] + H[i] <= B){
				double a = (double)(X[i] + H[i] - A) / H[i];

				double c = (R[i] * a) * (R[i] * a) * Math.PI * (H[i] * a) / 3;

				ret += c;
			}//?????????????????????????
			else if(X[i] >= A && X[i] + H[i] > B){

				double a = (double)(X[i] + H[i] - B) / H[i];

				double c = (R[i] * a) * (R[i] * a) * Math.PI * H[i] * a / 3;
				double d = (double)R[i] * R[i] * Math.PI * H[i] / 3;

				ret += d - c;
			}
		}
		return ret;
	}

	public void solve() {
		N = nextInt();
		Q = nextInt();

		X = new int[N];
		R = new int[N];
		H = new int[N];

		for(int i = 0;i < N;i++){
			X[i] = nextInt();
			R[i] = nextInt();
			H[i] = nextInt();
		}

		for(int i = 0;i < Q;i++){
			int A = nextInt();
			int B = nextInt();

			double ans = 0.0;
			ans = getVolume(A,B);
			out.println(String.format("%.6f", ans));
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