import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
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

	static IntList edges[];

	static void solve() throws Exception {
		int n = scanInt();
		edges = new IntList[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new IntList();
		}
		for (int i = 0; i < n - 1; i++) {
			int a = scanInt() - 1;
			int b = scanInt() - 1;
			edges[a].push(b);
			edges[b].push(a);
		}
		up = new int[n];
		resLongest = resLongestEnd = 0;
		dfs(0, -1);
		for (int i = 0; i < resLongest / 2; i++) {
			resLongestEnd = up[resLongestEnd];
		}
		degrees = new int[n];
		long ans;
		if ((resLongest & 1) != 0) {
			dfs2(resLongestEnd, up[resLongestEnd], 0);
			dfs2(up[resLongestEnd], resLongestEnd, 0);
			ans = 2;
		} else {
			dfs2(resLongestEnd, -1, 0);
			degrees[0] = edges[resLongestEnd].size() + 1;
			ans = 1;
		}
		for (int i = 0; i < n && degrees[i] > 1; i++) {
			ans *= degrees[i] - 1;
		}
		if ((resLongest & 1) == 0) {
			for (int i = 0; i < edges[resLongestEnd].size(); i++) {
				int e = edges[resLongestEnd].get(i);
				fill(degrees, 0);
				long cans = 2;
				dfs2(resLongestEnd, e, 0);
				dfs2(e, resLongestEnd, 0);
				for (int j = 0; j < n && degrees[j] > 1; j++) {
					cans *= degrees[j] - 1;
				}
				ans = min(ans, cans);
			}
		}
		out.print((resLongest / 2 + 1) + " " + ans);
	}

	static int up[];
	static int resDepth, resEnd, resLongest, resLongestEnd;
	static void dfs(int cur, int prev) {
		up[cur] = prev;
		int d1 = 0, e1 = cur, d2 = 0;
		for (int i = 0; i < edges[cur].size(); i++) {
			int next = edges[cur].get(i);
			if (next == prev) {
				continue;
			}
			dfs(next, cur);
			if (resDepth + 1 > d1) {
				d2 = d1;
				d1 = resDepth + 1;
				e1 = resEnd;
			} else if (resDepth + 1 > d2) {
				d2 = resDepth + 1;
			}
		}
		if (resLongest < d1 + d2) {
			resLongest = d1 + d2;
			resLongestEnd = e1;
		}
		resDepth = d1;
		resEnd = e1;
	}

	static int degrees[];
	static void dfs2(int cur, int prev, int depth) {
		degrees[depth] = max(degrees[depth], edges[cur].size());
		for (int i = 0; i < edges[cur].size(); i++) {
			int next = edges[cur].get(i);
			if (next == prev) {
				continue;
			}
			dfs2(next, cur, depth + 1);
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