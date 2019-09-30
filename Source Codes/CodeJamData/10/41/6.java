package round2;
import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class ElegantDiamond {

	static DecimalFormat DF = new DecimalFormat("0.000",new DecimalFormatSymbols(Locale.ENGLISH));
	
	public static void run() throws Exception {
		
		init("A-large");
		
		int cases = INT();
		for(int cc = 1;cc<=cases;cc++) {
			int k = INT();
			char[][] diamond = new char[2*k-1][2*k-1];
			for(char[] d : diamond)Arrays.fill(d,'#');
			int start = k-1;
			for(int i = 0;i<k-1;i++) {
				for(int j = 0;j<=i;j++) {
					diamond[i][start+2*j] = TOKEN().charAt(0);
				}
				start--;
			}
			for(int j = 0;j<k;j++)diamond[k-1][2*j] = TOKEN().charAt(0);
			start = 1;
			for(int i = 0;i<k-1;i++) {
				for(int j = 0;j<=k-2-i;j++) {
					diamond[k+i][start+2*j] = TOKEN().charAt(0);
				}
				start++;
			}
//			System.out.println();
//			for(char[] d : diamond)System.out.println(Arrays.toString(d));
//			System.err.println();
			
			int best = Integer.MAX_VALUE / 2;
			for(int ci = 0;ci<diamond.length;ci++) {
				for(int cj = 0;cj<diamond[ci].length;cj++) {
					boolean ok = true;
					for(int x = 0;x<diamond.length;x++) {
						for(int y = 0;y<diamond.length;y++) {
							
							// Horizontal Reflect
							int xx = 2 * ci - x;
							if(xx>=0 && xx<diamond.length && diamond[x][y]!=diamond[xx][y]) {
								if(diamond[x][y]!='#' && diamond[xx][y]!='#')ok = false;
//								if(ci==2 && cj==3)System.out.println("!H");
							}
								
							
							// Vertical Reflect
							int yy = 2 * cj - y;
							if(yy>=0 && yy<diamond[x].length && diamond[x][y]!=diamond[x][yy]) {
								if(diamond[x][y]!='#' && diamond[x][yy]!='#')ok = false;
//								if(ci==2 && cj==3)System.out.println("!V");
							}
								
							
//							if(ci==2 && cj==3) {
//								System.out.println(x+" "+y+" "+xx+" "+yy);
//							}
						}
					}
					if(ok) {
						// Update best!!
						
						int dx = Math.abs(ci-(k-1));
						int dy = Math.abs(cj-(k-1));
						
						int newk = k+dx+dy;
//						System.out.println("("+ci+","+cj+") --> "+dx+" "+dy);
						
						best = Math.min(best, newk*newk-k*k);
						
					}
				}
			}
			
			println("Case #"+cc+": "+best);
			// TODO Print output
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
