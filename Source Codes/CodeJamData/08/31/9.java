import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class TaskA {
	private static final String TEST_NAME = "A-large";
	private static final String INPUT_FILE = TEST_NAME + ".in";
	private static final String OUTPUT_FILE = TEST_NAME + ".out";
	
	private static Scanner in;
	private static PrintWriter out;
		
	public static void main(String[] args) throws Exception {
		in = new Scanner(new File(INPUT_FILE));
		out = new PrintWriter(OUTPUT_FILE);
		
		int testCasesNum = in.nextInt();
		for (int i=0; i<testCasesNum; ++i) {
			solveTestCase(i+1);
		}
		in.close();
		out.close();
	}
	
	private static void reverse(int[] a) {
		int med = a.length / 2;
		int len = a.length;
		for (int i=0; i<med; ++i) {
			int t = a[i];
			a[i] = a[len-1-i];
			a[len-1-i] = t;
		}
	}
	
	private static void solveTestCase(int testCaseID ) {
		int P = in.nextInt();
		int K = in.nextInt();
		int L = in.nextInt();
		int[] freq = new int[L];		
		
		for (int i=0; i<L; ++i) {
			freq[i] = in.nextInt();
		}
		Arrays.sort(freq);
		reverse(freq);
		
		int[] keys = new int[K];
		int curKey = -1;
		long result = 0;
		
		for (int i=0; i<L; ++i) {
			// adding i-th letter
			curKey = (curKey + 1) % K;
			keys[curKey] += 1;
			result += keys[curKey]*freq[i];
		}
		
		out.println(String.format("Case #%d: %d", testCaseID, result));
	}
}