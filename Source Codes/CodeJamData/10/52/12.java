import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main implements Runnable {
	private boolean _ReadFromFile = System.getProperty("ONLINE_JUDGE") == null;
	private boolean _WriteToFile = true;
	static final String TASK_ID = "b";
	static final String IN_FILE = TASK_ID + ".in";
	static final String OUT_FILE = TASK_ID + ".out";
	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	private void core() throws Exception {
		int ntest = nextInt();
		for (int test = 0; test < ntest; test++) {
			long tot = nextLong();
			int n = nextInt();
			int[] have = new int[n];
			for (int i = 0; i < have.length; i++) {
				have[i] = nextInt();
			}
			Arrays.sort(have);
			
			int[] best = new int[1000000];
			Arrays.fill(best, Integer.MAX_VALUE);
			best[0] = 0;
			for (int len = 1; len < best.length; len++) {
				for (int i = 0; i < have.length; i++) {
					if (len >= have[i] && best[len-have[i]] != Integer.MAX_VALUE)
						best[len] = Math.min(best[len], 1 + best[len-have[i]]);
				}
			}
			
			long res = Long.MAX_VALUE;
			for (int i = 0; i < best.length; i++) {
				if (best[i] != Integer.MAX_VALUE) {
					long rem = tot - i;
					for (int j = 0; j < have.length; j++) {
						if (rem % have[j] == 0) {
							long now = best[i] + rem / have[j];
							if (now < res)
								res = now;
						}
					}
				}
			}
			writeCase(test);
			if (res == Long.MAX_VALUE)
				writer.println("IMPOSSIBLE");
			else
				writer.println(res);
			writer.flush();
		}
	}
	private void writeCase(int test) {
		writer.printf("Case #%d: ", test+1);
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
