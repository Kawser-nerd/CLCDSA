import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class DrumDecorator {

	public static void main(String[] args) throws Exception {
		DrumDecorator object = new DrumDecorator();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase() + ".in"));
		Scanner scanner = new Scanner(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		int testCases = scanner.nextInt();

		for (int tc = 1; tc <= testCases; tc++) {

			int r = scanner.nextInt();
			int c = scanner.nextInt();

			int result = object.solve(r, c);

			wr.write("Case #" + tc + ": " + result + "\r\n");

		}

		scanner.close();
		wr.close();
	}

	int[][] state;
	int r, c;

	Set<String> solutions;

	private int solve(int r, int c) {

		this.r = r;
		this.c = c;

		solutions = new HashSet<>();

		state = new int[r][c];

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				state[i][j] = -1;

		generate(0, 0);
		
		//System.out.println(solutions);

		return solutions.size();

	}

	private void generate(int rr, int cc) {

		if (rr == r) {

			boolean exists = false;
			for (int rotation = 0; exists == false && rotation < c; rotation++) {
				if (solutions.contains(encode(rotation))) {
					exists = true;
				}
			}

			if (!exists) {
				solutions.add(encode(0));
			}

			return;
		}

		// else, add something
		for (int value = 1; value <= 3; value++) {

			state[rr][cc] = value;

			if (ok(rr, cc) && ok(rr - 1, cc) && ok(rr, cc - 1) && ok(rr + 1, cc) && ok(rr, cc + 1)) {

				int nextRr = rr;
				int nextCc = cc + 1;

				if (nextCc == c) {
					nextRr++;
					nextCc = 0;
				}

				generate(nextRr, nextCc);
			}

			state[rr][cc] = -1;
		}

	}

	static int[] counts = new int[4];

	private boolean ok(int rr, int cc) {

		if (rr < 0 || rr >= r) {
			return true;
		}

		if (cc < 0) {
			cc += c;
		}

		if (cc >= c) {
			cc -= c;
		}

		int myValue = state[rr][cc];
		if (myValue == -1) {
			return true;
		}

		int up = -1, down = -1;

		if (rr > 0) {
			up = rr - 1;
		}

		if (rr + 1 < r) {
			down = rr + 1;
		}

		int left = getLeft(cc);
		int right = getRight(cc);

		int free = 2;
		if (up >= 0) {
			free++;
		}

		if (down >= 0) {
			free++;
		}

		Arrays.fill(counts, 0);

		if (up != -1 && state[up][cc] > 0) {
			counts[state[up][cc]]++;
		}

		if (down != -1 && state[down][cc] > 0) {
			counts[state[down][cc]]++;
		}

		if (state[rr][left] >= 0)
			counts[state[rr][left]]++;

		if (state[rr][right] >= 0)
			counts[state[rr][right]]++;

		int otherSum = 0;
		for (int i = 1; i <= 3; i++)
			if (i != myValue)
				otherSum += counts[i];

		if (counts[myValue] > myValue) {
			return false;
		}

		if ((free - otherSum) < myValue) {
			return false;
		}

		return true;
	}

	private int getRight(int cc) {
		if (cc + 1 < c) {
			return cc + 1;
		}

		return 0;
	}

	private int getLeft(int cc) {
		if (cc > 0)
			return cc - 1;

		return c - 1;
	}

	private String encode(int rotation) {

		StringBuilder sb = new StringBuilder();

		int start = rotation;

		for (int row = 0; row < r; row++) {

			if (row != 0) {
				sb.append("\n");
			}

			for (int i = 0; i < c; i++) {
				int index = (start + i) % c;

				sb.append(state[row][index] + "");
			}

		}

		return sb.toString();
	}

}
