import java.io.PrintStream;
import java.util.Scanner;

public class Main {

	static void exec(Scanner in, PrintStream out) {
		int[][] c = new int[3][3];
		for (int i = 0; i < 3; i += 1) {
			for (int j = 0; j < 3; j += 1) {
				c[i][j] = in.nextInt();
			}
		}
		for (int i = 0; i <= 100; i += 1) {
			int a1 = i;
			int b1 = c[0][0] - a1;
			int b2 = c[0][1] - a1;
			int b3 = c[0][2] - a1;
			int a2 = c[1][0] - b1;
			if (a2 + b2 != c[1][1] || a2 + b3 != c[1][2]) {
				continue;
			}
			int a3 = c[2][0] - b1;
			if (a3 + b2 != c[2][1] || a3 + b3 != c[2][2]) {
				continue;
			}
			out.println("Yes");
			return;
		}
		out.println("No");
	}

	public static void main(String[] args) {
		exec(new Scanner(System.in), System.out);
	}

}