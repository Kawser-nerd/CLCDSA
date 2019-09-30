import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class B {
	int n;
	int[] pre;
	char[] letters;
	int m;
	String[] words;
	int[] size;
	double[] comb;
	double[] fact;
	
	String solve() {
		fact = new double[n + 1];
		fact[0] = 1;
		for (int i = 1; i <= n; i++) {
			fact[i] = fact[i - 1] * i;
		}
		
		size = new int[n];
		comb = new double[n];
		for (int i = 0; i < n; i++) {
			if (pre[i] == -1) {
				dfs(i);
			}
		}
		
		boolean[] taken = new boolean[n];
		char[] hat = new char[n];
		Random r = new Random(letters.hashCode());
		int[] seen = new int[m];
		int iters = 2000;
		double[] s = new double[n];
		for (int t = 0; t < iters; t++) {
			Arrays.fill(taken, false);
			for (int i = 0; i < n; i++) {
				Arrays.fill(s, 0);
				for (int j = 0; j < n; j++) {
					if (taken[j] || pre[j] >= 0 && !taken[pre[j]]) {
						continue;
					}
					taken[j] = true;
					ArrayList<Integer> sizes = new ArrayList<>();
					ArrayList<Double> combs = new ArrayList<>();
					for (int k = 0; k < n; k++) {
						if (taken[k] || pre[k] >= 0 && !taken[pre[k]]) {
							continue;
						}
						sizes.add(size[k]);
						combs.add(comb[k]);
					}
					s[j] = combs(sizes, combs);
					taken[j] = false;
				}
				double sum = 0;
				for (int j = 0; j < n; j++) {
					sum += s[j];
				}
				sum = r.nextDouble() * sum;
				int k = -1;
				for (int j = 0; j < n; j++) {
					sum -= s[j];
					if (sum < 0) {
						k = j;
						break;
					}
				}
				if (k == -1) {
					throw new RuntimeException();
				}
				taken[k] = true;
				hat[i] = letters[k];
			}
			String hatString = new String(hat);
			for (int i = 0; i < m; i++) {
				if (hatString.contains(words[i])) {
					seen[i]++;
				}
			}
		}
		String ans = "";
		for (int i = 0; i < m; i++) {
			ans += " " + seen[i] * 1.0 / iters;
		}
		return ans.trim();
	}
	
	void dfs(int v) {
		size[v] = 1;
		ArrayList<Integer> sizes = new ArrayList<>();
		ArrayList<Double> combs = new ArrayList<>();
		for (int u = 0; u < n; u++) {
			if (pre[u] == v) {
				dfs(u);
				size[v] += size[u];
				sizes.add(size[u]);
				combs.add(comb[u]);
			}
		}
		comb[v] = combs(sizes, combs);
	}

	double combs(ArrayList<Integer> sizes, ArrayList<Double> combs) {
		int sz = sizes.size();
		int sum = 0;
		for (int s : sizes) {
			sum += s;
		}
		double res = fact[sum];
		for (int i = 0; i < sz; i++) {
			res /= fact[sizes.get(i)];
			res *= combs.get(i);
		}
		return res;
	}

	public B(Scanner in) {
		n = in.nextInt();
		pre = new int[n];
		for (int i = 0; i < n; i++) {
			pre[i] = in.nextInt() - 1;
		}
		letters = in.next().toCharArray();
		m = in.nextInt();
		words = new String[m];
		for (int i = 0; i < m; i++) {
			words[i] = in.next();
		}
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
