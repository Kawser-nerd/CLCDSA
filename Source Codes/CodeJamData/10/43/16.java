import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main implements Runnable {
	private boolean _ReadFromFile = System.getProperty("ONLINE_JUDGE") == null;
	private boolean _WriteToFile = true;
	static final String TASK_ID = "c1";
	static final String IN_FILE = TASK_ID + ".in";
	static final String OUT_FILE = TASK_ID + ".out";
	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	private void core() throws Exception {
		int ntest = nextInt();
		for (int test = 0; test < ntest; test++) {
			int n = nextInt();
			int[] x1 = new int[n], x2 = new int[n], y1 = new int[n], y2 = new int[n];
			for (int i = 0; i < y2.length; i++) {
				x1[i] = nextInt();
				y1[i] = nextInt();
				x2[i] = nextInt();
				y2[i] = nextInt();
			}
			
			int lim = 101;
			int[][] board = new int[lim][lim];
			for (int i = 0; i < x1.length; i++) {
				for (int row = y1[i]; row <= y2[i]; row++) {
					for (int col = x1[i]; col <= x2[i]; col++) {
						board[row][col] = 1;
					}
				}
			}
			
			int res = solve(board);
			writeCase(test);
			writer.println(" " + res);
		}
	}
	
	private int solve(int[][] board) {
		for (int day = 0;; day++) {
			boolean empty = true;
			for (int i = 0; empty && i < board.length; i++) {
				for (int j = 0; empty && j < board[i].length; j++) {
					if (board[i][j] > 0) {
						empty = false;
						break;
					}
				}
			}
			if (empty) return day;
			for (int i = board.length-1; i >= 0; i--) {
				for (int j = board[i].length-1; j >= 0; j--) {
					if (i > 0 && j > 0 && board[i-1][j] > 0 && board[i][j-1] > 0) 
						board[i][j] = 1;
				}
			}
			for (int i = board.length-1; i >= 0; i--) {
				for (int j = board[i].length-1; j >= 0; j--) {
					boolean die = true;
					if (i > 0 && board[i-1][j] > 0) die = false;
					if (j > 0 && board[i][j-1] > 0) die = false;
					if (die) {
						board[i][j] = 0;
					}
				}
			}
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
