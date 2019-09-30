import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main implements Runnable {
	private boolean _ReadFromFile = System.getProperty("ONLINE_JUDGE") == null;
	private boolean _WriteToFile = true;
	static final String TASK_ID = "c";
	static final String IN_FILE = TASK_ID + ".in";
	static final String OUT_FILE = TASK_ID + ".out";
	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	private void core() throws Exception {
		int ntest = nextInt();
		for (int test = 0; test < ntest; test++) {
			int n = nextInt();
			int[] location = new int[n];
			int[] count = new int[n];
			int sum = 0;
			for (int i = 0; i < n; i++) {
				location[i] = nextInt();
				count[i] = nextInt();
				sum += count[i];
			}
			int[] all = new int[sum];
			int id = 0;
			for (int i = 0; i < location.length; i++) {
				for (int j = 0; j < count[i]; j++) {
					all[id++] = location[i];
				}
			}
			int res = 0;
			while(true) {
				Arrays.sort(all);
				boolean ok = true;
				for (int i = 0; i < all.length; i++) {
					if (i > 0 && all[i] == all[i-1]) {
						all[i-1]--;
						all[i]++;
						++res;
						ok = false;
						break;
					}
				}
				if (ok) break;
			}
			writeCase(test);
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
