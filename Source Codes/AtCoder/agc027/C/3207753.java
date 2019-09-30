import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.NoSuchElementException;

import javax.swing.plaf.synth.SynthSpinnerUI;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	public void run() {
		Scanner sc = new Scanner();
		int N = sc.nextInt();
		int M = sc.nextInt();
		String str = sc.next();
		int[] col = new int[N];
		for (int i = 0; i < N; ++i) {
			col[i] = str.charAt(i) - 'A';
		}
		ArrayList<Integer>[] g = new ArrayList[N];
		for (int i = 0; i < N; ++i) {
			g[i] = new ArrayList<>();
		}
		int[][] deg = new int[N][2];
		for (int i = 0; i < M; ++i) {
			int a = sc.nextInt() - 1;
			int b = sc.nextInt() - 1;
			g[a].add(b);
			g[b].add(a);
			++deg[a][col[b]];
			++deg[b][col[a]];
		}
		ArrayDeque<Integer> dq = new ArrayDeque<>();
		for (int i = 0; i < N; ++i) {
			if (deg[i][0] == 0 || deg[i][1] == 0) {
				dq.add(i);
			}
		}
		boolean[] delete = new boolean[N];
		Arrays.fill(delete, false);
		while (!dq.isEmpty()) {
			int cur = dq.pollFirst();
			if (delete[cur])
				continue;
			delete[cur] = true;
			--N;
			for (int dst : g[cur]) {
				--deg[dst][col[cur]];
				if (deg[dst][1] == 0 || deg[dst][0] == 0) {
					dq.addLast(dst);
				}
			}
		}
		System.out.println(N > 0 ? "Yes" : "No");
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

		private boolean isPrintableChar(int c) {
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

		int nextInt() {
			return (int) nextLong();
		}
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.