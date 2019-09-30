import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.NoSuchElementException;

public class Main {
	
	static long[] fac = new long[200001];
	static final long mod = 1000000007;
	static final BigInteger MOD = BigInteger.valueOf(1000000007);
	
	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		
		int h = sc.nextInt();
		int w = sc.nextInt();
		
		int a = sc.nextInt();
		int b = sc.nextInt();
		
		calc();
		
		long ans = 0;
		for (int i = b; i < w; i++) {
			ans = (ans + modCombi(i + (h - a - 1), i) * modCombi((w - i - 1) + (a - 1), w - i - 1) % mod) % mod;
		}
		
		out.println(ans);
		out.flush();
	}
	
	static void calc() {
		fac[0] = 1;
		for (int i = 1; i < fac.length; i++) {
			fac[i] = (fac[i - 1] * i) % mod;
		}
	}
	
	static long modCombi(int n, int r) {
		
		long a = BigInteger.valueOf(fac[r]).modInverse(MOD).longValue();
		long b = BigInteger.valueOf(fac[n - r]).modInverse(MOD).longValue();
		
		return fac[n] * a % mod * b % mod;
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
			if (buflen <= 0) {
				return false;
			}
		}
		return true;
	}
	
	private byte readByte() {
		if (hasNextByte()) {
			return buffer[ptr++];
		} else {
			return -1;
		}
	}
	
	private boolean isPrintableChar(int c) {
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
	
	public int nextInt() {
		if (!hasNext()) {
			throw new NoSuchElementException();
		}
		int n = 0;
		boolean minus = false;
		byte b = readByte();
		if (b == '-') {
			minus = true;
			b = readByte();
		}
		if (b < '0' || '9' < b) {
			throw new NumberFormatException();
		}
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