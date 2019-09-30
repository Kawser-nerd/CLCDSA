package round3;
import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class A {

	static DecimalFormat DF = new DecimalFormat("0.000",new DecimalFormatSymbols(Locale.ENGLISH));
	
	public static void run() throws Exception {
		
		boolean[] prime = sieve(1000000);
		int[] maxplist = new int[] {0,10,100,1000,10000,100000,1000000};
		
		// TODO Insert input file
		init("A-small-attempt0");
		
		int cases = INT();
		for(int cc = 1;cc<=cases;cc++) {
			int D = INT(), K = INT();
			int maxp = maxplist[D];
			int[] s = new int[K];
			int highnum = 0;
			for(int i = 0;i<K;i++) {
				s[i] = INT();
				highnum = Math.max(highnum,s[i]);
			}
			int answer = -1;
			boolean ok = false;
			if(K>1) {
out:			for(int p = highnum+1;p<=maxp;p++) {
					if(!prime[p])continue;
					for(int a = 0;a<p;a++) {
						int s1 = (s[0]*a)%p;
						int b = (s[1]+p-s1)%p;
						
						boolean isok = true;
						for(int i = 1;i<s.length;i++) {
							if(s[i]!=(s[i-1]*a+b)%p)isok = false;
						}
						
						if(isok) {
							int num = (s[s.length-1]*a+b)%p;
							if(answer==-1) {
								answer = num;
								ok = true;
							} else {
								if(answer!=num) {
									ok = false;
									break out;
								}
							}
						}
					}
				}
			}
			print("Case #"+cc+": ");
			// TODO Print output
			if(ok)println(answer);
			else println("I don't know.");
		}
		
	}
	
	// Samme som over, men regner ut for alle tall fra 0 til n, og legger dette
	// i en boolsk tabell.
	public static boolean[] sieve(int n) {
		boolean[] prime = new boolean[n + 1];
		Arrays.fill(prime, true);
		prime[0] = false;
		prime[1] = false;
		
		for(int i = 4;i<=n;i+=2)prime[i] = false;
		
		int m = (int) Math.sqrt(n);
		
		for (int i = 3; i <= m; i += 2)
			if (prime[i])
				for (int k = i * i; k <= n; k += i)
					prime[k] = false;

		return prime;
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
