package round3;
import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class B {

	static DecimalFormat DF = new DecimalFormat("0.000",new DecimalFormatSymbols(Locale.ENGLISH));
	
	public static void run() throws Exception {
		
		// TODO Insert input file
		init("B-small-attempt0");
		
		int cases = INT();
		for(int cc = 1;cc<=cases;cc++) {
			// TODO Read input for single case and solve
			long L = LONG();
			int N = INT();
			int[] B = new int[N];
			for(int i = 0;i<N;i++)B[i] = INT();
			Arrays.sort(B);
			int max = B[N-1];
			
			int[] dp = new int[10001];
			long best = Long.MAX_VALUE;
			for(int i = 1;i<dp.length;i++) {
				dp[i] = Integer.MAX_VALUE / 2;
				for(int b : B) {
					if(b<=i && dp[i-b]<Integer.MAX_VALUE/2)
						dp[i] = Math.min(dp[i],1+dp[i-b]);
				}
				if((L-i)%max==0 && dp[i]<Integer.MAX_VALUE/2) {
					best = Math.min((L-i)/max+dp[i],best);
				}
			}
			
			print("Case #"+cc+": ");
			// TODO Print output
			if(best==Long.MAX_VALUE)
				println("IMPOSSIBLE");
			else
				println(best);
			
		}
		
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
