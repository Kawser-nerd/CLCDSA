import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;


public class Main {

	static double[][][] f;
	static int n,k;
	public static void main(String[] args) throws Exception{
		FastScanner fs = new FastScanner();
		n = fs.nextInt2();
		k = fs.nextInt2();
		f = new double[n + 1][k + 1][2];
		for (int i= 0; i <= n; i++)
			for (int j = 0; j <= k; j++){
				f[i][j][0] = -1;
				f[i][j][1] = -1;
			}
		//int result = 0;
		StringBuilder sb = new StringBuilder();
		sb.append(dp(0,k,0));
		//sb.append(result);
		System.out.println(sb.toString());
	}
	
	static double dp(int i, int j,int t){
		if (f[i][j][t] >= 0) return f[i][j][t];
		if (i == n) 
			if (t == 1){
				return 1.0;
			} else {
				return 0.0;
			}
		double p = 1.0/(i+1);
		double ans;
		if (j > 0){
			ans = p*Math.max(dp(i+1,j,0), dp(i+1,j-1,1)) + (1-p)*dp(i+1,j,t);
		} else {
			ans = p*dp(i+1,j,0) + (1-p)*dp(i+1,j,t);
		}
		
		f[i][j][t] = ans;
		return ans;
	}
	
}


class FastScanner {
	private final InputStream in = System.in;
	private final byte[] buffer = new byte[1024];
	private int ptr = 0;
	private int buflen = 0;
	
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
			if (buflen <= 0) { return false; }
		}
		return true;
	}
	
	private int readByte() {
		if (hasNextByte()) {
			return buffer[ptr++];
		} else {
			return -1;
		}
	}
	
	private static boolean isPrintableChar(int c) {
		return '!' <= c && c <= '~';
	}
	
	private void skipUnprintable() {
		while (hasNextByte() && !isPrintableChar(buffer[ptr])) {
			ptr++;
		}
	}
	
	public boolean hasNext() {
		skipUnprintable();
		return hasNextByte();
	}
	
	public String next() {
		if (!hasNext()) { throw new NoSuchElementException(); }
		StringBuilder sb = new StringBuilder();
		int b = readByte();
		while (isPrintableChar(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	public int nextInt2() {
		return Integer.parseInt(next());
	}
	
	public int nextInt() {
		if (!hasNext()) { throw new NoSuchElementException(); }
		int n = 0;
		boolean minus = false;
		int b = readByte();
		if (b == '-') {
			minus = true;
			b = readByte();
		}
		if (b < '0' || '9' < b) { throw new NumberFormatException(); }
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
	
}