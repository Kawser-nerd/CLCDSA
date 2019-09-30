import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class Rotate {

	private Scanner fin;
	private PrintStream fout;

	public Rotate(String in, String out) {
		try {
			fin = new Scanner(new FileInputStream(in));
			fout = new PrintStream(out);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private char table[][];

	private void run() {
		int cas = fin.nextInt();
		for (int t = 1; t <= cas; ++t) {
			process(t);
		}
	}

	private void process(int t) {
		int sd = fin.nextInt();
		int k = fin.nextInt();
		table = new char[sd][sd];
		for (int i = sd - 1; i >= 0; --i) {
			String line = fin.next();
			for (int j = 0; j < sd; ++j) {
				table[j][i] = line.charAt(j);
			}
		}
		for (int i = 0; i < sd; ++i) {
			int r = sd - 1;
			for (int j = sd - 1; j >= 0; --j) {
				if (table[j][i] != '.') {
					table[r--][i] = table[j][i];
				}
			}
			for (; r >= 0; --r) {
				table[r][i] = '.';
			}
		}
		boolean red = win('R', sd, k);
		boolean blue = win('B', sd, k);
		if (red && blue) {
			fout.println("Case #" + t + ": Both");
		} else if (red) {
			fout.println("Case #" + t + ": Red");
		} else if (blue) {
			fout.println("Case #" + t + ": Blue");
		} else {
			fout.println("Case #" + t + ": Neither");
		}
	}

	private boolean win(char c, int sd, int k) {
		for (int i = 0; i < sd; ++i) {
			int cnt = 0;
			for (int j = 0; j < sd; ++j) {
				if (table[i][j] == c) {
					cnt ++;
					if (cnt == k) return true;
				} else {
					cnt = 0;
				}
			}
		}
		for (int j = 0; j < sd; ++j) {
			int cnt = 0;
			for (int i = 0; i < sd; ++i) {
				if (table[i][j] == c) {
					cnt ++;
					if (cnt == k) return true;
				} else {
					cnt = 0;
				}
			}
		}
		for (int a = 0; a < sd; ++a) {
			int cnt = 0;
			for (int b = 0; b < sd - a; ++b) {
				if (table[b][a+b] == c) {
					cnt ++;
					if (cnt == k) return true;
				} else {
					cnt = 0;
				}
			}
		}
		for (int a = 0; a < sd; ++a) {
			int cnt = 0;
			for (int b = 0; b < sd - a; ++b) {
				if (table[a+b][b] == c) {
					cnt ++;
					if (cnt == k) return true;
				} else {
					cnt = 0;
				}
			}
		}
		for (int a = 0; a < sd; ++a) {
			int cnt = 0;
			for (int b = 0; b < sd - a; ++b) {
				if (table[b][sd-a-b-1] == c) {
					cnt ++;
					if (cnt == k) return true;
				} else {
					cnt = 0;
				}
			}
		}
		for (int a = 0; a < sd; ++a) {
			int cnt = 0;
			for (int b = 0; b < sd - a; ++b) {
				if (table[a+b][sd-b-1] == c) {
					cnt ++;
					if (cnt == k) return true;
				} else {
					cnt = 0;
				}
			}
		}
		return false;
	}

	public static void main(String[] args) {
		new Rotate("a.in", "a.out").run();
	}

}
