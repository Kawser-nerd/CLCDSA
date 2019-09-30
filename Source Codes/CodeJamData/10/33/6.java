package c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.UnsupportedEncodingException;
import java.util.Date;
import java.util.LinkedHashMap;
import java.util.Map;

public class C {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Date start = new Date();

		try {
			// BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("C-in.txt"), "utf8"));
			// BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("C-out.txt"), "utf8"));

			// BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("C-small.in"), "utf8"));
			// BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("C-small.out"), "utf8"));

			BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("C-large.in"), "utf8"));
			BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("C-large.out"), "utf8"));

			// BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

			String line = reader.readLine();
			int caseCount = Integer.valueOf(line);
			for (int index = 0; index < caseCount; index++) {
				line = reader.readLine();
				if (line != null) {
					writer.write("Case #" + (index + 1) + ": ");
					String[] parts = line.split(" ");
					M = Integer.valueOf(parts[0]);
					N = Integer.valueOf(parts[1]);

					for (int i = 0; i < M; i++) {
						line = reader.readLine();
						for (int j = 0; j < N / 4; j++) {
							char c = line.charAt(j);
							int n = c - '0';
							if (n > 9) {
								n = c - 'A' + 10;
							}
							board[i][4 * j] = n / 8;
							board[i][4 * j + 1] = (n % 8) / 4;
							board[i][4 * j + 2] = (n % 4) / 2;
							board[i][4 * j + 3] = n % 2;
						}
					}

					calculate(writer);
				} else {
					throw new RuntimeException("Fewer testcases (" + index + ") than expected (" + caseCount + ")!");
				}
			}

			reader.close();
			writer.close();
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

		Date end = new Date();
		System.err.println("Finished in " + (end.getTime() - start.getTime()) + "ms.");
	}

	private static int M;
	private static int N;

	private static int board[][] = new int[512][512];

	private static void calculate(BufferedWriter writer) throws IOException {
		int classCount = 0;
		int biggest = 0;
		Map<Integer, Integer> classes = new LinkedHashMap<Integer, Integer>();

		// classes.put(4, 3);
		// classes.put(6, 1);
		// classes.put(3, 7);
		// classes.put(6, classes.get(6) + 1);
		// biggest = 6;

		int max = 0;
		do {
			max = 0;
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < N; j++) {
					int m = check(i, j);
					if (m > max) {
						max = m;
					}
				}
			}
			if (max > 0) {
				int count = 0;

				for (int i = 0; i < M; i++) {
					for (int j = 0; j < N; j++) {
						int m = check(i, j);
						if (m == max) {
							cut(i, j, m);
							count++;
						}
					}
				}

				classes.put(max, count);

				if (max > biggest) {
					biggest = max;
				}
			}
		} while (max > 1);

		classCount = classes.size();
		writer.write(new Integer(classCount).toString());
		writer.newLine();
		for (int i = biggest; i > 0; i--) {
			Integer count = classes.get(i);
			if (count != null) {
				writer.write(new Integer(i).toString() + " " + count.toString());
				writer.newLine();
			}
		}
		writer.flush();
	}

	private static int check(int i, int j) {
		int size = 1;

		if (board[i][j] < 9) {
			boolean extendable = true;
			while (extendable) {
				if (i + size >= M || j + size >= N) {
					extendable = false;
				} else if (board[i][j] != board[i + size][j + size]) {
					extendable = false;
				} else {
					for (int l = j + size - 1; l >= j; l--) {
						if ((l - j + size) % 2 == 0) {
							if (board[i + size][l] != board[i][j]) {
								extendable = false;
							}
						} else {
							if (board[i + size][l] != 1 - board[i][j]) {
								extendable = false;
							}
						}
					}

					for (int l = i + size - 1; l >= i; l--) {
						if ((l - i + size) % 2 == 0) {
							if (board[l][j + size] != board[i][j]) {
								extendable = false;
							}
						} else {
							if (board[l][j + size] != 1 - board[i][j]) {
								extendable = false;
							}
						}
					}

					if (extendable) {
						size++;
					}
				}
			}
		} else {
			size = 0;
		}

		return size;
	}

	private static void cut(int i, int j, int size) {
		for (int ii = i; ii < i + size; ii++) {
			for (int jj = j; jj < j + size; jj++) {
				board[ii][jj] = 9;
			}
		}
	}

}
