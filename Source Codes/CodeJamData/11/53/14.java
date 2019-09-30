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
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

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
			int m = sc.nextInt();
			List<List<Integer>> l = new ArrayList<List<Integer>>();
			for(int i = 0;i < n * m; i++)
				l.add(new ArrayList<Integer>());
			for(int i = 0; i < n; i++) {
				String s = sc.next();
				for(int j = 0; j < m; j++) {
					char c = s.charAt(j);
					int u1 = 0;
					int v1 = 0;
					int u2 = 0;
					int v2 = 0;
					if(c == '-') {
						u1 = i;
						v1 = (j + 1) % m;
						u2 = i;
						v2 = (j + m - 1) % m;
					} else if(c == '|') {
						u1 = (i + 1) % n;
						v1 = j;
						u2 = (i + n - 1) % n;
						v2 = j;
					} else if(c == '\\') {
						u1 = (i + 1) % n;
						v1 = (j + 1) % m;
						u2 = (i + n - 1) % n;
						v2 = (j + m - 1) % m;
					} else {
						u1 = (i + n - 1) % n;
						v1 = (j + 1) % m;
						u2 = (i + 1) % n;
						v2 = (j + m - 1) % m;
					}
					int a1 = u1 * m + v1;
					int a2 = u2 * m + v2;
					l.get(a1).add(a2);
					l.get(a2).add(a1);
				}
			}
			Set<Integer> was = new HashSet<Integer>();
			long res = 1;
			for(int i = 0; i < l.size(); i++) {
				if(!was.contains(i)) {
					num = sum = 0;
					find(i, was, l);
					if(num * 2 != sum) {
						pw.format("Case #%d: 0\n", tn);
						continue case_cycle;
					}
					res = res * 2 % 1000003;
				}
			}
			pw.format("Case #%d: %d\n", tn, res);
		}
		pw.close();
	}
	
	int num = 0;
	int sum = 0;
	
	void find(int a, Set<Integer> was, List<List<Integer>> l) {
		was.add(a);
		num++;
		sum += l.get(a).size();
		for(int b : l.get(a)) {
			if(!was.contains(b))
				find(b, was, l);
		}
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
