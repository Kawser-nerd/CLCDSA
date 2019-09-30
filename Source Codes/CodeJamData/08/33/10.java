import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Summator {
	long a[];
	int N;
	
	Summator(int N) {
		this.N = N;
		a = new long[N+1]; 
	}
	
	int prev(int x) {
		return x&(x-1);
	}
	int next(int x){
		return 2*x - prev(x);
	}
	long findSum(int l, int r) {
		if (l>1) {
			return (findSum(1,r)-findSum(1, l-1)) % TaskC2.MOD;
		}
		if (r>0) {
			return (findSum(1, prev(r)) + a[r]) % TaskC2.MOD; 
		} else {
			return 0;
		}
	}
	void modify(int p, long v) {
		int x=p;
		while (x<=N) {
			a[x] = (a[x] + v) % TaskC2.MOD;
			x=next(x);
		}
	}
}


public class TaskC2 {
	private static final String TEST_NAME = "C-large";
	private static final String INPUT_FILE = TEST_NAME + ".in";
	private static final String OUTPUT_FILE = TEST_NAME + ".out";
	
	public static final int MOD = 1000000007;
	
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
	
	private static void solveTestCase(int testCaseID ) {
		int n = in.nextInt(), m = in.nextInt();
		long X = in.nextLong(), Y = in.nextLong(), Z = in.nextLong();
		long[] am = new long[m], an = new long[n];
		
		for (int i=0; i<m; ++i) {
			am[i] = in.nextLong();
		}
		
		for (int i=0; i<n; ++i) {
			an[i] = am[i%m];
			am[i % m] = (X*am[i%m] + Y*(i+1)) % Z;
		}
		
		long an_s[] = Arrays.copyOf(an, an.length); 
		Arrays.sort(an_s);
		
		int[] positions = new int[an_s.length];
		positions[0] = 1;
		for (int i=1; i<an_s.length; ++i) {
			if (an_s[i] > an_s[i-1])
				positions[i] = positions[i-1] + 1;
			else
				positions[i] = positions[i-1];
		}
		Map<Integer, Integer> val2pos = new HashMap<Integer, Integer>();
		for (int i=0; i<an_s.length; ++i) {
			val2pos.put((int)an_s[i], positions[i]);
		}
		
		Summator sum = new Summator(positions[n-1]);
		
		for (int i=0; i<n; ++i) {
			int val = (int)an[i];
			int pos = val2pos.get(val);
			long summa = sum.findSum(1, pos-1);
			sum.modify(pos, summa+1);
		}
		
		long result = sum.findSum(1, positions[n-1]);
		
		out.println(String.format("Case #%d: %d", testCaseID, result));
	}
}