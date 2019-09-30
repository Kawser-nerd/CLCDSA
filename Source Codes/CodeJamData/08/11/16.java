import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Solution implements Runnable {
	private static final String INPUT_FILE_NAME = "a.big.in.txt";
	private static final String OUTPUT_FILE_NAME = "a.big.out.txt";
	
	private BufferedReader rd;
	private PrintWriter wr;

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
		int nn = Integer.parseInt(st.nextToken());
		for (int ii = 0; ii < nn; ++ii) {
			subSolve(ii);
		}
		
		rd.close();
		wr.close();
	}

	private void subSolve(int ii) throws IOException {
		String line = rd.readLine();
		StringTokenizer st = new StringTokenizer(line);
		int n = Integer.parseInt(st.nextToken());
		
		long[] a = new long[n];
		long[] b = new long[n];
		
		line = rd.readLine();
		st = new StringTokenizer(line);
		for (int i = 0; i < n; ++i) {
			a[i] = Long.parseLong(st.nextToken());
		}
		
		line = rd.readLine();
		st = new StringTokenizer(line);
		for (int i = 0; i < n; ++i) {
			b[i] = Long.parseLong(st.nextToken());
		}
		
		Arrays.sort(a);
		Arrays.sort(b);
		
		long result = 0;
		for (int i = 0; i < n; ++i) {
			result += (a[i] * b[n - i - 1]);
		}
		
		wr.println(String.format("Case #%d: %d", ii + 1, result));
	}
}
