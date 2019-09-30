package R2;

import java.io.*;
import java.math.*;
import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;

import static java.util.Arrays.*;

public class A {
	// Setting
	static
	class Config {
		public static final boolean DISP_PROGRESS = true;
		public static final boolean DISP_ELASPED_TIME = true;
		public static final boolean STDIO = false;

		public static final String BASE_DIR = "data\\R2" ;
		public static final String IN_FILE = "A-large.in";
		public static final String OUT_FILE = IN_FILE + "_out.txt";
		public static final int MAX_THREAD = 3;
	}


	// main
	static
	class ParallelSolver implements Runnable {
		private static final int mod = (int)1e9+7;
		
		int n;
		int R, P, S;
		public void readInput(final IOFast io) throws IOException {
			n = io.nextInt();
			R = io.nextInt();
			P = io.nextInt();
			S = io.nextInt();
		}
		
		@Override
		public void run() {
			int[] x = new int[]{P,R,S,};
			for(int i = 0; i < 3; i++) {
				int[] y = rec(n, i, null).clone();
				if(Arrays.equals(x, y)) {
					List<Integer> xs = new ArrayList<>();
					rec(n, i, xs);
					for(int v : xs) {
						out.print("PRS".charAt(v));
					}
					out.println();
					return;
				}
			}
			out.println("IMPOSSIBLE");
		}
		
		boolean less(List<Integer> l, List<Integer> r) {
			for(int i = 0; i < l.size(); i++) {
				if(l.get(i) != r.get(i)) {
					return l.get(i) < r.get(i);
				}
			}
			return false;
		}
		
		int[][][] memo = new int[1<<12+1][3][];
		int[] rec(int n, int a, List<Integer> xs) {
			if(memo[n][a] == null || xs != null) {
				memo[n][a] = new int[3];
				if(n == 0) {
					memo[n][a][a] = 1;
					if(xs != null) xs.add(a);
				} else {
					List<Integer> l = new ArrayList<>();
					List<Integer> r = new ArrayList<>();
					int[] x = rec(n - 1, (a + 1) % 3, l);
					int[] y = rec(n - 1, a, r);
					if(xs != null) {
						if(less(l, r)) { xs.addAll(l); xs.addAll(r); }
						else { xs.addAll(r); xs.addAll(l); }
					}
					for(int i = 0; i < 3; i++) {
						memo[n][a][i] = x[i] + y[i];
					}
				}
			}
			return memo[n][a];
		}
		private static final void swap(int[] xs, int i, int j) {
			final int t = xs[j];
			xs[j] = xs[i];
			xs[i] = t;
		}
		private static final boolean nextPermutation(final int[] xs) {
			for(int i = xs.length - 1; i > 0; i--) {
				if(xs[i - 1] > xs[i]) {
					continue;
				}

				for(int j = i, k = xs.length - 1; j < k; j++, k--) {
					swap(xs, j, k);
				}

				for(int j = i; j < xs.length; j++) if(xs[j] > xs[i - 1]) {
					swap(xs, j, i - 1);
					break;
				}

				return true;
			}
			return false;
		}

		// template
		void printList(int[] res) {
			for(int i = 0; i < res.length; i++) {
				out.print(res[i] + (i==res.length-1?"\n":" "));
			}
		}
		<T> void printList(List<T> res) {
			for(int i = 0; i < res.size(); i++) {
				out.print(res.get(i) + (i==res.size()-1?"\n":" "));
			}
		}
		
//		final Random random = new Random(0);
		final Random random = new Random(System.currentTimeMillis());
		final StringWriter sw = new StringWriter();
		final PrintWriter out = new PrintWriter(sw);
		
		@Override
		public String toString() {
			out.flush();
			return sw.toString();
		}
		
		public ParallelSolver init(final IOFast io) throws IOException {
			readInput(io);
			return this;
		}
	}


	//////////////////////////////////////////
	final IOFast io = new IOFast();
	
	
	public long elaspedTimeMilli;
	
	
	
	static class Par implements Runnable {
		private static AtomicInteger cur = new AtomicInteger(1);
		
		IOFast io;
		int T;
		int caseIndex;
		String[] answer;
		ParallelSolver ps;
		
		public Par(int T, String[] answer, IOFast io) {
			this.T = T;
			this.answer = answer;
			this.io = io;
		}
		
		public boolean init() throws IOException {
			synchronized (answer) {
				caseIndex = cur.getAndIncrement();
				if(caseIndex > T) return false;
				System.gc();
				ps = new ParallelSolver();
				ps.init(io);
				return true;
			}
		}
		
		public void debugProgress() {
			synchronized (answer) {
				if(Config.DISP_PROGRESS) {
					System.err.println("Case #" + caseIndex + ": DONE");
				}
			}
		}
		
		@Override
		public void run() {
			try {
				while(init()) {
					ps.run();
					answer[caseIndex - 1] = "Case #" + caseIndex + ": " + ps.toString();
					debugProgress();
				}
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	
	public void run() throws IOException, InterruptedException {
		if(!Config.STDIO) {
			io.setFileDir(Config.BASE_DIR);
			io.setFileIO(Config.IN_FILE, Config.OUT_FILE);
		}
		
		int T = io.nextInt();
//		IOFast.nextLine();
		Runnable[] inst = new Runnable[Config.MAX_THREAD];
		Thread[] thread = new Thread[Config.MAX_THREAD];
		String[] answer = new String[T];
		
		final long start = System.currentTimeMillis();
		for(int i = 0; i < Config.MAX_THREAD; i++) {
			inst[i] = new Par(T, answer, io);
//			thread[i] = new Thread(inst[i]);
			thread[i] = new Thread(null, inst[i], ""+(i+1), 1<<25);
			thread[i].start();
		}
		for(int i = 0; i < Config.MAX_THREAD; i++) {
			thread[i].join();
		}
		for(String s : answer) {
			io.out.print(s);
		}
		final long end = System.currentTimeMillis();
		elaspedTimeMilli = end - start;
		System.err.println(elaspedTimeMilli + " [ms]");
	}


	/// TEMPLATE
	static int gcd(int n, int r) { return r == 0 ? n : gcd(r, n%r); }
	static long gcd(long n, long r) { return r == 0 ? n : gcd(r, n%r); }
	
	static <T> void swap(T[] x, int i, int j) {
		T t = x[i];
		x[i] = x[j];
		x[j] = t;
	}
	
	static void swap(int[] x, int i, int j) {
		int t = x[i];
		x[i] = x[j];
		x[j] = t;
	}
	

	static void radixSort(int[] xs) {
		int[] cnt = new int[(1<<16)+1];
		int[] ys = new int[xs.length];
		
		for(int j = 0; j <= 16; j += 16) {
			Arrays.fill(cnt, 0);
			for(int x : xs) { cnt[(x>>j&0xFFFF)+1]++; }
			for(int i = 1; i < cnt.length; i++) { cnt[i] += cnt[i-1]; }
			for(int x : xs) { ys[cnt[x>>j&0xFFFF]++] = x; }
			{ final int[] t = xs; xs = ys; ys = t; }
		}
	}
	
	static void radixSort(long[] xs) {
		int[] cnt = new int[(1<<16)+1];
		long[] ys = new long[xs.length];
		
		for(int j = 0; j <= 48; j += 16) {
			Arrays.fill(cnt, 0);
			for(long x : xs) { cnt[(int)(x>>j&0xFFFF)+1]++; }
			for(int i = 1; i < cnt.length; i++) { cnt[i] += cnt[i-1]; }
			for(long x : xs) { ys[cnt[(int)(x>>j&0xFFFF)]++] = x; }
			{ final long[] t = xs; xs = ys; ys = t; }
		}
	}
	

	static void arrayIntSort(int[][] x, int... keys) {
		Arrays.sort(x, new ArrayIntsComparator(keys));
	}
	
	static class ArrayIntsComparator implements Comparator<int[]> {
		final int[] KEY;
		
		public ArrayIntsComparator(int... key) {
			KEY = key;
		}
		
		@Override
		public int compare(int[] o1, int[] o2) {
			for(int k : KEY) if(o1[k] != o2[k]) return o1[k] - o2[k];
			return 0;
		}
	}
	
	static class ArrayIntComparator implements Comparator<int[]> {
		final int KEY;
		
		public ArrayIntComparator(int key) {
			KEY = key;
		}
		
		@Override
		public int compare(int[] o1, int[] o2) {
			return o1[KEY] - o2[KEY];
		}
	}
	
	
	void main() throws IOException, InterruptedException {
		//		IOFast.setFileIO("rle-size.in", "rle-size.out");
		try {
			run();
		}
		catch (EndOfFileRuntimeException e) { }
		io.out.flush();
	}

	public static void main(String[] args) throws IOException, InterruptedException {
		new A().main();
	}
	
	static class EndOfFileRuntimeException extends RuntimeException {
		private static final long serialVersionUID = -8565341110209207657L; }

	static
	public class IOFast {
		private BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		private PrintWriter out = new PrintWriter(System.out);
		private String _dir;
		
		void setFileDir(String dir) {
			this._dir = dir;
		}

		void setFileIn(String ins) throws IOException {
			String pf = _dir == null ? "" : _dir + "\\";
			in = new BufferedReader(new FileReader(pf + ins));
		}

		void setFileOut(String outs) throws IOException {
			String pf = _dir == null ? "" : _dir + "\\";
			out = new PrintWriter(new FileWriter(pf + outs));
		}

		void setFileIO(String ins, String outs) throws IOException {
			out.flush();
			out.close();
			in.close();
//			in = new BufferedReader(new FileReader(ins));
//			out = new PrintWriter(new FileWriter(outs));
			setFileIn(ins);
			setFileOut(outs);
			System.err.println("reading from " + ins);
		}

		//		private static final int BUFFER_SIZE = 50 * 200000;
		private static int pos, readLen;
		private static final char[] buffer = new char[1024 * 8];
		private static char[] str = new char[500*8*2];
		private static boolean[] isDigit = new boolean[256];
		private static boolean[] isSpace = new boolean[256];
		private static boolean[] isLineSep = new boolean[256];

		static {
			for(int i = 0; i < 10; i++) { isDigit['0' + i] = true; }
			isDigit['-'] = true;
			isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true;
			isLineSep['\r'] = isLineSep['\n'] = true;
		}

		public int read() throws IOException {
			if(pos >= readLen) {
				pos = 0;
				readLen = in.read(buffer);
				if(readLen <= 0) { throw new EndOfFileRuntimeException(); }
			}
			return buffer[pos++];
		}

		public int nextInt() throws IOException {
			int len = 0;
			str[len++] = nextChar();
			len = reads(len, isSpace);
			
			int i = 0;
			int ret = 0;
			if(str[0] == '-') { i = 1; }
			for(; i < len; i++) ret = ret * 10 + str[i] - '0';
			if(str[0] == '-') { ret = -ret; }
			return ret;
//			return Integer.parseInt(nextString());
		}

		public long nextLong() throws IOException {
			int len = 0;
			str[len++] = nextChar();
			len = reads(len, isSpace);
			
			int i = 0;
			long ret = 0;
			if(str[0] == '-') { i = 1; }
			for(; i < len; i++) ret = ret * 10 + str[i] - '0';
			if(str[0] == '-') { ret = -ret; }
			return ret;
//			return Long.parseLong(nextString());
		}

		public char nextChar() throws IOException {
			while(true) {
				final int c = read();
				if(!isSpace[c]) { return (char)c; }
			}
		}
		
		int reads(int len, boolean[] accept) throws IOException {
			try {
				while(true) {
					final int c = read();
					if(accept[c]) { break; }
					
					if(str.length == len) {
						char[] rep = new char[str.length * 3 / 2];
						System.arraycopy(str, 0, rep, 0, str.length);
						str = rep;
					}
					
					str[len++] = (char)c;
				}
			}
			catch(EndOfFileRuntimeException e) { ; }
			
			return len;
		}
		
		int reads(char[] cs, int len, boolean[] accept) throws IOException {
			try {
				while(true) {
					final int c = read();
					if(accept[c]) { break; }
					cs[len++] = (char)c;
				}
			}
			catch(EndOfFileRuntimeException e) { ; }
			
			return len;
		}

		public char[] nextLine() throws IOException {
			int len = 0;
//			str[len++] = nextChar();
			str[len++] = (char)read();
			len = reads(len, isLineSep);
			
			try {
				if(str[len-1] == '\r') { len--; read(); }
			}
			catch(EndOfFileRuntimeException e) { ; }
			
			return Arrays.copyOf(str, len);
		}

		public String nextString() throws IOException {
			return new String(next());
		}

		public char[] next() throws IOException {
			int len = 0;
			str[len++] = nextChar();
			len = reads(len, isSpace);
			return Arrays.copyOf(str, len);
		}
		/*
		public int next(char[] cs) throws IOException {
			int len = 0;
			cs[len++] = nextChar();
			len = reads(cs, len, isSpace);
			return len;
		}
		*/
		public double nextDouble() throws IOException {
			return Double.parseDouble(nextString());
		}

		public long[] nextLongArray(final int n) throws IOException {
			final long[] res = new long[n];
			for(int i = 0; i < n; i++) {
				res[i] = nextLong();
			}
			return res;
		}

		public int[] nextIntArray(final int n) throws IOException {
			final int[] res = new int[n];
			for(int i = 0; i < n; i++) {
				res[i] = nextInt();
			}
			return res;
		}

		public int[][] nextIntArray2D(final int n, final int k) throws IOException {
			final int[][] res = new int[n][];
			for(int i = 0; i < n; i++) {
				res[i] = nextIntArray(k);
			}
			return res;
		}

		public int[][] nextIntArray2DWithIndex(final int n, final int k) throws IOException {
			final int[][] res = new int[n][k+1];
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < k; j++) {
					res[i][j] = nextInt();
				}
				res[i][k] = i;
			}
			return res;
		}

		public double[] nextDoubleArray(final int n) throws IOException {
			final double[] res = new double[n];
			for(int i = 0; i < n; i++) {
				res[i] = nextDouble();
			}
			return res;
		}

	}

}
