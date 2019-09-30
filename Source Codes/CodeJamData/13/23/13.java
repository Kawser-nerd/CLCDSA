import java.io.*;
import java.util.Arrays;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class C {
	
	public static final int MAX_LENGTH = 10;
	Random rand = new Random();

	class TestCase implements Runnable {
		final int testId;

		char[] s;
		int n;
		int[][] best;

		public TestCase(int testId) {
			this.testId = testId;
			readInput();
		}

		public synchronized void readInput() {
			s = nextToken().toCharArray();
			//s = generateTest(4000).toCharArray();
			n = s.length;
		}

		@Override
		public void run() {
			best = new int[6][n + 1];
			for (int[] a : best) {
				Arrays.fill(a, Integer.MAX_VALUE / 2);
			}
			best[5][0] = 0;
			for (int pos = 0; pos <= n; ++pos) {
				System.err.println("  " + pos);
				for (String word : dictionary) {
					if (word.length() > pos) {
						continue;
					}
					int prev = pos - word.length();
					int first = -1, last = -1;
					boolean bad = false;
					int add = 0;
					int prErr = -1;
					for (int i = 0; i < word.length(); ++i) {
						if (word.charAt(i) != s[prev + i]) {
							++add;
							last = i;
							if (first < 0) {
								first = i;
							} else if (last - prErr < 5) {
								bad = true;
								break;
							}
							prErr = i;
						}
					}
					if (bad) {
						continue;
					}

					boolean hasErrors = false;
					if (first < 0) {
						first = 5;
						last = 5;
					} else {
						hasErrors = true;
						last = Math.min(5, word.length() - last);
					}
					for (int prevC = 5; prevC + first >= 5 && prevC > 0; --prevC) {
						if (!hasErrors) {
							last = Math.min(5, word.length() + prevC);
						}
						best[last][pos] = Math.min(best[last][pos], best[prevC][prev] + add);
					}
				/*int prevC = Math.max(1, 5 - first);
				best[last][pos] = Math.min(best[last][pos], best[prevC][prev] + add);*/
				}
			/*for (int cnt = 1; cnt <= 5; ++cnt) {
				for (int oCnt = 1; oCnt < cnt; ++oCnt) {
					best[oCnt][pos] = Math.min(best[oCnt][pos], best[cnt][pos]);
				}
			}*/
			}

			synchronized (System.err) {
				System.err.println(testId);
			}
		}

		public synchronized void writeOutput() {
			int ans = Integer.MAX_VALUE;
			for (int cnt = 1; cnt <= 5; ++cnt) {
				ans = Math.min(ans, best[cnt][n]);
			}
			out.println(ans);
		}
	}
	
	String[] dictionary;
	
	private String generateTest(int length) {
		StringBuilder sb = new StringBuilder();
		while (sb.length() < length) {
			sb.append(dictionary[rand.nextInt(dictionary.length)]);
		}
		char[] s = sb.toString().toCharArray();
		int left = 0;
		for (int i = 0; i < s.length; ++i) {
			if (left <= 0 && rand.nextDouble() > 0.5) {
				s[i] = (char) ('a' + rand.nextInt(26));
				left = 5;
			}
			--left;
		}
		sb.setLength(0);
		for (char c : s) {
			sb.append(c);
		}
		return sb.toString();
	}

	private void readDictionary() throws IOException {
		dictionary = new String[521196];
		int[] count = new int[MAX_LENGTH + 1];
		BufferedReader dictFile = new BufferedReader(new FileReader("garbled_email_dictionary.txt"));
		int index = 0;
		for (String line = dictFile.readLine(); line != null; line = dictFile.readLine()) {
			dictionary[index++] = line;
			++count[line.length()];
		}
		System.out.println(Arrays.toString(count));
		dictFile.close();
	}

	public void run() {
		try {
			readDictionary();
			/*
			int tc = nextInt();
			for (int it = 1; it <= tc; ++it) {
				System.err.println(it);
				out.print("Case #" + it + ": ");
				solve();
			}
			*/
			long start = System.currentTimeMillis();
			int testCount = nextInt();
			//ExecutorService executor = Executors.newCachedThreadPool();
			ExecutorService executor = Executors.newFixedThreadPool(4);
			TestCase[] testCases = new TestCase[testCount];
			Future<?>[] results = new Future[testCount];

			for (int i = 0; i < testCount; ++i) {
				testCases[i] = new TestCase(i);
				results[i] = executor.submit(testCases[i]);
			}

			for (int i = 0; i < testCount; ++i) {
				results[i].get();
				out.print("Case #" + (i + 1) + ": ");
				testCases[i].writeOutput();
			}

			executor.shutdownNow();

			System.err.println("Done in " + (System.currentTimeMillis() - start) + "ms");
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
		Locale.setDefault(Locale.US);
		new C("C").run();
	}
}
