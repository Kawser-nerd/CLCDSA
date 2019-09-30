import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;


public class Main {
	public static void main(String[] args) throws Exception{
		FastScanner fs = new FastScanner();
		int n = fs.nextInt2();
		int[][] a = new int[n][n];
		for (int i = 0; i < n; i++){
			String str = fs.next();
			for (int j = 0; j < n; j++){
				a[i][j] = str.charAt(j) - '0';
			}
		}
		for (int i = 0; i < n; i++){
			if (a[i][i] == 0){
				for (int j = i + 1; j < n; j++){
					if (a[j][i] != 0) {
						int[] temp = new int[n];
						temp = a[i];
						a[i] = a[j];
						a[j] = temp;
					}
				}
			}
			if (a[i][i] == 0) {
				System.out.println("Even");
				return;
			}
			for (int j = i + 1; j < n; j++){
				double rate = a[j][i] / a[i][i];
				for (int k = i; k < n; k++){
					a[j][k] += a[i][k] * rate;
					a[j][k] %=2;
				}
			}
		}
		int result = 1;
		for (int i = 0; i < n; i++){
			result *=a[i][i];
		}
		StringBuilder sb = new StringBuilder();
		sb.append(result);
		System.out.println(result % 2 == 0 ? "Even" : "Odd");
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