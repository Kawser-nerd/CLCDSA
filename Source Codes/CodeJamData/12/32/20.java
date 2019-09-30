import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;



public class C1B {
	
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer input;
	
	
	public static void main(String[] args) throws IOException {
		//Initializing ...
	 	new C1B();
		//-------------------------------------------------------------------------
		int testCases = nextInt();
		int counter=0;
		while (testCases -- > 0){
			counter++;
			//Here put the code..:)
			double d = nextDouble();
			int n = nextInt();
			int a = nextInt();
			double [] ti = new double[n];
			double [] xi = new double[n];
			for (int i = 0; i < xi.length; i++) {
				ti[i]=nextDouble();
				xi[i]=nextDouble();
			}
			writeln("Case #"+counter+":");
			if(n!=1)
			for (int i = 0; i < a; i++) {
				double acc = nextDouble();
				double time = 0.0;
				double place = 0.0;
				double vnote = 0.0;
				for (int j = 1; j < xi.length; j++) {
					double A = 0.5*acc;
					double B = vnote;
					double C= xi[j]-place;
					double deltaTime = (-B+Math.sqrt(B*B+4*A*C))/(2*A);
					if((time+deltaTime)-ti[j]>0.00000001){//no hit
						if(xi[j]-d>0.00000001){
							A = 0.5*acc;
							B = vnote;
							C= d-place;
							deltaTime = (-B+Math.sqrt(B*B+4*A*C))/(2*A);
							writeln((time+deltaTime));
							break;
						}else if(Math.abs(xi[j]-d)<0.00000001){
							writeln((time+deltaTime));
							break;
						}else{
							continue;
						}
					}else{//hit
						if(xi[j]-d>0.00000001){
							double vol = (xi[j]-xi[j-1])/(ti[j]-ti[j-1]);
							A = 0.5*acc;
							B = vnote;
							C= d-place;
							deltaTime = (-B+Math.sqrt(B*B+4*A*C))/(2*A);
							writeln(Math.max(deltaTime+time, (d-xi[j-1])/vol));
							break;
						}else if(Math.abs(xi[j]-d)<0.00000001){
							writeln(ti[j]);
							break;
						}else{
							vnote = (xi[j]-xi[j-1])/(ti[j]-ti[j-1]);
							place = xi[j];
							time = ti[j];
							continue;
						}
					}
				}
			}
			else{
				for (int i = 0; i < a; i++) {
					double acc = nextDouble();
					double time = 0.0;
					time = Math.sqrt((2*d)/acc);
					writeln(time);
					
				}
			}
			
			
		}
		//-------------------------------------------------------------------------
		//closing up
		end();
		//--------------------------------------------------------------------------

	}
	
	private static void writeln(double max) {
		// TODO Auto-generated method stub
//		out.write(output+"\n");
		out.printf("%.7f\n", max);
		out.flush();
	}

	public C1B() throws IOException {
		//Input Output for Console to be used for trying the test samples of the problem 
		in = new BufferedReader(new InputStreamReader(System.in));
//		out = new PrintWriter(System.out);
		//-------------------------------------------------------------------------
		//Input Output for File to be used for solving the small and large test files
//		in = new BufferedReader(new FileReader("C1B.in"));
		out = new PrintWriter("C1B.txt");
		//-------------------------------------------------------------------------
		//Initalize Stringtokenizer input
		input = new StringTokenizer(in.readLine());
	}

	private static int nextInt() throws IOException {
		if (!input.hasMoreTokens())input=new StringTokenizer(in.readLine());
		return Integer.parseInt(input.nextToken());
	}
	private static long nextLong() throws IOException {
		if (!input.hasMoreTokens())input=new StringTokenizer(in.readLine());
		return Long.parseLong(input.nextToken());
	}
	private static double nextDouble() throws IOException {
		if (!input.hasMoreTokens())input=new StringTokenizer(in.readLine());
		return Double.parseDouble(input.nextToken());
	}
	private static String nextString() throws IOException {
		if (!input.hasMoreTokens())input=new StringTokenizer(in.readLine());
		return input.nextToken();
	}
	private static void write(String output){
		out.write(output);
		out.flush();
	}
	private static void writeln(String output){
		out.write(output+"\n");
		out.flush();
	}
	private static void end() throws IOException{
		in.close();
		out.close();
		System.exit(0);
	}
	
}
