import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {

	static final int[] dx = { 1, 0, -1, 0 };
	static final int[] dy = { 0, 1, 0, -1 };
	static final int MOD = 1000000007;

	static int h, w;
	static int[][] a, memo;

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		h = sc.nextInt();
		w = sc.nextInt();
		a = new int[h + 2][w + 2];
		for (int y = 1; y <= h; y++) {
			for (int x = 1; x <= w; x++) {
				a[y][x] = sc.nextInt();
			}
		}

		int sum = 0;
		memo = new int[h + 2][w + 2];
		for (int y = 1; y <= h; y++) {
			for (int x = 1; x <= w; x++) {
				sum += dp(y, x);
				sum %= MOD;
			}
		}

		System.out.println(sum);

	}

	static int dp(int y, int x) {
		if (memo[y][x] > 0) return memo[y][x];
		int result = 1;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (a[y][x] < a[ny][nx]) result = (result + dp(ny, nx)) % MOD;
		}
		return memo[y][x] = result;
	}

}

class Scanner {

	private final InputStream in;
	private final byte[] buffer;
	private int ptr;
	private int buflen;

	public Scanner(InputStream in) {
		this.in = in;
		this.buffer = new byte[1024];
		this.ptr = 0;
		this.buflen = 0;
	}

	private boolean hasNextByte() {
		if (ptr < buflen)
			return true;
		else {
			ptr = 0;
			try {
				buflen = in.read(buffer);
			} catch (IOException e) {
				e.printStackTrace();
			}
			if (buflen <= 0)
				return false;
		}
		return true;
	}

	private byte readByte() {
		if (hasNextByte())
			return buffer[ptr++];
		return -1;
	}

	private boolean isPrintableChar(byte c) {
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
		if (!hasNext())
			throw new NoSuchElementException();
		int n = 0;
		boolean minus = false;
		byte b = readByte();
		if (b == '-') {
			minus = true;
			b = readByte();
		}
		if (b < '0' || '9' < b)
			throw new NumberFormatException();
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