package round1a;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;

public class CollectingCards {

	final static String INPUT		= "test/round1a/C-large.in"; 
	final static String OUTPUT		= "test/round1a/C-large.out";
	
	final static int oo				= 100100100;
	
	int c, n;
	double result;
	double[][] d;
	long[][] th;
	
	void initFirst() {
		th = new long[41][41];
		th[0][0] = 1;
		th[1][0] = 1;
		th[1][1] = 1;
		for (int c=2; c<=40; c++) {
			th[c][0] = 1;
			for (int n=1; n<=c; n++) th[c][n] = th[c-1][n-1]+th[c-1][n];
		}
	}
	
	void initAll() {
		d = new double[2][c+1];
		for (int i=0; i<2; i++) Arrays.fill(d[i], 0);
		d[1][0] = 1;
		result = 0;
	}

	void process() {
		for (int i=1; i<=1000; i++) {
			for (int j=0; j<=c; j++) d[0][j] = d[1][j];
			Arrays.fill(d[1], 0);
			for (int j=n; j<=c; j++) {
				for (int k=j-n; k<=j; k++) {
					d[1][j] += d[0][k]*th[k][n-j+k]*th[c-k][j-k]/th[c][n];
				}
			}
//			System.out.println(i+": ");
//			for (int j=0; j<=c; j++) System.out.print(d[1][j]+" "); System.out.println();			
			double tmp = 0;
			for (int k=c-n; k<c; k++) {
				tmp += d[0][k]*th[k][n-c+k]/th[c][n];
			}
//			double sum = 0;
//			for (int j=0; j<=c; j++) sum+=d[1][j];
//			System.out.println("sum="+sum);
			result += i*tmp;
		}
		System.out.println("result = "+result);
	}
	
	void solveTestCase() {
		initAll();
		process();
	}
	
	void solveProblem() throws Exception {		
		BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(INPUT)));		
		PrintWriter out = new PrintWriter(OUTPUT);
		int t = Integer.parseInt(br.readLine());
		for (int i=0; i<t; i++) {
			int[] tmp = Utils.toInts(br.readLine());
			c = tmp[0]; n = tmp[1];
			solveTestCase();
			out.println("Case #"+(i+1)+": "+result);
		}
		out.close();
	}
	
	public CollectingCards() throws Exception {
		initFirst();
		solveProblem();
	}
	
	public static void main(String[] args) throws Exception {
		System.out.println("Starting...");
		new CollectingCards();
		System.out.println("Done!");
	}

}
