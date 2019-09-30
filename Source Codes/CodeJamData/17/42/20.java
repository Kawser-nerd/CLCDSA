/* Google Code Jam Template by Sergey Esipenko, 2017 */
import java.io.*;
import java.util.*;
import java.util.function.ToIntFunction;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import static java.lang.Math.*;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.fill;
import static java.util.Arrays.sort;

public class Solution implements Runnable {
	
	/* START OF SOLUTION */
	
	static final Random random = new Random(7777L);
	
	void solve() throws IOException  {
		final int testNum = nextInt();
		for (int test = 1; test <= testNum; test++) {
			final long startTime = System.currentTimeMillis();
			solve(test);
			System.err.println("finished " + test + "/" + testNum + " in " + (System.currentTimeMillis() - startTime) + "ms");
		}
	}
	
	void solve(int test) throws IOException {
		out.print("Case #" + test + ": ");
		
		final int nSeats = nextInt();
		final int nCustomers = nextInt();
		final int nTickets = nextInt();
		
		final Ticket[] tickets = new Ticket [nTickets];
		
		for (int i = 0; i < nTickets; i++) {
			final int seat = nextInt() - 1;
			final int customer = nextInt() - 1;
			tickets[i] = new Ticket(seat, customer);
		}
		
		sort(tickets);
		
		
		int left = 1;
		int right = nTickets;
		
		int answer = nTickets;
		
		used = new int [nTickets][nCustomers];
		
		while (left <= right) {
			final int middle = (left + right) / 2;
			if (can(nSeats, nCustomers, tickets, middle) != -1) {
				answer = min(answer, middle);
				right = middle - 1;
			} else {
				left = middle + 1;
			}
		}
		out.println(answer + " " + can(nSeats, nCustomers, tickets, answer));
	}
	
	int tick = 1;
	int[][] used;
	
	int can(int nSeats, int nCustomers, Ticket[] tickets, int nRides) {
		tick++;
		
		int[] free = new int [nSeats];
		fill(free, nRides);
		
		int nPromotions = 0;
		
		for (final Ticket ticket : tickets) {
			boolean found = false;
			lp: for (int seat = ticket.seat; seat >= 0; seat--) {
				if (free[seat] > 0) {
					for (int ride = 0; ride < nRides; ride++) {
						if (used[ride][ticket.customer] != tick) {
							used[ride][ticket.customer] = tick;
							free[seat]--;
							if (seat != ticket.seat)
								nPromotions++;
							found = true;
							break lp;
						}
					}
				}
			}
			if (!found)
				return -1;
		}		
		
		return nPromotions;
	}

	static final class Ticket implements Comparable<Ticket> {
		final int seat;
		final int customer;
		
		public Ticket(int seat, int customer) {
			this.seat = seat;
			this.customer = customer;
		}

		@Override
		public int compareTo(Ticket ticket) {
			if (seat != ticket.seat)
				return Integer.compare(seat, ticket.seat);
			if (customer != ticket.customer)
				return Integer.compare(customer, ticket.customer);
			return 0;
		}
	}
	
	/* END OF SOLUTION */
	/************************************************************************** 
	 * Entry point
	 *************************************************************************/
	
	static final Solution INSTANCE = new Solution();
	static final boolean WRITE_LOG = true;
	static final long STACK_SIZE = 1L << 24; // < 0 to default stack size
	
	static final String ROOT = "." + File.separator;
	static final String INPUT_FOLDER = ROOT + "input";
	static final String OUTPUT_FOLDER = ROOT + "output";
	static final String INPUT_EXTENSION = "in";
	static final String OUTPUT_EXTENSION = "out";
	static final Pattern SMALL_INPUT_PATTERN_SINGLE = Pattern.compile("-small-attempt([0-9]+).in");
	static final Pattern SMALL_INPUT_PATTERN_MULTIPLE = Pattern.compile("-small-([0-9]+)-attempt([0-9]+).in");
	
	static final ToIntFunction<String> FILE_PRIORITY = (String filename) -> {
		if (filename.endsWith("-large.in"))
			return Integer.MAX_VALUE / 7;
		int priority = -1;
		/* Single small input pattern */ {
			final Matcher matcher = SMALL_INPUT_PATTERN_SINGLE.matcher(filename);
			if (matcher.find()) {
				try {
					priority = Integer.parseInt(matcher.group(1));
				} catch (NumberFormatException ex) {
					ex.printStackTrace();
				}
			}
		}
		/* Multiple small input pattern */ {
			final Matcher matcher = SMALL_INPUT_PATTERN_MULTIPLE.matcher(filename);
			if (matcher.find()) {
				try {
					final int nInput = Integer.parseInt(matcher.group(1));
					final int nAttempt = Integer.parseInt(matcher.group(2));
					priority = nInput * 1000 + nAttempt;
				} catch (NumberFormatException ex) {
					ex.printStackTrace();
				}
			}
		}
		return priority; 
	};
	
	static long initTime;
	static String inputFileName = "sample." + INPUT_EXTENSION;
	static String outputFileName;
	
	@SuppressWarnings("unused")
	public static void main(String[] args) throws IOException {
		try {
			initTime = System.currentTimeMillis();
			try {
				final String[] txtFiles = new File(INPUT_FOLDER).list((File dir, String name) -> name.endsWith(".in"));
				final Optional<String> selectedInput = Arrays.stream(txtFiles).max((String s1, String s2) 
						-> Integer.compare(FILE_PRIORITY.applyAsInt(s1),
										   FILE_PRIORITY.applyAsInt(s2)));
				if (selectedInput.isPresent())
					inputFileName = selectedInput.get();
			} catch (SecurityException ex) {
				// Can't get property. It seems that solution is running in secure
				// environment
				ex.printStackTrace();
			}
			outputFileName = inputFileName.replaceFirst("\\." + INPUT_EXTENSION + "$", "." + OUTPUT_EXTENSION);
			if (STACK_SIZE < 0L) {
				INSTANCE.run();
			} else {
				new Thread(null, INSTANCE, "Solver", 1L << 24).start();
			}
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(999);
		}
	}

	@Override
	public void run() {
		try {
			System.err.println("Set '" + inputFileName + "' as an input file");
			System.err.println("Set '" + outputFileName + "' as an output file");
			in = new BufferedReader(new InputStreamReader(new FileInputStream(INPUT_FOLDER + File.separator + inputFileName)));
			out = new PrintWriter(OUTPUT_FOLDER + File.separator + outputFileName);
			solve();
			out.close();
			in.close();
			writeLog("Total time: "
					+ (System.currentTimeMillis() - initTime) + " ms");
			writeLog("Memory status: " + memoryStatus());
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(999);
		}
	}
	
	/**************************************************************************
	 * Input 
	 *************************************************************************/
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st = new StringTokenizer("");
	
	String nextToken() throws IOException {
		while (!st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	
	int[] nextIntArray(int size) throws IOException {
		int[] ret = new int [size];
		for (int i = 0; i < size; i++)
			ret[i] = nextInt();
		return ret;
	}
	
	long[] nextLongArray(int size) throws IOException {
		long[] ret = new long [size];
		for (int i = 0; i < size; i++)
			ret[i] = nextLong();
		return ret;
	}
	
	double[] nextDoubleArray(int size) throws IOException {
		double[] ret = new double [size];
		for (int i = 0; i < size; i++)
			ret[i] = nextDouble();
		return ret;
	}
	
	String nextLine() throws IOException {
		st = new StringTokenizer("");
		return in.readLine();
	}
	
	boolean isEof() throws IOException {
		while (!st.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null)
				return true;
			st = new StringTokenizer(s);
		}
		return false;
	}
	
	/************************************************************************** 
	 * Output 
	 *************************************************************************/
	void printRepeat(String s, int count) {
		for (int i = 0; i < count; i++)
			out.print(s);
	}
	
	void printArray(int[] array) {
		if (array == null || array.length == 0)
			return;
		for (int i = 0; i < array.length; i++) {
			if (i > 0) out.print(' ');
			out.print(array[i]);
		}
		out.println();
	}
	
	void printArray(long[] array) {
		if (array == null || array.length == 0)
			return;
		for (int i = 0; i < array.length; i++) {
			if (i > 0) out.print(' ');
			out.print(array[i]);
		}
		out.println();
	}
	
	void printArray(double[] array) {
		if (array == null || array.length == 0)
			return;
		for (int i = 0; i < array.length; i++) {
			if (i > 0) out.print(' ');
			out.print(array[i]);
		}
		out.println();
	}
	
	void printArray(double[] array, String spec) {
		if (array == null || array.length == 0)
			return;
		for (int i = 0; i < array.length; i++) {
			if (i > 0) out.print(' ');
			out.printf(Locale.US, spec, array[i]);
		}
		out.println();
	}
	
	void printArray(Object[] array) {
		if (array == null || array.length == 0)
			return;
		boolean blank = false;
		for (Object x : array) {
			if (blank) out.print(' '); else blank = true;
			out.print(x);
		}
		out.println();
	}
	
	@SuppressWarnings("rawtypes")
	void printCollection(Collection collection) {
		if (collection == null || collection.isEmpty())
			return;
		boolean blank = false;
		for (Object x : collection) {
			if (blank) out.print(' '); else blank = true;
			out.print(x);
		}
		out.println();
	}
	
	/**************************************************************************
	 * Utility
	 *************************************************************************/
	
	static String memoryStatus() {
		return (Runtime.getRuntime().totalMemory()
				- Runtime.getRuntime().freeMemory() >> 20)
				+ "/" + (Runtime.getRuntime().totalMemory() >> 20) + " MB";
	}
	
	static void checkMemory() {
		System.err.println(memoryStatus());
	}
	
	static long prevTimeStamp = Long.MIN_VALUE;
	
	static void updateTimer() {
		prevTimeStamp = System.currentTimeMillis();
	}
	
	static long elapsedTime() {
		return (System.currentTimeMillis() - prevTimeStamp);
	}
	
	static void checkTimer() {
		System.err.println(elapsedTime() + " ms");
	}
	
	static void chk(boolean f) {
		if (!f) throw new RuntimeException("Assert failed");
	}
	
	static void chk(boolean f, String format, Object ... args) {
		if (!f) throw new RuntimeException(String.format(format, args));
	}
	
	static void writeLog(String format, Object... args) {
		if (WRITE_LOG)
			System.err.println(String.format(Locale.US, format, args));
	}
	
	static void swap(int[] a, int i, int j) {
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	
	static void swap(long[] a, int i, int j) {
		long tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	
	static void swap(double[] a, int i, int j) {
		double tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	
	static void shuffle(int[] a, int from, int to) {
		for (int i = from; i < to; i++)
			swap(a, i, random.nextInt(a.length));
	}
	
	static void shuffle(long[] a, int from, int to) {
		for (int i = from; i < to; i++)
			swap(a, i, random.nextInt(a.length));
	}
	
	static void shuffle(double[] a, int from, int to) {
		for (int i = from; i < to; i++)
			swap(a, i, random.nextInt(a.length));
	}
	
	static void shuffle(int[] a) {
		if (a == null) return;
		shuffle(a, 0, a.length);
	}
	
	static void shuffle(long[] a) {
		if (a == null) return;
		shuffle(a, 0, a.length);
	}
	
	static void shuffle(double[] a) {
		if (a == null) return;
		shuffle(a, 0, a.length);
	}
	
	static long[] getPartialSums(int[] a) {
		final long[] sums = new long [a.length + 1];
		for (int i = 0; i < a.length; i++)
			sums[i + 1] = sums[i] + a[i];
		return sums;
	}
	
	static long[] getPartialSums(long[] a) {
		final long[] sums = new long [a.length + 1];
		for (int i = 0; i < a.length; i++)
			sums[i + 1] = sums[i] + a[i];
		return sums;
	}
	
	static int[] getOrderedSet(int[] a) {
		final int[] set = Arrays.copyOf(a, a.length);
		if (a.length == 0) return set;
		shuffle(set);
		sort(set);
		int k = 1;
		int prev = set[0];
		for (int i = 1; i < a.length; i++) {
			if (prev != set[i]) {
				set[k++] = prev = set[i];
			}
		}
		return Arrays.copyOf(set, k);
	}
	
	static long[] getOrderedSet(long[] a) {
		final long[] set = Arrays.copyOf(a, a.length);
		if (a.length == 0) return set;
		shuffle(set);
		sort(set);
		int k = 1;
		long prev = set[0];
		for (int i = 1; i < a.length; i++) {
			if (prev != set[i]) {
				set[k++] = prev = set[i];
			}
		}
		return Arrays.copyOf(set, k);
	}
	
	static int gcd(int x, int y) {
		x = abs(x);
		y = abs(y);
		while (x > 0 && y > 0) {
			if (x > y) {
				x %= y;
			} else {
				y %= x;
			}
		}
		return x + y;
	}
	
	static long gcd(long x, long y) {
		x = abs(x);
		y = abs(y);
		while (x > 0 && y > 0) {
			if (x > y) {
				x %= y;
			} else {
				y %= x;
			}
		}
		return x + y;
	}
	
}
