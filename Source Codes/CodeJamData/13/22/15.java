import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class B implements Runnable {

	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok;
	
	public static void main(String[] args) {
		new Thread(null, new B(), "", 64*1024*1024).start();
	}

	public void run() {
		try {
			long t1 = 0, t2 = 0;
			if (LOCAL) {
				t1 = System.currentTimeMillis();
			}
			Locale.setDefault(Locale.US);
			if (LOCAL) {
				in = new BufferedReader(new FileReader("input.txt"));
				out = new PrintWriter("output.txt");
			} else {
				in = new BufferedReader(new InputStreamReader(System.in));
				out = new PrintWriter(System.out);
			}
			tok = new StringTokenizer("");
			solve();
			in.close();
			out.close();
			if (LOCAL) {
				t2 = System.currentTimeMillis();
				System.err.println("Time = " + (t2 - t1) + " ms.");
			}
		} catch (Throwable e) {
			e.printStackTrace(System.err);
			throw new RuntimeException();
		}
	}

	String readString() throws IOException {
		while (!tok.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) return null;
			tok = new StringTokenizer(line);
		}
		return tok.nextToken();
	}
	
	int readInt() throws IOException {
		return Integer.parseInt(readString());
	}
	
	long readLong() throws IOException {
		return Long.parseLong(readString());
	}
	
	double readDouble() throws IOException {
		return Double.parseDouble(readString());
	}
	
	static class Mergesort {

		private Mergesort() {}

		public static void sort(int[] a) {
			mergesort(a, 0, a.length - 1);
		}

		public static void sort(long[] a) {
			mergesort(a, 0, a.length - 1);
		}

		public static void sort(double[] a) {
			mergesort(a, 0, a.length - 1);
		}

		private static final int MAGIC_VALUE = 42;

		private static void mergesort(int[] a, int leftIndex, int rightIndex) {
			if (leftIndex < rightIndex) {
				if (rightIndex - leftIndex <= MAGIC_VALUE) {
					insertionSort(a, leftIndex, rightIndex);
				} else {
					int middleIndex = (leftIndex + rightIndex) / 2;
					mergesort(a, leftIndex, middleIndex);
					mergesort(a, middleIndex + 1, rightIndex);
					merge(a, leftIndex, middleIndex, rightIndex);
				}
			}
		}

		private static void mergesort(long[] a, int leftIndex, int rightIndex) {
			if (leftIndex < rightIndex) {
				if (rightIndex - leftIndex <= MAGIC_VALUE) {
					insertionSort(a, leftIndex, rightIndex);
				} else {
					int middleIndex = (leftIndex + rightIndex) / 2;
					mergesort(a, leftIndex, middleIndex);
					mergesort(a, middleIndex + 1, rightIndex);
					merge(a, leftIndex, middleIndex, rightIndex);
				}
			}
		}

		private static void mergesort(double[] a, int leftIndex, int rightIndex) {
			if (leftIndex < rightIndex) {
				if (rightIndex - leftIndex <= MAGIC_VALUE) {
					insertionSort(a, leftIndex, rightIndex);
				} else {
					int middleIndex = (leftIndex + rightIndex) / 2;
					mergesort(a, leftIndex, middleIndex);
					mergesort(a, middleIndex + 1, rightIndex);
					merge(a, leftIndex, middleIndex, rightIndex);
				}
			}
		}

		private static void merge(int[] a, int leftIndex, int middleIndex, int rightIndex) {
			int length1 = middleIndex - leftIndex + 1;
			int length2 = rightIndex - middleIndex;
			int[] leftArray = new int[length1];
			int[] rightArray = new int[length2];
			System.arraycopy(a, leftIndex, leftArray, 0, length1);
			System.arraycopy(a, middleIndex + 1, rightArray, 0, length2);
			for (int k = leftIndex, i = 0, j = 0; k <= rightIndex; k++) {
				if (i == length1) {
					a[k] = rightArray[j++];
				} else if (j == length2) {
					a[k] = leftArray[i++];
				} else {
					a[k] = leftArray[i] <= rightArray[j] ? leftArray[i++] : rightArray[j++];
				}
			}
		}

		private static void merge(long[] a, int leftIndex, int middleIndex, int rightIndex) {
			int length1 = middleIndex - leftIndex + 1;
			int length2 = rightIndex - middleIndex;
			long[] leftArray = new long[length1];
			long[] rightArray = new long[length2];
			System.arraycopy(a, leftIndex, leftArray, 0, length1);
			System.arraycopy(a, middleIndex + 1, rightArray, 0, length2);
			for (int k = leftIndex, i = 0, j = 0; k <= rightIndex; k++) {
				if (i == length1) {
					a[k] = rightArray[j++];
				} else if (j == length2) {
					a[k] = leftArray[i++];
				} else {
					a[k] = leftArray[i] <= rightArray[j] ? leftArray[i++] : rightArray[j++];
				}
			}
		}

		private static void merge(double[] a, int leftIndex, int middleIndex, int rightIndex) {
			int length1 = middleIndex - leftIndex + 1;
			int length2 = rightIndex - middleIndex;
			double[] leftArray = new double[length1];
			double[] rightArray = new double[length2];
			System.arraycopy(a, leftIndex, leftArray, 0, length1);
			System.arraycopy(a, middleIndex + 1, rightArray, 0, length2);
			for (int k = leftIndex, i = 0, j = 0; k <= rightIndex; k++) {
				if (i == length1) {
					a[k] = rightArray[j++];
				} else if (j == length2) {
					a[k] = leftArray[i++];
				} else {
					a[k] = leftArray[i] <= rightArray[j] ? leftArray[i++] : rightArray[j++];
				}
			}
		}

		private static void insertionSort(int[] a, int leftIndex, int rightIndex) {
			for (int i = leftIndex + 1; i <= rightIndex; i++) {
				int current = a[i];
				int j = i - 1;
				while (j >= leftIndex && a[j] > current) {
					a[j + 1] = a[j];
					j--;
				}
				a[j + 1] = current;
			}
		}

		private static void insertionSort(long[] a, int leftIndex, int rightIndex) {
			for (int i = leftIndex + 1; i <= rightIndex; i++) {
				long current = a[i];
				int j = i - 1;
				while (j >= leftIndex && a[j] > current) {
					a[j + 1] = a[j];
					j--;
				}
				a[j + 1] = current;
			}
		}

		private static void insertionSort(double[] a, int leftIndex, int rightIndex) {
			for (int i = leftIndex + 1; i <= rightIndex; i++) {
				double current = a[i];
				int j = i - 1;
				while (j >= leftIndex && a[j] > current) {
					a[j + 1] = a[j];
					j--;
				}
				a[j + 1] = current;
			}
		}

	}
	
	void debug(Object... o) {
		if (LOCAL) {
			System.err.println(Arrays.deepToString(o));
		}
	}
	
	final static boolean LOCAL = System.getProperty("ONLINE_JUDGE") == null;
	
	private void solve() throws IOException {
		int t = readInt();
		for (int i = 1; i <= t; i++) {
			out.printf("Case #%d: ", i);
			solveTest();
			if (i % 10 == 0) {
				System.out.println(i + " tests processed");
				System.out.flush();
			}
		}
	}
	
//------------------------------------------------------------------------------
	
	private void solveTest() throws IOException {
		int n = readInt();
		int needX = readInt();
		needX = abs(needX);
		int needY = readInt();
		int layer = 0;
		int count = 1;
		int onCurrent = 1;
		while (count < n) {
			layer++;
			onCurrent += 4;
			count += onCurrent;
		}
		//debug(n, needX, needY, layer, onCurrent);
		if ((needX + needY) / 2 > layer) {
			out.printf("%.15f\n", 0.0);
			return;
		}
		if ((needX + needY) / 2 < layer) {
			out.printf("%.15f\n", 1.0);
			return;
		}
		if (count == n) {
			out.printf("%.15f\n", 1.0);
			return;
		}
		int onSide = onCurrent / 2;
		double[][] dp = new double[onSide + 1][onSide + 1];
		dp[0][0] = 1;
		int fall = n - (count - onCurrent);
		for (int have = 0; have < fall; have++) {
			int beginL = (have <= onSide) ? 0 : have - onSide;
			int beginR = have - beginL;
			for (int L = beginL, R = beginR; L <= onSide && R >= 0; L++, R--) {
				if (L == onSide) {
					dp[L][R+1] += dp[L][R];
				} else if (R == onSide) {
					dp[L+1][R] += dp[L][R];
				} else {
					dp[L][R+1] += dp[L][R] * 0.5;
					dp[L+1][R] += dp[L][R] * 0.5;
				}
			}
		}
		double ans = 0;
		for (int L = 0, R = fall; R >= 0; L++, R--) {
			if (L <= onSide && R <= onSide) {
				if (L >= needY + 1) {
					ans += dp[L][R];
				}
			}
		}
		out.printf("%.15f\n", ans);
	}
	
}
