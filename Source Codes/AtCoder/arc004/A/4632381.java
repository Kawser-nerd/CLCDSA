import java.io.PrintStream;
import java.util.Scanner;

public class Main {

	static void exec(Scanner in, PrintStream out) {
		int N = in.nextInt();
		int[] x = new int[N];
		int[] y = new int[N];
		for (int i = 0; i < N; i += 1) {
			x[i] = in.nextInt();
			y[i] = in.nextInt();
		}
		double max = 0.0;
		for (int i = 0; i < N; i += 1) {
			for (int j = i + 1; j < N; j += 1) {
				int dx = x[i] - x[j];
				int dy = y[i] - y[j];
				double len = Math.sqrt(dx * dx + dy * dy);
				if (max < len) {
					max = len;
				}
			}
		}
		out.printf("%.6f%n", max);
	}

	public static void main(String[] args) {
		exec(new Scanner(System.in), System.out);
	}

}