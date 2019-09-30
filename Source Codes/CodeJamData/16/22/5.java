import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class B {
	String s, t;
	
	String solve() {
		int n = s.length();
		int[] a = new int[n];
		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = s.charAt(i) == '?' ? -1 : s.charAt(i) - '0';
			b[i] = t.charAt(i) == '?' ? -1 : t.charAt(i) - '0';
		}
		{
			boolean canBeEqual = true;
			String ans = ""; 
			for (int i = 0; i < n; i++) {
				if (a[i] == -1 && b[i] == -1) {
					ans += "0";
					continue;
				}
				if (a[i] != -1 && b[i] != -1) {
					if (a[i] != b[i]) {
						canBeEqual = false;
					}
					ans += a[i];
					continue;
				}
				ans += a[i] + b[i] + 1;
			}
			if (canBeEqual) {
				return ans + " " + ans;
			}
		}
		long bestA = -1, bestB = -1;
		for (int larger = 0; larger < 2; larger++) {
			for (int d = 0; d < n; d++) {
				boolean possible = true;
				int[] aa = new int[n];
				int[] bb = new int[n];
				for (int i = 0; i < n; i++) {
					if (i < d) {
						if (a[i] == -1 && b[i] == -1) {
							aa[i] = bb[i] = 0;
							continue;
						}
						if (a[i] != -1 && b[i] != -1) {
							if (a[i] != b[i]) {
								possible = false;
							}
							aa[i] = bb[i] = a[i];
							continue;
						}
						aa[i] = bb[i] = a[i] + b[i] + 1;
						continue;
					}
					if (i > d) {
						int[] c = a;
						int[] cc = aa;
						int[] e = b;
						int[] ee = bb;
						if (larger == 1) {
							c = b;
							cc = bb;
							e = a;
							ee = aa;
						}
						if (c[i] == -1) {
							cc[i] = 0;
						} else {
							cc[i] = c[i];
						}
						if (e[i] == -1) {
							ee[i] = 9;
						} else {
							ee[i] = e[i];
						}
						continue;
					}
					boolean found = false;
					loop:
					for (int diff = 1; diff <= 9; diff++) {
						for (aa[i] = 0; aa[i] <= 9; aa[i]++) {
							if (larger == 0) {
								bb[i] = aa[i] - diff;
							} else {
								bb[i] = aa[i] + diff;
							}
							if (bb[i] < 0 || bb[i] > 9) {
								continue;
							}
							if (a[i] != -1 && a[i] != aa[i]) {
								continue;
							}
							if (b[i] != -1 && b[i] != bb[i]) {
								continue;
							}
							found = true;
							break loop;
						}
					}
					if (!found) {
						possible = false;
					}
				}
				if (!possible) {
					continue;
				}
				long curA = make(aa);
				long curB = make(bb);
				if (bestA == -1 || Math.abs(curA - curB) < Math.abs(bestA - bestB) ||
						Math.abs(curA - curB) == Math.abs(bestA - bestB) && curA < bestA ||
						Math.abs(curA - curB) == Math.abs(bestA - bestB) && curA == bestA && curB < bestB) {
					bestA = curA;
					bestB = curB;
				}
			}
		}
		return pad(bestA, n) + " " + pad(bestB, n);
	}
	
	static long make(int[] a) {
		long res = 0;
		for (int d : a) {
			res = 10 * res + d;
		}
		return res;
	}
	
	static String pad(long v, int n) {
		String s = "" + v;
		while (s.length() < n) {
			s = "0" + s;
		}
		return s;
	}

	public B(Scanner in) {
		s = in.next();
		t = in.next();
	}
	
	public static void main(String[] args) throws Exception {
		int nThreads = 4;
		/* "Google Code Jam, Facebook Hacker Cup" */
		String fileNameSuffix = "";
		String formatOut = "Case #%2$d: %1$s";
		String formatSystemOut = formatOut;
//		/* "IPSC" */
//		String fileNameSuffix = "0";
//		String formatOut = "%s";
//		String formatSystemOut = "Case #%2$d solved.";//"Case #%2$d: %1$s";
		
		String fileName = B.class.getSimpleName().replaceFirst("_.*", "").toLowerCase() + fileNameSuffix;
		String inputFileName = fileName + ".in";
		String outputFileName = fileName + ".out";
		
		Locale.setDefault(Locale.US);
		Scanner in = new Scanner(new File(inputFileName));
		PrintWriter out = new PrintWriter(outputFileName);
		int tests = in.nextInt(); in.nextLine();//1;
		nThreads = Math.min(nThreads, tests);
		@SuppressWarnings("unchecked")
		Callable<String>[] callables = new Callable[tests];
		for (int t = 0; t < tests; t++) {
			final B testCase = new B(in);
			final int testCaseNumber = t + 1;
			callables[t] = new Callable<String>() {
				@Override
				public String call() {
					String answer = testCase.solve();
					System.out.println(String.format(formatSystemOut, answer, testCaseNumber));
					return String.format(formatOut, answer, testCaseNumber);
				}
			};
		}
		try {
			if (nThreads > 1) {
				ExecutorService executor = Executors.newFixedThreadPool(4);
				@SuppressWarnings("unchecked")
				Future<String>[] outputs = new Future[tests];
				for (int t = 0; t < tests; t++) {
					outputs[t] = executor.submit(callables[t]);
				}
				for (int t = 0; t < tests; t++) {
					out.println(outputs[t].get());
				}
				executor.shutdown();
			} else {
				for (int t = 0; t < tests; t++) {
					out.println(callables[t].call());
				}
			}
		} catch (Exception e) {
			System.out.flush();
			System.err.flush();
			e.printStackTrace();
			System.exit(1);
		}
		System.out.println("COMPLETE");
		in.close();
		out.close();
	}
}
