import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class C {
	static int n = 1000;
	static double[][] p;
	
	static void precalc() {
		int tries = 0;
		int[] a = new int[n];
		Random r = new Random(5);
		Map<String, Integer> count = new TreeMap<>();
		for (int t = 0; t < tries; t++) {
			for (int i = 0; i < n; i++) {
				a[i] = i;
			}
			for (int i = 0; i < n; i++) {
				int j = r.nextInt(n);
				int temp = a[i]; a[i] = a[j]; a[j] = temp;
			}
			String s = "";
			for (int i = 0; i < n; i++) {
				s += a[i];
			}
			if (!count.containsKey(s)) {
				count.put(s, 1);
			} else {
				count.put(s, count.get(s) + 1);
			}
		}
		System.out.println(count);
		for (Entry<String, Integer> entry : count.entrySet()) {
			System.out.println(entry.getKey() + " " + 1.0 * tries / entry.getValue());
		}
		p = new double[n][n];
		double[][] q = new double[n][n];
		for (int i = 0; i < n; i++) {
			p[i][i] = 1;
		}
		double p1 = 1.0 / n;
		double p2 = 1 - p1;
		for (int i = 0; i < n; i++) {
			for (int x = 0; x < n; x++) {
				for (int v = 0; v < n; v++) {
					if (x == i) {
						for (int j = 0; j < n; j++) {
							q[j][v] += p[x][v] * p1;
						}
					} else {
						q[x][v] += p[x][v] * p2;
						q[i][v] += p[x][v] * p1;
					}
				}
			}
			for (int x = 0; x < n; x++) {
				for (int v = 0; v < n; v++) {
					p[x][v] = q[x][v];
					q[x][v] = 0;
				}
			}
		}
//		for (int x = 0; x < n; x++) {
//			for (int v = 0; v < n; v++) {
//				System.out.print(p[x][v] + "\t");
//			}
//			System.out.println();
//		}
	}

	static double score() {
		if (n != in.nextInt()) {
			throw new RuntimeException();
		}
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		double qual = 1;
		for (int i = 0; i < n; i++) {
			qual *= p[i][a[i]];
			qual *= n;
		}
		return qual;
	}

	private static String fileName = C.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	public static void main(String[] args) throws IOException {
		precalc();
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new File(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		double[] scores = new double[tests];
		for (int t = 0; t < tests; t++) {
			scores[t] = score();
		}
		double[] s = scores.clone();
		Arrays.sort(s);
		double barrier = s[tests / 2];
		s[tests / 2] *= -1;
		System.out.println(Arrays.toString(s));
		for (int t = 0; t < tests; t++) {
			boolean good = scores[t] < barrier;
			out.println("Case #" + (t + 1) + ": " + (good ? "GOOD" : "BAD"));
		}
		in.close();
		out.close();
	}
}
