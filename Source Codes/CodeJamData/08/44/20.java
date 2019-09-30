import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution implements Runnable {
	private static final String INPUT_FILE_NAME = "d.small.in.txt";

	private static final String OUTPUT_FILE_NAME = "d.small.out.txt";

	private PrintWriter wr;

	private BufferedReader rd;

	private int k;

	private int[] perms;

	private boolean[] useds;

	public static void main(String[] args) {
		new Thread(new Solution()).start();
	}

	public void run() {
		try {
			solve();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	void solve() throws IOException {
		rd = new BufferedReader(new FileReader(Solution.INPUT_FILE_NAME));
		wr = new PrintWriter(Solution.OUTPUT_FILE_NAME);
		
		String line = rd.readLine();
		StringTokenizer st = new StringTokenizer(line);
		int n = Integer.parseInt(st.nextToken());
		for (int ii = 0; ii < n; ++ii) {
			subSolve(ii);
		}

		wr.close();
	}

	void subSolve(int ii) throws IOException {
		String line = rd.readLine();
		StringTokenizer st = new StringTokenizer(line);
		k = Integer.parseInt(st.nextToken());
		perms = new int[k];
		useds = new boolean[k];
		
		line = rd.readLine();
		
		Arrays.fill(useds, false);
		Arrays.fill(perms, 0);
		int best = rec(0, line);
		
		wr.println(String.format("Case #%d: %d", ii + 1, best));
	}

	private int rec(int x, String line) {
		if (x == k) {
			return checkLength(line);
		}
		
		int result = Integer.MAX_VALUE;
		
		for (int i = 0; i < k; ++i) {
			if (!useds[i]) {
				useds[i] = true;
				perms[x] = i;
				int subresult = rec(x + 1, line);
				result = Math.min(result, subresult);
				useds[i] = false;
			}
		}
		
		return result;
	}

	private int checkLength(String line) {
		int l = line.length() / k;
		
		StringBuilder sb = new StringBuilder(line.length());
		
		for (int i = 0; i < l; ++i) {
			for (int j = 0; j < k; ++j) {
				sb.append(line.charAt(i * k + perms[j]));
			}
		}
		
		return calcLength(sb.toString());
	}

	private int calcLength(String line) {
		char last = '0';
		int groups = 0;
		for (int i = 0; i < line.length(); ++i) {
			char ch = line.charAt(i);
			if (last != ch) {
				last = ch;
				++groups;
			}
		}
		return groups;
	}
}
