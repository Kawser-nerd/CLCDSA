package qualification;
import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class ThemePark {

	static DecimalFormat DF = new DecimalFormat("0.000",new DecimalFormatSymbols(Locale.ENGLISH));
	
	public static void run() throws Exception {
		
		init("C-large");
		
		int cases = INT();
		for(int cc = 1;cc<=cases;cc++) {
			long R = INT(), k = INT();
			int N = INT();
			long[] groups = new long[(int)N];
			for(int i = 0;i<N;i++)groups[i] = LONG();
			
			int[] next = new int[N];
			long[] count = new long[N];
			
			for(int i = 0;i<N;i++) {
				long cnt = groups[i];
				int at = (i+1)%N;
				while(at!=i && cnt+groups[at]<=k) {
					cnt += groups[at];
					at = (at+1)%N;
				}
				count[i] = cnt;
				next[i] = at;
			}
			
			HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
			int front = 0, time = 0;
			long sum = 0;
			while(!map.containsKey(front)) {
				if(time==R)break;
				map.put(front,time);
				sum += count[front];
				front = next[front];
				time++;
			}
			long cyclesum = count[front];
			int cyclelength = 1;
			int at = next[front];
			while(at!=front) {
				cyclelength++;
				cyclesum += count[at];
				at = next[at];
			}
			long morecycles = (R-time)/cyclelength;
			sum += cyclesum*morecycles;
			time += morecycles*cyclelength;
			while(time<R) {
				sum += count[front];
				front = next[front];
				time++;
			}
			print("Case #"+cc+": ");
			println(sum);
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
