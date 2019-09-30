import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;


public class ProblemB {
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		int T = in.nextInt();
		for (int cn = 1 ; cn <= T ; cn++) {
			double C = in.nextDouble();
			double F = in.nextDouble();
			double X = in.nextDouble();
			out.println(String.format("Case #%d: %.7f", cn, solve(C, F, X)));
		}
		out.flush();
	}
	
	private static double solve(double C, double F, double X) {
		double minTime = X / 2.0d;
		double time = 0.0d;
		double speed = 2.0d;
		for (int buy = 1 ; buy < 1000000 ; buy++) {
			time += C / speed;
			speed += F;
			double total = time + X / speed;
			minTime = Math.min(minTime, total);
		}
		return minTime;
	}

	public static void debug(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}
}
