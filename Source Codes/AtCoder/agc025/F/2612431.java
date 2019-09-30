import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static class Token implements Comparable<Token> {
		int index;
		final int time;

		Token(int index, int time) {
			this.index = index;
			this.time = time;
		}

		public int compareTo(Token o) {
			return time - o.time;
		}
	}

	static void solve() throws Exception {
		int c1 = scanInt();
		int c2 = scanInt();
		int c = max(c1, c2);
		int k = scanInt();
		int bit[] = new int[c];
		String s1 = scanString();
		for (int i = 0; i < c1; i++) {
			if (s1.charAt(i) == '1') {
				bit[c1 - i - 1] |= 1;
			}
		}
		String s2 = scanString();
		for (int i = 0; i < c2; i++) {
			if (s2.charAt(i) == '1') {
				bit[c2 - i - 1] |= 2;
			}
		}
		int lCap = 2 * c + 2;
		int lIndex[] = new int[lCap], lValue[] = new int[lCap];
		int lPrev[] = new int[lCap], lNext[] = new int[lCap], lFree = 1;
		Token lToken[] = new Token[lCap];
		for (int i = 1; i < lCap - 1; i++) {
			lNext[i] = i + 1;
		}
		lNext[lCap - 1] = -1;
		lPrev[0] = lNext[0] = 0;
		lIndex[0] = lValue[0] = -1;
		PriorityQueue<Token> pq = new PriorityQueue<>();
		for (int i = 0; i < c; i++) {
			if (bit[i] == 0) {
				continue;
			}
			int cur = lFree;
			lFree = lNext[lFree];
			lIndex[cur] = i;
			lValue[cur] = bit[i];
			int last = lPrev[0];
			if (lValue[last] == 3 && lValue[cur] != 3) {
				lToken[last] = new Token(last, lIndex[cur] - lIndex[last]);
				pq.add(lToken[last]);
			}
			lPrev[cur] = last;
			lNext[cur] = 0;
			lPrev[0] = lNext[last] = cur;
		}
		for (int step = 1; step <= k; step++) {
			while (!pq.isEmpty() && pq.element().time == step) {
				int cur = pq.remove().index;
				lToken[cur] = null;
				int v;
				{
					int next = lNext[cur];
					v = lValue[next];
					lValue[cur] = 3 ^ v;
					lIndex[cur] += step;
					int prev = lPrev[cur];
					if (lValue[prev] == 3) {
						lToken[prev] = new Token(prev, lIndex[cur] - lIndex[prev]);
						pq.add(lToken[prev]);
					}
					int next2 = lNext[next];
					lNext[cur] = next2;
					lPrev[next2] = cur;
					lNext[next] = lFree;
					lFree = next;
				}
				int curIndex = lIndex[cur];
				while (true) {
					int next = lNext[cur];
					++curIndex;
					if (lValue[next] != 3 && lIndex[next] == curIndex) {
						if (lValue[next] == v) {
							int next2 = lNext[next];
							lNext[cur] = next2;
							lPrev[next2] = cur;
							lNext[next] = lFree;
							lFree = next;
						} else {
							lValue[next] = 3;
							lIndex[next] -= step;
							int next2 = lNext[next];
							if (next2 != 0 && lValue[next2] != 3) {
								lToken[next] = new Token(next, lIndex[next2] - lIndex[next]);
								pq.add(lToken[next]);
							}
							break;
						}
					} else {
						int neww = lFree;
						lFree = lNext[lFree];
						lIndex[neww] = curIndex;
						lValue[neww] = v;
						lPrev[neww] = cur;
						lNext[neww] = next;
						lPrev[next] = lNext[cur] = neww;
						break;
					}
				}
			}
		}
		int last = lPrev[0];
		int maxIndex = lValue[last] == 3 ? lIndex[last] + k : lIndex[last];
		char bits0[] = new char[maxIndex + 1], bits1[] = new char[maxIndex + 1];
		fill(bits0, '0');
		fill(bits1, '0');
		int firstBit0 = -1, firstBit1 = -1;
		for (int cur = lNext[0]; cur != 0; cur = lNext[cur]) {
			int curValue = lValue[cur];
			int curIndex = curValue == 3 ? lIndex[cur] + k : lIndex[cur];
			if ((curValue & 1) != 0) {
				bits0[maxIndex - curIndex] = '1';
				firstBit0 = maxIndex - curIndex;
			}
			if ((curValue & 2) != 0) {
				bits1[maxIndex - curIndex] = '1';
				firstBit1 = maxIndex - curIndex;
			}
		}
		out.println(new String(bits0, firstBit0, maxIndex - firstBit0 + 1));
		out.print(new String(bits1, firstBit1, maxIndex - firstBit1 + 1));
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