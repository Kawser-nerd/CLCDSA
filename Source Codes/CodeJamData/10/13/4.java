import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main implements Runnable {
	private boolean _ReadFromFile = System.getProperty("ONLINE_JUDGE") == null;
	private boolean _WriteToFile = true;
	static final String TASK_ID = "cl";
	static final String IN_FILE = TASK_ID + ".in";
	static final String OUT_FILE = TASK_ID + ".out";
	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;
	private int[] maxWin;
	private int[] minWin;

	private void core() throws Exception {
		int maxValue = 1000001;
		maxWin = new int[maxValue];
		maxWin[0] = Integer.MAX_VALUE;
		maxWin[1] = 0;
		for (int i = 2; i < maxWin.length; i++) {
			int last = maxWin[i-1];
			while(isWin(i, last+1)) ++last;
			maxWin[i] = last;
		}
		minWin = new int[maxValue];
		minWin[0] = 0;
		minWin[1] = 2;
		for (int i = 2; i < minWin.length; i++) {
			int last = minWin[i-1];
			while(last < minWin.length && !isWin(last, i)) ++last;
			minWin[i] = last;
		}
		int ntest = nextInt();
		for (int test = 0; test < ntest; test++) {
			int amin = nextInt();
			int amax = nextInt();
			int bmin = nextInt();
			int bmax = nextInt();
			long res = 0;
			for (int i = amin; i <= amax; i++) {
				res += overlap(1, maxWin[i], bmin, bmax) + overlap(minWin[i], bmax, bmin, bmax);
			}
			writeCase(test);
			writer.println(" " + res);
		}
	}
	private long overlap(int i, int j, int bmin, int bmax) {
		int l = Math.max(i, bmin);
		int r = Math.min(j, bmax);
		if (l > r) return 0;
		else return r-l+1;
	}
	private boolean isWin(int max, int min) {
		if (max-min >= min && maxWin[max-min] < min) 
			return true;
		if (max % min > 0 && maxWin[min] < max%min) 
			return true;
		return false;
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
