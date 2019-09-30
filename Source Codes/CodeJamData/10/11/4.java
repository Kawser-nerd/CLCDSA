import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main implements Runnable {
	private boolean _ReadFromFile = System.getProperty("ONLINE_JUDGE") == null;
	private boolean _WriteToFile = true;
	static final String TASK_ID = "al";
	static final String IN_FILE = TASK_ID + ".in";
	static final String OUT_FILE = TASK_ID + ".out";
	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	private void core() throws Exception {
		int ntest = nextInt();
		for (int test = 0; test < ntest; test++) {
			int n = nextInt();
			int len = nextInt();
			String[] board = new String[n];
			for (int i = 0; i < board.length; i++) {
				board[i] = nextToken();
			}
			for (int i = 0; i < board.length; i++) {
				board[i] = shiftRight(board[i]);
			}
			boolean red = good('R', board, len);
			boolean blue = good('B', board, len);
			writeCase(test);
			String res = "";
			if (red && blue) res = "Both";
			else if (red) res = "Red";
			else if (blue) res = "Blue";
			else res = "Neither";
			writer.println(" " + res);
		}
	}
	private boolean good(char c, String[] board, int len) {
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board.length; j++) {
				if (board[i].charAt(j) == c) {
					for (int drow = -1; drow <= 1; drow++) {
						for (int dcol = -1; dcol <= 1; dcol++) {
							if (drow != 0 || dcol != 0) {
								int row = i;
								int col = j;
								boolean ok = true;
								for (int times = 0; times < len; times++) {
									if (!(0 <= row && row < board.length && 0 <= col && col < board.length)) 
										ok = false;
									else if (board[row].charAt(col) != c)
										ok = false;
									row += drow;
									col += dcol;
								}
								if (ok) return true;
							}
						}
					}
				}
			}
		}
		return false;
	}
	private String shiftRight(String string) {
		String res = "";
		for (int i = 0; i < string.length(); i++) {
			if (string.charAt(i) != '.')
				res += string.charAt(i);
		}
		while(res.length() < string.length())
			res = "." + res;
		return res;
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
