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
			int size = 2 * n - 1;
			char[][] board = new char[size][size];
			for (int i = 0; i < board.length; i++) {
				String nowString = reader.readLine();
				while(nowString.length() < size)
					nowString += " ";
				board[i] = nowString.toCharArray();
			}
			
			for (int i = 0; i < board.length; i++) {
				for (int j = 0; j < board.length; j++) {
					if (board[i][j] != ' ')
						break;
					board[i][j] = '*';
				}
				
				for (int j = board.length-1; j >= 0; j--) {
					if (board[i][j] != ' ')
						break;
					board[i][j] = '*';
				}
			}
			
			int res = Integer.MAX_VALUE;
			for (int i = 0; i < board.length; i++) {
				for (int j = 0; j < board.length; j++) {
					int mid = board.length / 2;
					int m = 1 + getMax(dist(i,j,0,mid), dist(i, j, mid, 0), 
										dist(i, j, mid, 2*mid), 
										dist(i, j, 2*mid, mid)); 
					int newSize = m * 2 - 1;
					
					char[][] newBoard = new char[newSize][newSize];
					for (char[] cs : newBoard) {
						Arrays.fill(cs, '*');
					}
					
					for (int k = 0; k < board.length; k++) {
						for (int k2 = 0; k2 < board.length; k2++) {
							int row = k - i + m - 1;
							int col = k2 - j + m - 1;
							newBoard[row][col] = board[k][k2];
						}
					}
					
					debug(i, j);
					for (char[] cs : newBoard) {
						debug(cs);
					}
					debug(sym(newBoard));
					
					int newN = (newSize + 1) / 2;
					int cost = newN * newN - n*n;
					if (sym(newBoard))
						res = Math.min(res, cost);
				}
			}
			writeCase(test);
			writer.println(" " + res);
		}
	}
	private int getMax(int dist, int dist2, int dist3, int dist4) {
		int res = dist;
		if (dist2 > res) res = dist2;
		if (dist3 > res) res = dist3;
		if (dist4 > res) res = dist4;
		return res;
	}
	private int dist(int i, int j, int k, int k2) {
		return Math.abs(i-k) + Math.abs(j-k2);
	}
	private boolean sym(char[][] newBoard) {
		int mid = newBoard.length / 2;
		for (int i = 0; i < newBoard.length; i++) {
			for (int j = 0; j < newBoard.length; j++) {
				if (newBoard[i][j] != '*') {
					char ch = newBoard[i][2*mid-j];
					if (ch != '*' && ch != newBoard[i][j]) {
						debug(i, j);
						return false;
					}
					
					ch = newBoard[2*mid-i][j];
					if (ch != '*' && ch != newBoard[i][j]) {
						debug(i, j);
						return false;
					}
				}
			}
		}
		return true;
	}
	private void writeCase(int test) {
		writer.printf("Case #%d:", test+1);
	}
	void debug(Object...os) {
//		System.out.println(Arrays.deepToString(os));
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
