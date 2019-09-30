import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemA {
	public static void main(String[] args) throws Exception {
		new ProblemA();
	}

	public ProblemA() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("input-a-large.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
		"output-A-large.txt")));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int n = scan.nextInt();
			long A = scan.nextInt();
			long B = scan.nextInt();
			long C = scan.nextInt();
			long D = scan.nextInt();
			long[] x = new long[n];
			long[] y = new long[n];
			x[0] = scan.nextInt();
			y[0] = scan.nextInt();
			int M = scan.nextInt();
			for ( int i = 1; i < n; i++) {
				x[i] = (A * x[i-1] + B	) % M;
				y[i] = (C*y[i-1] + D) % M;
			}
			long[] totals = new long[9];
			for (int i = 0; i < n; i++) {
				totals[3*(int)(x[i]%3) + (int)(y[i]%3)]++;
			}
			long count = 0;
			for ( int i = 0; i < 9; i++)
				for ( int j = i; j < 9; j++)
					for ( int k = j; k < 9; k++) {
						if ( (i/3 + j/3 + k /3 ) % 3 == 0 && ( i%3 + j%3 + k %3) % 3 == 0 ) {
							long z = totals[i];
							if ( j == i) {
								z *= totals[i]-1;
								if ( k == j) {
									z *= totals[i]-2;
									z /= 6;
								} else {
									z*= totals[k];
									z /= 2;
								}
							} else {
								z *= totals[j];
								if ( k == j ) {
									z *= totals[j]-1;
									z /= 2;
								}
								else z*= totals[k];
							}
							count += z;
						}
					}
			String answer = String.format("Case #%d: %d\n", test + 1, count);
			System.out.print(answer);
			out.print(answer);
		}
		out.close();
	}
}
