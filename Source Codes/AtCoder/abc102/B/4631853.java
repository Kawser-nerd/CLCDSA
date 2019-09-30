import java.io.PrintStream;
import java.util.IntSummaryStatistics;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

	static void exec(Scanner in, PrintStream out) {
		int N = in.nextInt();
		int[] A = new int[N];
		for (int i = 0; i < N; i += 1) {
			A[i] = in.nextInt();
		}
		IntSummaryStatistics s = IntStream.of(A).summaryStatistics();
		out.println(s.getMax() - s.getMin());
	}

	public static void main(String[] args) {
		exec(new Scanner(System.in), System.out);
	}

}