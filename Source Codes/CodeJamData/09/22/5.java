import java.util.*;
import java.io.*;

public class B implements Runnable {
	private BufferedReader in;
	private PrintWriter out;
	private String problemID = getClass().getName().toLowerCase().split("_")[0] + "-large";
	
	private void solve() throws IOException {
		int n = Integer.parseInt(in.readLine());
		for (int i = 0; i < n; i++) {
			solveSingleTest(i + 1);
		}
	}
	
	private void solveSingleTest(int testCase) throws IOException {
		String line = in.readLine().trim();
		
		int[] d = new int[10];
		for (int i = 0; i < line.length(); i++) {
			d[line.charAt(i) - '0']++;
		}
		
		int[] cur = new int[10];
		String best = line + "0";
		line = "0" + line;
		for (int i = line.length() - 1; i >= 0; i--) {
			Arrays.fill(cur, 0);
			for (int j = 0; j < i; j++) {
				cur[line.charAt(j) - '0']++;
			}
			for (int k = line.charAt(i) - '0' + 1; k < 10; k++) {
				cur[k]++;
				
				int needed = 0;
				boolean bad = false;
				for (int u = 1; u < 10; u++) {
					if (cur[u] > d[u]) {
						bad = true;
						break;
					}
					needed += d[u] - cur[u];
				}
				if (!bad) {
					int rest = line.length() - i - 1;
					if (needed <= rest) {
						String number = line.substring(0, i) + k;
						for (int u = 0; u < rest - needed; u++) {
							number = number + "0";
						}
						for (int u = 1; u < 10; u++) {
							for (int v = 0; v < d[u] - cur[u]; v++) {
								number = number + u;
							}
						}
						if (number.compareTo(best) < 0) {
							best = number;
						}
					}
				}
				
				cur[k]--;
			}
		}
		
		while (best.charAt(0) == '0') {
			best = best.substring(1);
		}
		
		out.println("Case #" + testCase + ": " + best);
	}

	public void run() {
		try {
			in = new BufferedReader(new FileReader(new File(problemID + ".in")));
			out = new PrintWriter(new File(problemID + ".out"));
			solve();
			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	public static void main(String[] args) {
		new Thread(new B()).start();
	}
}
