package round2;
import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class WorldCup {

	static DecimalFormat DF = new DecimalFormat("0.000",new DecimalFormatSymbols(Locale.ENGLISH));
	
	public static void run() throws Exception {
		
		init("B-large");
		
		int cases = INT();
		for(int cc = 1;cc<=cases;cc++) {
			int P = INT();
			int N = 1<<P;
			M = new int[N];
			for(int i = 0;i<N;i++)M[i] = INT();
			prices = new int[N][N];
			for(int[] p : prices)Arrays.fill(p, Integer.MAX_VALUE);
			for(int exp = P-1;exp>=0;exp--) {
				int amount = 1<<exp;
				int blocksize = 1<<(P-exp);
				for(int i = 0;i<amount;i++)
					prices[i*blocksize][i*blocksize+blocksize-1] = INT();
			}
			
			memo = new int[P+1][N][N];
			for(int[][] mm : memo)for(int[] m : mm)Arrays.fill(m, -1); 
			
			int best = solve(0,0,N-1);
			
			println("Case #"+cc+": "+best);
		}
		
	}
	
	static int[] M;
	static int[][] prices;
	static int[][][] memo;
	
	public static int solve(int missed, int start, int end) {
		if(memo[missed][start][end]>=0)return memo[missed][start][end];
		int best = Integer.MAX_VALUE;
		if(start==end) {
			if(missed<=M[start])best = 0;
		} else {
			int interval = end-start+1;
			// Try watching this game!
			int costa = solve(missed,start,start+interval/2-1);
			int costb = solve(missed,start+interval/2,end);
			if(costa<Integer.MAX_VALUE && costb<Integer.MAX_VALUE)
				best = Math.min(best,prices[start][end]+costa+costb);
			
			// Try not watching this game!
			costa = solve(missed+1,start,start+interval/2-1);
			costb = solve(missed+1,start+interval/2,end);
			if(costa<Integer.MAX_VALUE && costb<Integer.MAX_VALUE)
				best = Math.min(best,costa+costb);
			
		}
		
		
		memo[missed][start][end] = best;
		return best;
	
	}
	
	// *************************************************************************************
	// *********************************** FRAMEWORK ***************************************
	// *************************************************************************************
	
	public static BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
	public static boolean isStandardInput = false;
	
	public static File input;
	public static FileReader inputreader;
	public static BufferedReader in;
	
	public static File output;
	public static FileWriter outputwriter;
	public static BufferedWriter out;
	
	public static StringTokenizer st;
	
	public static void main(String[] args) throws Exception {
		doSTDIN(true);
		setOutput("test.out");
		run();
		close();
	}
	
	public static void init(String problemName) throws Exception {
		doSTDIN(false);
		setInput(problemName+".in");
		setOutput(problemName+".out");
	}
	
	// **************** PRINT METHODS **********************
	
	public static void println() throws IOException {
		out.write("\n");
		System.out.println();
	}
	
	public static void println(Object obj) throws IOException {
		out.write(obj.toString());
		out.write("\n");
		System.out.println(obj.toString());
	}
	
	public static void print(Object obj) throws IOException {
		out.write(obj.toString());
		System.out.print(obj.toString());
	}
	
	public static void println(long number) throws IOException {
		out.write(Long.toString(number));
		out.write("\n");
		System.out.println(number);
	}
	
	public static void print(long number) throws IOException {
		out.write(Long.toString(number));
		System.out.print(number);
	}
	
	public static void println(char c) throws IOException {
		out.write(Character.toString(c));
		out.write("\n");
		System.out.println(c);
	}
	
	public static void print(char c) throws IOException {
		out.write(Character.toString(c));
		System.out.print(c);
	}
	
	public static void println(String line) throws IOException {
		out.write(line);
		out.write("\n");
		System.out.println(line);
	}
	
	public static void print(String line) throws IOException {
		out.write(line);
		System.out.print(line);
	}
	
	// ******************** INPUT DECLARATION ******************
	
	public static void doSTDIN(boolean standard) {
		isStandardInput = standard;
	}
	
	public static void setInput(String filename) throws IOException {
		input = new File(filename);
		inputreader = new FileReader(input);
		in = new BufferedReader(inputreader);
	}
	
	public static void setOutput(String filename) throws IOException {
		output = new File(filename);
		outputwriter = new FileWriter(output);
		out = new BufferedWriter(outputwriter);
	}
	
	public static void close() throws IOException {
		if(in!=null)in.close();
		if(inputreader!=null)inputreader.close();
		
		if(out!=null)out.flush();
		if(out!=null)out.close();
		if(outputwriter!=null)outputwriter.close();
	}
	
	// ************************** INPUT READING *****************
	
	static String LINE() throws IOException { return isStandardInput?stdin.readLine():in.readLine(); }
	static String TOKEN() throws IOException {
		while (st == null || !st.hasMoreTokens())st = new StringTokenizer(LINE());
		return st.nextToken();
	}
	static int INT() throws IOException {return Integer.parseInt(TOKEN());}
	static long LONG() throws IOException {return Long.parseLong(TOKEN());}
	static double DOUBLE() throws IOException {return Double.parseDouble(TOKEN());}
	static BigInteger BIGINT() throws IOException {return new BigInteger(TOKEN());}
	
}
