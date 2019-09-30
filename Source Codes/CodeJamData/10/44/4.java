package round2;
import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Goats {

	static DecimalFormat DF = new DecimalFormat("0.000",new DecimalFormatSymbols(Locale.ENGLISH));
	static double EPSILON = 1E-9;
	
	
	public static void run() throws Exception {
		
		// TODO Insert input file
		init("D-small-attempt0");
		
		int cases = INT();
		for(int cc = 1;cc<=cases;cc++) {
			// TODO Read input for single case and solve
			int N = INT(), M = INT();
			double[][] centers = new double[N][2];
			for(int i = 0;i<N;i++) {
				centers[i][0] = DOUBLE();
				centers[i][1] = DOUBLE();
			}
			
			print("Case #"+cc+":");
			for(int pole = 0;pole<M;pole++) {
				int x = INT(), y = INT();
				
				double ra = distance(x,y,centers[0][0],centers[0][1]);
				double rb = distance(x,y,centers[1][0],centers[1][1]);
				double pdist = distance(centers[0][0],centers[0][1], centers[1][0], centers[1][1]);
				double area = 0.0;
				if(equals(centers[0][0],centers[1][0]) && equals(centers[0][1],centers[1][1])) {
					area = Math.PI*ra*ra;
				} else {
					
					double[][] intersections = circleCircleIntersection(centers[0], ra, centers[1], rb);
					if(intersections!=null) {
						double anga = angle(centers[0][0],centers[0][1], intersections[0][0],intersections[0][1],intersections[1][0],intersections[1][1]);
						double angb = angle(centers[1][0],centers[1][1], intersections[0][0],intersections[0][1],intersections[1][0],intersections[1][1]);
						
						if(java.awt.geom.Line2D.relativeCCW(intersections[0][0],intersections[0][1],intersections[1][0],intersections[1][1], centers[0][0], centers[0][1])
								==java.awt.geom.Line2D.relativeCCW(intersections[0][0],intersections[0][1],intersections[1][0],intersections[1][1], centers[1][0], centers[1][1]))
						{
							// On same side!
							
							double aa = Math.PI*ra*ra*anga/(2*Math.PI) - polygonArea(new double[][] {{centers[0][0],centers[0][1]},{intersections[0][0],intersections[0][1]},{intersections[1][0],intersections[1][1]}});
							double bb = Math.PI*rb*rb*angb/(2*Math.PI) - polygonArea(new double[][] {{centers[1][0],centers[1][1]},{intersections[0][0],intersections[0][1]},{intersections[1][0],intersections[1][1]}});
							
							area = Math.PI*Math.min(ra*ra,rb*rb) - Math.abs(aa-bb); 
							
						} else {
							area = Math.PI*ra*ra*anga/(2*Math.PI);
							area += Math.PI*rb*rb*angb/(2*Math.PI);
							
							area -= polygonArea(new double[][] {{centers[0][0],centers[0][1]},{intersections[0][0],intersections[0][1]},{intersections[1][0],intersections[1][1]}});
							area -= polygonArea(new double[][] {{centers[1][0],centers[1][1]},{intersections[0][0],intersections[0][1]},{intersections[1][0],intersections[1][1]}});
							
						}
						
						
					}
					
				}
				print(' ');
				print(area);
			}
			
			println();
		}
		
	}
	
	public static double distance(double x1, double y1, double x2, double y2) {
		double dx = x1-x2, dy = y1-y2;
		return Math.sqrt(dx*dx+dy*dy);
	}
	
	// Returns null if there is no intersection, or if there are infinite!!
	public static double[][] circleCircleIntersection(double[] c0, double r0, double[] c1, double r1) {
			
		double x0 = c0[0]-c1[0], y0 = c0[1]-c1[1];
		double d = x0*x0+y0*y0;
		double p = Math.sqrt(((r0+r1)*(r0+r1) - d) * (d - (r1-r0)*(r1-r0)));
		
		if(Math.abs(d)<EPSILON || Double.isNaN(p))return null;
		
		double x = x0 / 2.0 - x0*(r0*r0-r1*r1) / (2*d) + c1[0];
		double y = y0 / 2.0 - y0*(r0*r0-r1*r1) / (2*d) + c1[1];
			
		return new double[][] {	{x + y0*p / (2*d), y - x0*p / (2*d)},
								{x - y0*p / (2*d), y + x0*p / (2*d)} };
			
	}
	
	public static double angle(double xa, double ya, double xb, double yb, double xc, double yc) {
		
		double dx = xb-xa;
		double dy = yb-ya;
		double ang1 = Math.atan2(dy,dx);
		
		dx = xc-xa;
		dy = yc-ya;
		double ang2 = Math.atan2(dy,dx);
		
		double angdiff = Math.abs(ang1-ang2);
		
		return Math.min(angdiff, 2*Math.PI-angdiff);
		
	}
	
	public static double polygonArea(double[][] polygon) {

		double area = 0;
		int V = polygon.length;
		for (int i = 0; i < V; i++) {
			double[] p1 = polygon[i];
			double[] p2 = polygon[(i + 1) % V];
			area += (p1[0] * p2[1]) - (p1[1] * p2[0]);
		}
		return Math.abs(area) / 2.0;

	}
	
	// Sjekk for om to doubles er like:
	public static boolean equals(double a, double b) {
		if(Math.abs(a-b)<EPSILON)return true;
		double min = b-(b*EPSILON); double max = b+(b*EPSILON);
		if(min>max) { double temp = min; min = max; max = temp; }
		if(a>min && a<max)return true;
		return false;
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
