import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class C {
	private void solve() throws Exception {
		BigInteger from = new BigInteger(nextToken()), to = new BigInteger(nextToken());
		int ans = 0;
		for (BigInteger b : sq) {
			/*if (base * base < from || base * base > to) {
				continue;
			}*/
			if (b.compareTo(from) >= 0 && b.compareTo(to) <= 0) {
				++ans;
			}
		}
		out.println(ans);
	}
	
	int count = 0;

	private boolean checkBase(char[] cur) {
		StringBuilder sb = new StringBuilder();
		for (char c : cur) {
			sb.append(c);
		}
		String s = sb.toString();
		BigInteger val = new BigInteger(s);
		boolean ans = isPalindrome(val.multiply(val));
		if (ans) {
			//out.println(s);
			++count;
			biBases.add(val);
		}
		return ans;
	}

	private boolean isPalindrome(BigInteger x) {
		char[] c = x.toString().toCharArray();
		for (int i = 0; i < c.length / 2; ++i) {
			if (c[i] != c[c.length - i - 1]) {
				return false;
			}
		}
		return true;
	}

	private boolean isPalindrome(long x) {
		char[] c = Long.toString(x).toCharArray();
		for (int i = 0; i < c.length / 2; ++i) {
			if (c[i] != c[c.length - i - 1]) {
				return false;
			}
		}
		return true;
	}
	
	private void preProcessBI() {
		biBases.add(BigInteger.valueOf(3));
		for (int len = 1; len <= 52; ++len) {
			System.out.println(len);
			//{int len = 10;
			char[] cur = new char[len];
			Arrays.fill(cur, '0');
			int mid = len / 2;
			{
				cur[0] = cur[len - 1] = '2';
				checkBase(cur);
				if (len % 2 == 1 && len > 1) {
					cur[mid] = '1';
					checkBase(cur);
					cur[mid] = '0';
				}
			}
			{
				cur[0] = cur[len - 1] = '1';
				checkBase(cur);
				while (true) {
					boolean found = false;
					for (int i = mid; i > 0; --i) {
						if (cur[i] < '1' || i == mid && cur[i] < '2' && len > 2) {
							cur[i] = (char) (cur[i] + 1);
							cur[len - i - 1] = cur[i];
							for (int j = i + 1; j <= mid; ++j) {
								cur[j] = cur[len - j - 1] = '0';
							}
							if (checkBase(cur)) {
								found = true;
								break;
							}
						}
					}
					if (!found) {
						break;
					}
				}
			}
		}
		Collections.sort(biBases);
		for (BigInteger b : biBases) {
			sq.add(b.multiply(b));
		}
	}

	ArrayList<BigInteger> biBases = new ArrayList<>();
	ArrayList<BigInteger> sq = new ArrayList<>();
	ArrayList<Long> goodBases = new ArrayList<>();

	private void preProcess() {
		for (long base = 1; base * base <= 100000000000000L; ++base) {
			if (isPalindrome(base) && isPalindrome(base * base)) {
				goodBases.add(base);
			}
		}
	}

	public void run() {
		try {
			//preProcess();
			preProcessBI();
			/*for (int i = 0; i < Math.max(goodBases.size(), biBases.size()); ++i) {
				if (biBases.get(i).compareTo(BigInteger.valueOf(goodBases.get(i))) != 0) {
					System.err.println("Error: " + biBases.get(i) + " " + goodBases.get(i));
				}
			}*/
			int tc = nextInt();
			for (int it = 1; it <= tc; ++it) {
				System.err.println(it);
				out.print("Case #" + it + ": ");
				solve();
			}
		} catch (Exception e) {
			NOO(e);
		} finally {
			out.close();
		}
	}

	PrintWriter out;
	BufferedReader in;
	StringTokenizer St;

	void NOO(Exception e) {
		e.printStackTrace();
		System.exit(42);
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String nextToken() {
		while (!St.hasMoreTokens()) {
			try {
				String line = in.readLine();
				if (line == null)
					return null;
				St = new StringTokenizer(line);
			} catch (Exception e) {
				NOO(e);
			}
		}
		return St.nextToken();
	}

	private C(String name) {
		try {
			in = new BufferedReader(new FileReader(name + ".in"));
			St = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(name + ".out"));
		} catch (Exception e) {
			NOO(e);
		}
	}

	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		new C("C").run();
		System.err.println("Done in " + (System.currentTimeMillis() - start) + "ms");
	}
}
