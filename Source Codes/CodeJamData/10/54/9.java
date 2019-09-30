import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main implements Runnable {
	private boolean _ReadFromFile = System.getProperty("ONLINE_JUDGE") == null;
	private boolean _WriteToFile = true;
	static final String TASK_ID = "d";
	static final String IN_FILE = TASK_ID + ".in";
	static final String OUT_FILE = TASK_ID + ".out";
	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	int numPossible;
	private int base;
	LinkedList<Integer> solution;
	private void core() throws Exception {
		int ntest = nextInt();
		for (int test = 0; test < ntest; test++) {
			int sum = nextInt();
			base = nextInt();
			int[] digit = calc(sum, base);
			
			int[] used = new int[digit.length];
			numPossible = 0;
			solution = new LinkedList<Integer>();
			go(sum, sum+1, used);
			
			writeCase(test);
			writer.println(numPossible);
			writer.flush();
		}
	}
	private void go(int sum, int last, int[] used) {
		if (sum == 0) {
			++numPossible;
		}
		else {
			for (int add = Math.min(last-1, sum); add >= 1; add--) {
				int[] digit = calc(add, base);
				boolean ok = true;
				for (int i = 0; i < digit.length; i++) {
					int cur = digit[i];
					if (((used[i] >> cur) & 1) > 0) {
						ok = false;
						break;
					}
				}
				if (ok) {
					for (int i = 0; i < digit.length; i++) {
						int cur = digit[i];
						used[i] ^= 1 << cur;
					}
					solution.add(add);
					go(sum-add, add, used);
					for (int i = 0; i < digit.length; i++) {
						int cur = digit[i];
						used[i] ^= 1 << cur;
					}
					solution.removeLast();
				}
			}
		}
	}
	private int[] calc(int sum, int base) {
		int n = sum;
		int len = 0;
		while(n > 0) {
			n /= base;
			++len;
		}
		int[] res = new int[len];
		n = sum;
		int i = 0;
		while(n > 0) {
			res[i] = n % base;
			n /= base;
			++i;
		}
		return res;
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
