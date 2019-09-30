import java.util.*;
import java.math.*;
import java.io.*;

public class A {
	private void solve() throws Exception {
		boolean xWon = false, oWon = false;
		char[][] state = new char[4][];
		boolean hasFree = false;
		for (int i = 0; i < 4; ++i) {
			state[i] = nextToken().toCharArray();
			for (int j = 0; j < 4; ++j) {
				hasFree |= state[i][j] == '.';
			}
		}
		for (char c : Arrays.asList('X', 'O')) {
			boolean win = false;
			for (int i = 0; i < 4; ++i) {
				boolean eq = true;
				for (int j = 0; j < 4; ++j) {
					eq &= checkState(state[i][j], c);
				}
				win |= eq;
				eq = true;
				for (int j = 0; j < 4; ++j) {
					eq &= checkState(state[j][i], c);
				}
				win |= eq;
			}
			for (int dir = 0; dir < 2; ++dir) {
				boolean eq = true;
				for (int i = 0; i < 4; ++i) {
					eq &= checkState(state[i][dir * i + (1 - dir) * (3 - i)], c);
				}
				win |= eq;
			}
			if (c == 'X') {
				xWon = win;
			} else {
				oWon = win;
			}
		}
		if (xWon) {
			if (oWon) {
				throw new RuntimeException();
			}
			out.println("X won");
		} else if (oWon) {
			out.println("O won");
		} else if (hasFree) {
			out.println("Game has not completed");
		} else {
			out.println("Draw");
		}
	}

	private boolean checkState(char state, char player) {
		return state == player || state == 'T';
	}

	public void run() {
		try {
			int tc = nextInt();
			for (int it = 1; it <= tc; ++it) {
				System.err.println(it);
				out.print("Case #" + it + ": ");
				solve();
			}
		} catch (Exception e) {
			NOO(e);
		} finally {
			out.close();
		}
	}

	PrintWriter out;
	BufferedReader in;
	StringTokenizer St;

	void NOO(Exception e) {
		e.printStackTrace();
		System.exit(42);
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String nextToken() {
		while (!St.hasMoreTokens()) {
			try {
				String line = in.readLine();
				if (line == null)
					return null;
				St = new StringTokenizer(line);
			} catch (Exception e) {
				NOO(e);
			}
		}
		return St.nextToken();
	}

	private A(String name) {
		try {
			in = new BufferedReader(new FileReader(name + ".in"));
			St = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(name + ".out"));
		} catch (Exception e) {
			NOO(e);
		}
	}

	public static void main(String[] args) {
		new A("A").run();
	}
}
