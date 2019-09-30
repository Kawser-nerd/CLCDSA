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
	private int[] miss;
	private long[] price;
	private long[][] best;
	private int nteams;
	private int round;

	private void core() throws Exception {
		int ntest = nextInt();
		for (int test = 0; test < ntest; test++) {
			round = nextInt();
			nteams = 1 << round;
			miss = new int[nteams*2];
			price = new long[nteams*2];
			best = new long[nteams*2][round+1];
			for (long[] ls : best) {
				Arrays.fill(ls, -1);
			}
			
			int start = nteams;
			for (int i = 0; i < nteams; i++) {
				miss[start+i] = nextInt();
			}
			
			start /= 2;
			int cnt = nteams / 2;
			for (int i = 0; i < round; i++) {
				for (int j = 0; j < cnt; j++) {
					price[start+j] = nextLong();
				}
				start /= 2;
				cnt /= 2;
			}
			
			long res = solve(1, 0);
			writeCase(test);
			writer.println(" " + res);
		}
	}
	
	static long inf = Long.MAX_VALUE/4;
	private long solve(int at, int buy) {
		if (at >= nteams) {
			if (miss[at] + buy >= round)
				return 0;
			else
				return inf;
		}
		else {
			if (best[at][buy] != -1)
				return best[at][buy];
			long res = inf; 
			long noBuy = solve(at*2, buy) + solve(at*2+1, buy);
			if (noBuy < res) res = noBuy;
			long willBuy = price[at] + solve(at*2, buy+1) + solve(at*2+1, buy+1);
			if (willBuy < res) res = willBuy;

			best[at][buy] = res;
			return res;
		}
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
