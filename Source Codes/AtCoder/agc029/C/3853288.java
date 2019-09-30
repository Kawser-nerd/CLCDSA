import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	boolean check(int m, long[] A) {
		int n = A.length;
		class S implements Comparable<S> {
			long id;
			long v;

			public S(long id_, long v_) {
				id = id_;
				v = v_;
			}

			public int compareTo(S o) {
				return Long.compare(-this.id, -o.id);
			};
		}
		PriorityQueue<S> pq = new PriorityQueue<>();
		for (int i = 1; i < A.length; ++i) {
			if (A[i] > A[i - 1])
				continue;
			while (!pq.isEmpty() && pq.peek().id > A[i]) {
				pq.poll();
			}
			long cur = A[i];
			while (!pq.isEmpty() && pq.peek().id == cur && pq.peek().v == m - 1) {
				pq.poll();
				--cur;
			}
			if (cur < 1)
				return false;
			if (pq.isEmpty() || pq.peek().id < cur) {
				pq.add(new S(cur, 1));
			} else {
				pq.add(new S(cur, pq.poll().v + 1));
			}
		}
		return true;
	}

	void run() {
		Scanner sc = new Scanner();
		int n = sc.nextInt();
		long[] A = new long[n];
		boolean flag = true;
		for (int i = 0; i < n; ++i) {
			A[i] = sc.nextLong();
			if (i > 0)
				flag &= A[i] > A[i - 1];
		}
		if (flag) {
			System.out.println(1);
			return;
		}
		int ok = n;
		int ng = 1;
		while (ok - ng > 1) {
			int m = (ok + ng) / 2;
			if (check(m, A)) {
				ok = m;
			} else {
				ng = m;
			}
		}
		System.out.println(ok);
	}

	void tr(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}

}

class Scanner {
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

	private int readByte() {
		if (hasNextByte())
			return buffer[ptr++];
		else
			return -1;
	}

	private static boolean isPrintableChar(int c) {
		return 33 <= c && c <= 126;
	}

	private void skipUnprintable() {
		while (hasNextByte() && !isPrintableChar(buffer[ptr]))
			ptr++;
	}

	public boolean hasNext() {
		skipUnprintable();
		return hasNextByte();
	}

	public String next() {
		if (!hasNext())
			throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		int b = readByte();
		while (isPrintableChar(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	public long nextLong() {
		if (!hasNext())
			throw new NoSuchElementException();
		long n = 0;
		boolean minus = false;
		int b = readByte();
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

	public int nextInt() {
		return (int) nextLong();
	}
}