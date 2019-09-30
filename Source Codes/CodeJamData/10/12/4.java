import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main implements Runnable {
	private boolean _ReadFromFile = System.getProperty("ONLINE_JUDGE") == null;
	private boolean _WriteToFile = true;
	static final String TASK_ID = "bl";
	static final String IN_FILE = TASK_ID + ".in";
	static final String OUT_FILE = TASK_ID + ".out";
	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;
	private int[][] dp;

	private void core() throws Exception {
		int ntest = nextInt();
		for (int test = 0; test < ntest; test++) {
			int deleteCost = nextInt();
			int insertCost = nextInt();
			int distance = nextInt();
			int n = nextInt();
			int[] a = new int[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = nextInt();
			}
			int maxValue = 256; //256 stands for empty
			dp = new int[n+1][maxValue + 1];
			for (int[] is : dp) {
				Arrays.fill(is, Integer.MAX_VALUE);
			}
			dp[0][maxValue] = 0;
			for (int i = 0; i < n; i++) {
				for (int last = 0; last <= maxValue; last++) {
					if (dp[i][last] != Integer.MAX_VALUE) {
						//delete
						update(i+1, last, dp[i][last] + deleteCost);
						//modify place
						for (int nextLast = 0; nextLast < maxValue; nextLast++) {
							if (last == maxValue) {
								int nextCost = dp[i][last] + Math.abs(nextLast - a[i]);
								update(i+1, nextLast, nextCost);
							}
							else {
								int k = Math.abs(nextLast - last);
								int added = 0;
								if (k > 0 && distance == 0) continue;
								if (k > 0) added = (k-1) / distance;
								int nextCost = dp[i][last] + added * insertCost + Math.abs(nextLast - a[i]);
								update(i+1, nextLast, nextCost);
							}
						}
					}
				}
			}
			int res = Integer.MAX_VALUE;
			for (int val = 0; val < dp[n].length; val++) {
				if (dp[n][val] < res)
					res = dp[n][val];
			}
			writeCase(test);
			writer.println(" " + res);
		}
	}
	private void update(int i, int val, int cost) {
		if (cost < dp[i][val])
			dp[i][val] = cost;
	}
	private void writeCase(int test) {
		writer.printf("Case #%d:", test+1);
	}
	void debug(Object...os) {
		System.out.println(Arrays.deepToString(os));
	}
	//--------------------- IO stuffs ---------------------
    public static void main(String[] args) throws InterruptedException {
        Thread thread = new Thread(new Main());
        thread.start();
        thread.join();
    }
	public void run() {
        try {
        	reader = _ReadFromFile ? new BufferedReader(new FileReader(IN_FILE)) : new BufferedReader(new InputStreamReader(System.in));
        	writer = _WriteToFile ? new PrintWriter(OUT_FILE) : new PrintWriter(new BufferedOutputStream(System.out));
            tokenizer = null;
            core();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
    int nextInt() throws Exception {
        return Integer.parseInt(nextToken());
    }
    long nextLong() throws Exception {
        return Long.parseLong(nextToken());
    }
    double nextDouble() throws Exception {
        return Double.parseDouble(nextToken());
    }
    String nextToken() throws Exception {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}
