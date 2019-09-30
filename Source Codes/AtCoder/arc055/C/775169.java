import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;


public class Main {

	static double[][][] f;
	static int n,k;
	public static void main(String[] args) throws Exception{
		FastScanner fs = new FastScanner();
		String s = fs.next();
		//int result = 0;
		StringBuilder sb = new StringBuilder();
		int[] z = new int[s.length()];
		int[] z1 = new int[s.length()];
		computez(z, s);
		String s1 = new StringBuffer(s).reverse().toString();
		computez(z1, s1);
		long result = 0;
		for (int i = s.length()/2; i < s.length(); i++){
			int y = s.length() - i;
			if (i <= y) continue;
			if (z[i] >= y) z[i] = y - 1;
			if (z1[y] >= y) z1[y] = y - 1;
			int co = z[i] + z1[y] - y;
			if (co >= 0) {
				result += co + 1;
			}
		}
		sb.append(result);
		System.out.println(sb.toString());
	}
	
	public static void computez(int[] z, String s){
		int r = 0, l = 0;
		for (int k = 1; k < s.length(); k++){
			if (k > r) {
				int p = 0;
				while (k + p < s.length() && s.charAt(p) == s.charAt(k+p)) p++;
				if (p > 0) {
					l = k;
					r = k + p - 1;
					z[k] = p;
				}
			} else if (z[k - l] <= r - k){
				z[k] = z[k-l];
			} else {
				int p = r - k + 1;
				while (k + p < s.length() && s.charAt(p) == s.charAt(k+p)) p++;
				if (p > 0) {
					l = k;
					r = k + p - 1;
					z[k] = p;
				}
			}
		}
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