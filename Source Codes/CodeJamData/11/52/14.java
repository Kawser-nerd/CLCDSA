import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main implements Runnable {
	public static void main(String[] args) {
		Thread thread = new Thread(new Main());
		thread.start();
	}

	public void run() {
		try {
			run1();
		} catch (IOException e) {
			throw new RuntimeException();
		}
	}

	int nextInt(StreamTokenizer st) throws IOException {
		st.nextToken();
		return (int) (st.nval);
	}

	long nextLong(StreamTokenizer st) throws IOException {
		st.nextToken();
		return (long) (st.nval);
	}

	BigInteger nextBI(StreamTokenizer st) throws IOException {
		st.nextToken();
		return new BigInteger(st.sval);
	}

	String nextString(StreamTokenizer st) throws IOException {
		st.nextToken();
		return st.sval;
	}

	double nextDouble(StreamTokenizer st) throws IOException {
		st.nextToken();
		return st.nval;
	}

	Map<Long, double[]> res = new HashMap<Long, double[]>();

	public void run1() throws IOException {
		InputStream inputStream = new FileInputStream("input.txt");
		// InputStream inputStream = System.in;
		Scanner sc = new Scanner(new InputStreamReader(inputStream));
		// StreamTokenizer st = new StreamTokenizer(inputStream);
		// BufferedReader br = new BufferedReader(new
		// InputStreamReader(inputStream));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int tN = sc.nextInt();
		case_cycle: for (int tn = 1; tn <= tN; tn++) {
			int n = sc.nextInt();
			int[] arr = new int[n];
			if (n == 0) {
				pw.format("Case #%d: 0\n", tn);
			} else {
				for (int i = 0; i < n; i++) {
					arr[i] = sc.nextInt();
				}
				Arrays.sort(arr);
				int[] res = new int[1 << n];
				res[0] = n;
				for (int mask = 1; mask < (1 << n); mask++) {
					for(int mask1 = mask; mask1 > 0; mask1 = (mask1 - 1) & mask) {
						int last = -1;
						boolean ok = true;
						int len = 0;
						for(int i = 0; i < n; i++) {
							if(((1 << i) & mask1) != 0) {
								ok &= last == -1 || arr[i] == last + 1;
								len++;
								last = arr[i];
							}
						}
//						System.out.println(mask + " " + mask1 + " " + len + " " + ok);
						if(ok) {
							res[mask] = Math.max(res[mask], Math.min(res[mask - mask1], len));
						}
					}
				}
				pw.format("Case #%d: %d\n", tn, res[(1<<n) - 1]);
			}
		}
		pw.close();
	}

	double get(double[][][] p, double w) {
		return get(p[1], w) - get(p[0], w);
	}

	double get(double[][] p, double w) {
		int n = p.length;
		double res = 0;
		for (int i = 1; i < n; i++) {
			if (p[i][0] < w) {
				res += (p[i][0] - p[i - 1][0]) * (p[i][1] + p[i - 1][1]) / 2;
			} else {
				double y = p[i - 1][1] + (p[i][1] - p[i - 1][1])
						* (w - p[i - 1][0]) / (p[i][0] - p[i - 1][0]);
				res += (w - p[i - 1][0]) * (y + p[i - 1][1]) / 2;
				break;
			}
		}
		return res;
	}

	double find(double[][][] p, double w, double area) {
		double l = 0;
		double r = w;
		for (int t = 0; t < 200; t++) {
			double m = (l + r) / 2;
			if (get(p, m) < area) {
				l = m;
			} else
				r = m;
		}
		return (l + r) / 2;
	}
}
