import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.NoSuchElementException;


public class Main {

	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		int N = sc.nextInt();
		int M = sc.nextInt();
		int S = sc.nextInt();
		
		UnionFind uf = new UnionFind(N + 1);
		int[][] edge = new int[M][3];
		for (int i = 0; i < M; i ++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			edge[i][0] = a;
			edge[i][1] = b;
			edge[i][2] = Math.min(a, b);
		}
		Arrays.sort(edge, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return o2[2] - o1[2];
			}
		});

		List<Integer> ret = new ArrayList<>();
		int idx = 0;
		for (int i = N; i >= 0; i --) {
			while (idx < M && edge[idx][2] >= i) {
				uf.union(edge[idx][0], edge[idx][1]);
				idx ++;
			}
			if (uf.find(i) == uf.find(S)) {
				ret.add(i);
			}
		}
		Collections.sort(ret);
		PrintWriter pw = new PrintWriter(System.out);
		for (int i : ret) {
			pw.println(i);
		}
		pw.flush();
	}
	
}

class UnionFind {
	private int[] table;
	private int[] rank;
	
	public UnionFind(int size) {
		this.table = new int[size];
		this.rank = new int[size];
		for (int i = 0; i < size; i ++) {
			this.table[i] = i;
			this.rank[i] = 1;
		}
	}

	public boolean isSame(int node1, int node2) {
		return find(node1) == find(node2);
	}

	public int find(int node) {
		if (table[node] == node) {
			return node;
		} else {
			return table[node] = find(table[node]);
		}
	}

	public void union(int node1, int node2) {
		int root1 = find(node1);
		int root2 = find(node2);
		
		if (rank[root1] < rank[root2]) {
			table[root1] = root2;
		} else if (rank[root1] > rank[root2]) {
			table[root2] = root1;
		} else if (root1 != root2) {
			table[root2] = root1;
			rank[root1] ++;
		}
	}
}



class FastScanner {
	public static String debug = null;

	private final InputStream in = System.in;
	private int ptr = 0;
	private int buflen = 0;
	private byte[] buffer = new byte[1024];
	private boolean eos = false;

	private boolean hasNextByte() {
		if (ptr < buflen) {
			return true;
		} else {
			ptr = 0;
			try {
				if (debug != null) {
					buflen = debug.length();
					buffer = debug.getBytes();
					debug = "";
					eos = true;
				} else {
					buflen = in.read(buffer);
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
			if (buflen < 0) {
				eos = true;
				return false;
			} else if (buflen == 0) {
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

	public boolean isEOS() {
		return this.eos;
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

	public long[] nextLongList(int n) {
		return nextLongTable(1, n)[0];
	}

	public int[] nextIntList(int n) {
		return nextIntTable(1, n)[0];
	}

	public long[][] nextLongTable(int n, int m) {
		long[][] ret = new long[n][m];
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				ret[i][j] = nextLong();
			}
		}
		return ret;
	}

	public int[][] nextIntTable(int n, int m) {
		int[][] ret = new int[n][m];
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				ret[i][j] = nextInt();
			}
		}
		return ret;
	}
}