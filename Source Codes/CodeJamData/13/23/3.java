import java.io.*;
import java.util.*;

public class C {
	private static String fileName = C.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	static String[] dict = new String[521196];
	static int maxLen = 0;
	static Map<String, List<String>> map = new HashMap<String, List<String>>();
	
	static void add(String t, String s) {
		if (!map.containsKey(t)) {
			map.put(t, new ArrayList<String>(1));
		}
		map.get(t).add(s);
	}
	
	static void init() throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("garbled_email_dictionary.txt"));
		for (int i = 0; i < dict.length; i++) {
			String s = br.readLine();
			dict[i] = s;
			maxLen = Math.max(maxLen, s.length());
			String ss;
			if (s.length() > 5) {
				ss = s.substring(0, 5);
			} else {
				ss = s;
			}
			for (int j = 0; j < ss.length(); j++) {
				String t = ss.substring(0, j) + "?" + ss.substring(j + 1);
				add(t, s);
			}
		}
		System.out.println("maxLen=" + maxLen);
		System.out.println("mapSize=" + map.size());
		br.close();
	}

	private void solve() {
		String s = in.next();
		int n = s.length();
		int[][] a = new int[n + 1][5];
		int infty = Integer.MAX_VALUE / 2;
		for (int i = 0; i <= n; i++) {
			Arrays.fill(a[i], infty);
		}
		a[0][4] = 0;
		for (int i = 0; i < n; i++) {
			int[] ai = a[i];
			for (int k = 1; k <= 5; k++) {
				if (i + k > n) {
					break;
				}
				String ss = s.substring(i, i + k);
				for (int q = 0; q < k; q++) {
					String t = ss.substring(0, q) + "?" + ss.substring(q + 1);
					if (!map.containsKey(t)) {
						continue;
					}
					wloop:
					for (String w : map.get(t)) {
						if (i + w.length() > n) {
							continue;
						}
						int prev = -1;
						int first = -1;
						int ers = 0;
						for (int p = 0; p < w.length(); p++) {
							if (w.charAt(p) == s.charAt(i + p)) {
								continue;
							}
							ers++;
							if (prev < 0) {
								first = p;
							} else {
								if (p < prev + 5) {
									continue wloop;
								}
							}
							prev = p;
						}
						int iw = i + w.length();
						if (ers == 0) {
							for (int j = 0; j < 5; j++) {
								int ns = Math.min(j + w.length(), 4);
								a[iw][ns] = Math.min(a[iw][ns], ai[j]);
							}
						} else {
							int ns = Math.min(w.length() - prev - 1, 4);
							for (int j = Math.max(4 - first, 0); j < 5; j++) {
								a[iw][ns] = Math.min(a[iw][ns], ai[j] + ers);
							}
						}
					}
				}
			}
		}
		Arrays.sort(a[n]);
		out.println(a[n][0]);
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		init();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new C().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
	}
}
