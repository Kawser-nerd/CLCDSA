import static java.lang.Math.*;
import static java.lang.System.currentTimeMillis;
import static java.lang.System.exit;
import static java.lang.System.arraycopy;
import static java.util.Arrays.sort;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.fill;
import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Main().run();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st = new StringTokenizer("");

	int MAXN = 1000000;

	TreeMap<Integer, Integer> maxes = new TreeMap<Integer, Integer>();
	long sumMaxSuf;

	private void run() throws IOException {
		in = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		int[] dist = new int[MAXN];

		int tc = nextInt();
		for (int tn = 1; tn <= tc; tn++) {
			int L = nextInt();
			long t = nextLong();
			int n = nextInt();
			int c = nextInt();

			int[] a = new int[c];
			for (int i = 0; i < c; i++)
				a[i] = nextInt();

			long sumPref = 0;
			for (int i = 0; i < n; i++) {
				dist[i] = a[i % c];
				sumPref += dist[i];
			}
			long timeAll = sumPref * 2;

			out.print("Case #" + tn + ": ");
			if (L == 0) {
				out.println(timeAll);
				continue;
			}
			
			maxes.clear();
			int sufLen = 0;
			sumMaxSuf = 0;

			long bestTime = timeAll;

			for (int i = n - 1; i >= 0; i--) {
				sumPref -= dist[i];

				long timeCur = sumPref * 2;
				long dt = dist[i] * 2;
				long timeNext = timeCur + dt;
				if (timeNext > t) {
					long timeWithBoost = min(timeNext - t, dt);
					long bonusCur = timeWithBoost / 2;
					long bonusNext = sumMaxSuf;

					long totalTime = timeAll - bonusCur - bonusNext;
					bestTime = min(bestTime, totalTime);
				}

				if (sufLen < L - 1) {
					addToMaxes(dist[i]);
					sufLen++;
				} else if (sufLen > 0) {
					int minMax = maxes.firstKey();
					if (dist[i] > minMax) {
						removeFromMaxes(minMax);
						addToMaxes(dist[i]);
					}
				}
			}

			out.println(bestTime);
		}
		in.close();
		out.close();
	}

	private void addToMaxes(int key) {
		if (!maxes.containsKey(key))
			maxes.put(key, 1);
		else
			maxes.put(key, maxes.get(key) + 1);

		sumMaxSuf += key;
	}

	private void removeFromMaxes(int key) {
		int count = maxes.get(key);
		if (count == 1)
			maxes.remove(key);
		else
			maxes.put(key, count - 1);

		sumMaxSuf -= key;
	}

	void chk(boolean b) {
		if (b)
			return;
		System.out.println(new Error().getStackTrace()[1]);
		exit(999);
	}
	void deb(String fmt, Object... args) {
		System.out.printf(fmt + "%n", args);
	}
	String nextToken() throws IOException {
		while (!st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	String nextLine() throws IOException {
		st = new StringTokenizer("");
		return in.readLine();
	}
	boolean EOF() throws IOException {
		while (!st.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null)
				return true;
			st = new StringTokenizer(s);
		}
		return false;
	}
}
