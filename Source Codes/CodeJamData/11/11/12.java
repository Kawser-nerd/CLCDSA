import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;


public class Round1AA {
	
	public static String problemName = "A";
	public static String inputName = "large";
	
	static long denoms[] = new long[101];
	
	static long gcd(long a, long b) {
		while (true) {
			if (a == 0)
				return b;
			b %= a;
			if (b == 0)
				return a;
			a %= b;
		}
	}
	
	public static String handleCase() {
		long n = in.nextLong();
		long pd = in.nextLong();
		long pg = in.nextLong();
		
		System.out.println("" + pd + " denom: " + denoms[(int)pd]);
		if (denoms[(int)pd] > n) {
			//System.out.println("err1");
			return "Broken";
		}
		/*
		long den_d = denoms[(int)pd];
		long num_d = pd / (100L / den_d);
		
		long den_g = denoms[(int)pg];
		long num_g = pg / (100L / den_g);
		
		long den_r = den_d * den_g;
		long num_r = num_d * den_g - num_g * den_d;
		
		if (num_r < 0 || num_r > den_r)
			return "Broken";
		
		num_d *= den_g;
		num_g *= den_d;
		
		if (num_d == 0 && num_g == 0) {
			if (num_r == 0)
				return "Possible";
			else
				return "Broken";
		}
		
		if (num_r % gcd(num_d, num_g) != 0)
			return "Broken";
		*/
		
		if (pg == 0 && pd != 0)
			return "Broken";
		if (pg == 100 && pd != 100)
			return "Broken";
		
		return "Possible";
	}
	
	
	public static int[] readIntArr() {
		int n = in.nextInt();
		int[] res = new int[n];
		for (int i = 0; i < n; i++)
			res[i] = in.nextInt();
		return res;
	}
	
	public static interface Parser<T> {
		public T next();
	}
	
	public static <T> ArrayList<T> readList (Parser<T> p) {
		int n = in.nextInt();
		ArrayList<T> res = new ArrayList<T>();
		for (int i = 0; i < n; i++)
			res.add(p.next());
		return res;
	}
	
	public static Parser<Integer> intParser = new Parser<Integer>(){
		public Integer next() { return in.nextInt(); }};
	
	public static void main(String[] args) throws FileNotFoundException {
		for (int i = 0; i < 101; i++) {
			denoms[i] = 100L/gcd(i, 100L);
			System.out.println("Denoms[" + i + "] is " + denoms[i]);
		}
		
		
		String inFilename = problemName + "-" + inputName + ".in";
		String outFilename = problemName + "-" + inputName + ".out";
		System.out.println("Reading from " + inFilename);
		System.out.println("Writing to " + outFilename);
		in = new Scanner(new File(inFilename));
		out = new PrintStream(new File(outFilename));
		
		int ncases = in.nextInt();
		
		for (int i = 0; i < ncases; i++) {
			System.out.println("Running case " + (i+1) + "...");
			out.println("Case #" + (i+1) + ": " +
					handleCase()
					)
					;
		}
		System.out.println("Done!");
	}
	
	static Scanner in;
	static PrintStream out;	
}
