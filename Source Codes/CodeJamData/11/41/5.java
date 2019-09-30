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
		for (int tn = 1; tn <= tN; tn++) {
			int x = sc.nextInt();
			int s = sc.nextInt();
			double r = sc.nextInt();
			double t = sc.nextInt();
			int n = sc.nextInt();
			System.out.println(x + " " + s + " " + r + " " + t + " " + n);
			int[][] arr = new int[n][3];
			int[] per = new int[2 * n + 2];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < 3; j++) {
					arr[i][j] = sc.nextInt();
					System.out.println(arr[i][j]);
				}
				per[2 * i + 0] = arr[i][0];
				per[2 * i + 1] = arr[i][1];
			}
			per[2 * n] = 0;
			per[2 * n + 1] = x;
			Arrays.sort(per);
			List<int[]> l = new ArrayList<int[]>();
			for (int i = 0; i + 1 < per.length; i++) {
				int max = 0;
				for (int j = 0; j < n; j++) {
					if (per[i] >= arr[j][0] && per[i] < arr[j][1])
						max = Math.max(max, arr[j][2]);
				}
				l.add(new int[] { per[i + 1] - per[i], max });
			}
			Collections.sort(l, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return a[1] - b[1];
				}
			});
			double res = 0;
			for (int i = 0; i < l.size(); i++) {
				double ru = Math.min(t, l.get(i)[0] / (l.get(i)[1] + r));
				t -= ru;
				res += ru + (l.get(i)[0] - ru * (l.get(i)[1] + r))
						/ (l.get(i)[1] + s);
			}
			pw.format("Case #%d: %f\n", tn, res);
		}
		pw.close();
	}

}
