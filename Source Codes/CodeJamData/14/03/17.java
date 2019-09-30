import java.io.*;
import java.util.Scanner;

public class Minesweeper_C_Q14 {

	private static final String PROBLEM_NAME = "C-large";

	private static final String INPUT_PATH = PROBLEM_NAME + ".in";
	private static final String OUTPUT_PATH = PROBLEM_NAME + "-Output.txt";

	private static final String NEW_LINE = System.getProperty("line.separator");

	private final int r;
	private final int c;
	private final int m;

	public Minesweeper_C_Q14(Scanner in) {
		r = in.nextInt();
		c = in.nextInt();
		m = in.nextInt();
	}

	//what a freakin mess
	public String solve() {
		StringBuilder solution = new StringBuilder();


		if (r == 1) {
			solution.append('c');
			for (int i = 1 ; i < c - m ; i++) {
				solution.append('.');
			}
			for (int i = c - m ; i < c ; i++) {
				solution.append('*');
			}
			return solution.toString();
		}


		if (c == 1) {
			solution.append('c').append(NEW_LINE);
			for (int i = 1 ; i < r - m ; i++) {
				solution.append('.').append(NEW_LINE);
			}
			for (int i = r - m ; i < r ; i++) {
				solution.append('*').append(NEW_LINE);
			}
			return solution.toString().trim();
		}


		if (m == r * c - 1) {
			for (int i = 0 ; i < r ; i++) {
				for (int j = 0 ; j < c ; j++) {
					solution.append('*');
				}
				if (i != r - 1) {
					solution.append(NEW_LINE);
				}
			}
			solution.deleteCharAt(solution.length() - 1);
			solution.append('c');
			return solution.toString();
		}


		if (r == 2) {
			if (m % 2 == 0 && m < r * c - 2) {
				solution.append('c');
				for (int i = 1 ; i < c - (m / 2) ; i++) {
					solution.append('.');
				}
				for (int i = c - (m / 2) ; i < c ; i++) {
					solution.append('*');
				}
				solution.append(NEW_LINE);
				for (int i = 0 ; i < c - (m / 2) ; i++) {
					solution.append('.');
				}
				for (int i = c - (m / 2) ; i < c ; i++) {
					solution.append('*');
				}
				return solution.toString();
			} else {
				return "Impossible";
			}
		}


		if (c == 2) {
			if (m % 2 == 0 && m < r * c - 2) {
				solution.append('c').append('.').append(NEW_LINE);
				for (int i = 1 ; i < r - (m / 2) ; i++) {
					solution.append('.').append('.').append(NEW_LINE);
				}
				for (int i = r - (m / 2) ; i < r ; i++) {
					solution.append('*').append('*').append(NEW_LINE);
				}
				return solution.toString().trim();
			} else {
				return "Impossible";
			}
		}


		if (m > r * c - 4) {
			return "Impossible";
		}


		if (m <= (r - 2) * (c - 2)) {
			int fullRows = m / (c - 2);
			for (int i = 0 ; i < fullRows ; i++) {
				for (int j = 0 ; j < c - 2 ; j++) {
					solution.append('*');
				}
				solution.append('.').append('.').append(NEW_LINE);
			}
			for (int j = 0 ; j < m - fullRows * (c - 2) ; j++) {
				solution.append('*');
			}
			for (int j = m - fullRows * (c - 2) ; j < c ; j++) {
				solution.append('.');
			}
			solution.append(NEW_LINE);
			for (int i = fullRows + 1 ; i < r ; i++) {
				for (int j = 0 ; j < c ; j++) {
					solution.append('.');
				}
				if (i != r - 1) {
					solution.append(NEW_LINE);
				}
			}
			solution.deleteCharAt(solution.length() - 1);
			solution.append('c');
			return solution.toString();
		}

		if (m <= r * c - 8) {
			int mLeft = m - (r - 2) * (c - 2);
			boolean fillCorner = mLeft % 2 == 0;
			int fullRows = (mLeft + 1) / 2;
			int fullColumns = Math.max(0, fullRows - (r - 3));
			fullRows -= fullColumns;

			for (int i = 0 ; i < fullRows ; i++) {
				for (int j = 0 ; j < c ; j++) {
					solution.append('*');
				}
				solution.append(NEW_LINE);
			}
			for (int i = fullRows ; i < r - 2 ; i++) {
				for (int j = 0 ; j < c - 2 ; j++) {
					solution.append('*');
				}
				if (i == r - 3 && !fillCorner) {
					solution.deleteCharAt(solution.length() - 1);
					solution.append('.');
				}
				solution.append('.').append('.').append(NEW_LINE);
			}
			for (int j = 0 ; j < fullColumns ; j++) {
				solution.append('*');
			}
			for (int j = fullColumns ; j < c ; j++) {
				solution.append('.');
			}
			solution.append(NEW_LINE);
			for (int j = 0 ; j < fullColumns ; j++) {
				solution.append('*');
			}
			for (int j = fullColumns ; j < c - 1 ; j++) {
				solution.append('.');
			}
			solution.append('c');
			return solution.toString();
		}


		if ((r * c - m) % 2 == 0) {
			for (int i = 0 ; i < r - 2 ; i++) {
				for (int j = 0 ; j < c ; j++) {
					solution.append('*');
				}
				solution.append(NEW_LINE);
			}
			for (int j = 0 ; j < c - 3 ; j++) {
				solution.append('*');
			}
			if (r * c - m == 6) {
				solution.append('.');
			} else {
				solution.append('*');
			}
			solution.append('.').append('.').append(NEW_LINE);
			for (int j = 0 ; j < c - 3 ; j++) {
				solution.append('*');
			}
			if (r * c - m == 6) {
				solution.append('.');
			} else {
				solution.append('*');
			}
			solution.append('.').append('c');
			return solution.toString();
		}

		return "Impossible";
	}

	public static void main(String[] args) throws Exception {
		try (Scanner in = new Scanner(new File(INPUT_PATH)) ;
			 BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(OUTPUT_PATH)))) {

			int t = in.nextInt();
			for (int i = 1 ; i <= t ; i++) {
				System.out.println("Case #" + i);
				out.write("Case #" + i + ":");
				out.newLine();
				out.write(new Minesweeper_C_Q14(in).solve());
				out.newLine();
				out.flush();
			}
		}
	}

}
