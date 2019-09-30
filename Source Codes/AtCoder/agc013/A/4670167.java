import java.io.PrintStream;
import java.util.Scanner;

public class Main {

	static void exec(Scanner in, PrintStream out) {
		int N = in.nextInt();
		int[] A = new int[N];
		for (int i = 0; i < N; i += 1) {
			A[i] = in.nextInt();
		}
		int currentSignum = 0;
		int count = 1;
		for (int i = 0; i < N - 1; i += 1) {
			int signum = Integer.signum(A[i] - A[i + 1]);
			if (currentSignum == 0) {
				currentSignum = signum;
			} else if (!(signum == 0 || currentSignum == signum)) {
				count += 1;
				currentSignum = 0;
			}
		}
		out.println(count);
	}

	public static void main(String[] args) {
		exec(new Scanner(System.in), System.out);
	}

}