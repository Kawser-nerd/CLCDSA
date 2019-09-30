import java.io.*;
import java.util.*;

public class Solution implements Runnable {

	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	static final String filename = "B-large";

	public void solve(int test) throws IOException {
		out.print("Case #" + test + ": ");
		char[] s = next().toCharArray();
		int n = s.length;
		int[] count = new int[10];
		int max = -1;
		int i;
		for (i = n - 1; i >= 0; --i) {
			count[s[i] - '0']++;
			if (max > s[i] - '0') {
				max = s[i] - '0' + 1;
				while (count[max] == 0) {
					++max;
				}
				s[i] = (char) ('0' + max);
				count[max]--;
				for (int j = i + 1, t = 0; t < 10; ++t) {
					while (count[t] > 0) {
						s[j++] = (char)('0' + t);
						--count[t];
					}
				}
				break;
			} else {
				max = s[i] - '0';
			}
		}
		if (i == -1) {
			s = new char[n + 1];
			count[0]++;
			int min = 1;
			while (count[min] == 0) {
				++min;
			}
			i = 0;
			s[i++] = (char) (min + '0');
			count[min]--;
			for (int t = 0; t < 10; ++t) {
				while (count[t] > 0) {
					s[i++] = (char) (t + '0');
					count[t]--;
				}
			}
		}
		for (char c : s) {
			out.print(c);
		}
		out.println();
	}
	
	public void run() {
		try {
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new PrintWriter(filename + ".out");
			eat("");
			
			int tests = nextInt();
			for (int test = 0; test < tests; ++test) {
				solve(test + 1);
			}
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		} catch (OutOfMemoryError er) {
			List<int[]> x = new ArrayList<int[]>();
			while (true) {
				x.add(new int[100000]);
			}
		}
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Thread(new Solution()).start();
	}
	
}
