import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class A implements Runnable {

	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok;
	
	public static void main(String[] args) {
		new Thread(null, new A(), "", 64*1024*1024).start();
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
		}
	}
	
//------------------------------------------------------------------------------

	private void solveTest() throws IOException {
		long st = readLong();
		int n = readInt();
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = readLong();
		}
		Arrays.sort(a);
		if (st == 1) {
			out.println(n);
			return;
		}
		int[] add = new int[n+1];
		long[] w = new long[n+1];
		w[0] = st;
		for (int i = 0; i < n; i++) {
			if (w[i] > a[i]) {
				w[i+1] = w[i] + a[i];
				add[i+1] = add[i];
			} else {
				add[i+1] = add[i];
				long now = w[i];
				long toAdd = w[i] - 1;
				while (true) {
					add[i+1]++;
					now += toAdd;
					if (now > a[i]) {
						break;
					}
					toAdd = now - 1;
				}
				w[i+1] = now + a[i];
			}
		}
		int bestAns = n;
		for (int i = 0; i <= n; i++) {
			int curAns = add[i] + (n - i);
			bestAns = min(bestAns, curAns);
		}
		out.println(bestAns);
	}
	
}
