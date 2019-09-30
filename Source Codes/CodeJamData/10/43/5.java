package round2;
import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Bacteria {

	static DecimalFormat DF = new DecimalFormat("0.000",new DecimalFormatSymbols(Locale.ENGLISH));
	
	public static void run() throws Exception {
		
		init("C-small-attempt0");
		
		int cases = INT();
		for(int cc = 1;cc<=cases;cc++) {
			int R = INT();
			boolean[][] map = new boolean[100][100];
			for(int i = 0;i<R;i++) {
				int x1 = INT(), y1 = INT();
				int x2 = INT(), y2 = INT();
				for(int x = x1-1;x<=x2-1;x++) {
					for(int y = y1-1;y<=y2-1;y++) {
						map[x][y] = true;
					}
				}
			}
			
			int iterations = 0;
			boolean done = false;
			while(!done) {
				iterations++;
				done = true;
				boolean[][] nmap = new boolean[100][100];
				for(int i = 0;i<100;i++) {
					for(int j = 0;j<100;j++) {
						if(i==0 && j==0) { nmap[i][j] = false;	}
						else if(i==0) {if(map[i][j] && map[i][j-1])nmap[i][j] = true; }
						else if(j==0) {if(map[i][j] && map[i-1][j])nmap[i][j] = true; }
						else {
							if(map[i][j])nmap[i][j] = map[i-1][j] || map[i][j-1];
							else nmap[i][j] = map[i-1][j] && map[i][j-1];
						}
						if(nmap[i][j])done = false;
					}
				}
				map = nmap;
			}
			
			println("Case #"+cc+": "+iterations);
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
