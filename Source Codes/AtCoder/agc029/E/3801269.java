import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.StringTokenizer;

public class Main {

	static class IntList {

		int data[] = new int[3];
		int size = 0;

		boolean isEmpty() {
			return size == 0;
		}

		int size() {
			return size;
		}

		int get(int index) {
			if (index < 0 || index >= size) {
				throw new IndexOutOfBoundsException();
			}
			return data[index];
		}

		void clear() {
			size = 0;
		}

		void set(int index, int value) {
			if (index < 0 || index >= size) {
				throw new IndexOutOfBoundsException();
			}
			data[index] = value;
		}

		void expand() {
			if (size >= data.length) {
				data = copyOf(data, (data.length << 1) + 1);
			}
		}

		void insert(int index, int value) {
			if (index < 0 || index > size) {
				throw new IndexOutOfBoundsException();
			}
			expand();
			arraycopy(data, index, data, index + 1, size++ - index);
			data[index] = value;
		}

		int delete(int index) {
			if (index < 0 || index >= size) {
				throw new IndexOutOfBoundsException();
			}
			int value = data[index];
			arraycopy(data, index + 1, data, index, --size - index);
			return value;
		}

		void push(int value) {
			expand();
			data[size++] = value;
		}

		int pop() {
			if (size == 0) {
				throw new NoSuchElementException();
			}
			return data[--size];
		}

		void unshift(int value) {
			expand();
			arraycopy(data, 0, data, 1, size++);
			data[0] = value;
		}

		int shift() {
			if (size == 0) {
				throw new NoSuchElementException();
			}
			int value = data[0];
			arraycopy(data, 1, data, 0, --size);
			return value;
		}
	}

	static int n;
	static IntList edges[];
	static int peak[];
	static IntList byPeak[];
	static int dsuNext[], dsuRank[];
	static int peakSizes[][];
	static int ans[];

	static void solve() throws Exception {
		n = scanInt();
		edges = new IntList[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new IntList();
		}
		for (int i = 0; i < n - 1; i++) {
			int a = scanInt() - 1, b = scanInt() - 1;
			edges[a].push(b);
			edges[b].push(a);
		}
		peak = new int[n];
		byPeak = new IntList[n];
		for (int i = 0; i < n; i++) {
			byPeak[i] = new IntList();
		}
		dfs1(0, -1, -1);
		dsuNext = new int[n];
		dsuRank = new int[n];
		fill(dsuNext, -1);
		peakSizes = new int[n][];
		ans = new int[n];
		for (int cur = 0; cur < n; cur++) {
			IntList cp = byPeak[cur];
			for (int i = 0; i < cp.size; i++) {
				int v = cp.data[i];
				if (v > cur) {
					ans[v] = 1;
					IntList ce = edges[v];
					peakSizes[v] = new int[ce.size];
					for (int j = 0; j < ce.size; j++) {
						int w = ce.data[j];
						if (w < cur) {
							ans[v] += peakSizes[v][j] = dsuSize(w);
						}
					}
				} else {
					ans[v] = dsuSize(v);
				}
			}
			IntList ce = edges[cur];
			for (int i = 0; i < ce.size; i++) {
				int next = ce.data[i];
				if (next < cur) {
					dsuMerge(cur, next);
				}
			}
		}
		dfs2(0, -1, -1, 0);
		for (int i = 1; i < n; i++) {
			out.print(ans[i] + " ");
		}
	}

	static int dsuGet(int cur) {
		return dsuNext[cur] < 0 ? cur : (dsuNext[cur] = dsuGet(dsuNext[cur]));
	}

	static int dsuSize(int cur) {
		return -dsuNext[dsuGet(cur)];
	}

	static void dsuMerge(int a, int b) {
		a = dsuGet(a);
		b = dsuGet(b);
		if (dsuRank[a] < dsuRank[b]) {
			dsuNext[b] += dsuNext[a];
			dsuNext[a] = b;
		} else {
			dsuNext[a] += dsuNext[b];
			dsuNext[b] = a;
			if (dsuRank[a] == dsuRank[b]) {
				++dsuRank[a];
			}
		}
	}

	static void dfs1(int cur, int prev, int curPeak) {
		peak[cur] = curPeak;
		if (curPeak >= 0) {
			byPeak[curPeak].push(cur);
		}
		if (cur > curPeak) {
			curPeak = cur;
		}
		IntList ce = edges[cur];
		for (int i = 0; i < ce.size; i++) {
			int next = ce.data[i];
			if (next == prev) {
				continue;
			}
			dfs1(next, cur, curPeak);
		}
	}

	static void dfs2(int cur, int prev, int curPeak, int curAdd) {
		ans[cur] += curAdd;
		if (cur > curPeak) {
			curPeak = cur;
			curAdd = ans[cur];
		}
		int peakS[] = peakSizes[cur];
		IntList ce = edges[cur];
		for (int i = 0; i < ce.size; i++) {
			int next = ce.data[i];
			if (next == prev) {
				continue;
			}
			dfs2(next, cur, curPeak, curAdd - (peakS == null ? 0 : peakS[i]));
		}
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}