import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/*
 * AtCoder Beginner Contest 100 D
 */
public class Main {

	public static void main(String[] args) {

		InputScanner in = new InputScanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		Task task = new Task();
		task.run(in, out);

		in.close();
		out.close();
	}

	static class Task {

		public void run(InputScanner in, PrintWriter out) {

			int N = in.nextInt();
			int M = in.nextInt();
			int EVAL_NUM = 3;
			long[][] xyz = new long[N][EVAL_NUM];
			for (int i = 0; i < N; i++) {
				xyz[i][0] = in.nextLong();
				xyz[i][1] = in.nextLong();
				xyz[i][2] = in.nextLong();
			}

			long ans = 0;
			for (int i = 0; i < Math.pow(2, EVAL_NUM); i++) {

				boolean[] isPlus = getCondition(i, EVAL_NUM);
				long[] sum = new long[N];
				Arrays.fill(sum, 0);
				for (int j = 0; j < N; j++) {
					sum[j] += (isPlus[0] ? xyz[j][0] : -xyz[j][0]);
					sum[j] += (isPlus[1] ? xyz[j][1] : -xyz[j][1]);
					sum[j] += (isPlus[2] ? xyz[j][2] : -xyz[j][2]);
				}

				Arrays.sort(sum);
				long eval = 0;
				for (int j = sum.length - 1; j > sum.length - 1 - M; j--) {
					eval += sum[j];
				}

				ans = Math.max(ans, eval);
			}

			out.print(ans);
		}
	}

	static boolean[] getCondition(int i, int num) {

		int index = i;
		boolean[] isUsed = new boolean[num];

		for (int j = 0; j < num; j++) {
			isUsed[j] = (index % 2 == 1 ? true : false);
			index /= 2;
		}

		return isUsed;
	}

	/*
	 * extends java.util.Scanner
	 */
	static class InputScanner {

		Scanner scanner;

		public InputScanner(InputStream inputStream) {
			this.scanner = new Scanner(inputStream);
		}

		public boolean hasNext() {
			return scanner.hasNext();
		}

		public int nextInt() {
			return Integer.parseInt(scanner.next());
		}

		public long nextLong() {
			return Long.parseLong(scanner.next());
		}

		public double nextDouble() {
			return Double.parseDouble(scanner.next());
		}
		public String next() {
			return scanner.next();
		}

		public int[] nextIntArray(int n) {
			int[] ret = new int[n];
			for (int i = 0; i < n; i++) {
				ret[i] = scanner.nextInt();
			}
			return ret;
		}

		public int[][] nextIntArray(int h, int w) {
			int[][] ret = new int[h][w];
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					ret[i][j] = scanner.nextInt();
				}
			}
			return ret;
		}

		public long[] nextLongArray(int n) {
			long[] ret = new long[n];
			for (int i = 0; i < n; i++) {
				ret[i] = scanner.nextLong();
			}
			return ret;
		}

		public long[][] nextlongArray(int h, int w) {
			long[][] ret = new long[h][w];
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					ret[i][j] = scanner.nextLong();
				}
			}
			return ret;
		}

		public double[] nextDoubleArray(int n) {
			double[] ret = new double[n];
			for (int i = 0; i < n; i++) {
				ret[i] = scanner.nextDouble();
			}
			return ret;
		}

		public double[][] nextDoubleArray(int h, int w) {
			double[][] ret = new double[h][w];
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					ret[i][j] = scanner.nextLong();
				}
			}
			return ret;
		}

		public String[] nextStringArray(int n) {
			String[] ret = new String[n];
			for (int i = 0; i < n; i++) {
				ret[i] = scanner.next();
			}
			return ret;
		}

		public String[] nextStringArray(String split) {
			String[] ret = scanner.next().split(split);
			return ret;
		}

		public String[][] nextStringArray(int h, int w) {
			String[][] ret = new String[h][w];
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					ret[i][j] = scanner.next();
				}
			}
			return ret;
		}

		public String[][] nextStringArray(int h, String split) {
			String[][] ret = new String[h][];
			for (int i = 0; i < h; i++) {
				ret[i] = scanner.next().split(split);
			}
			return ret;
		}

		public void close() {
			scanner.close();
		}

	}

}