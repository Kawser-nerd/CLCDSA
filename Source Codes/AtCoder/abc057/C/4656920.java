import java.io.PrintStream;
import java.util.Scanner;
import java.util.stream.LongStream;

public class Main {

	static int F(long A, long B) {
		return Math.max(Long.toString(A).length(), Long.toString(B).length());
	}

	static void exec(Scanner in, PrintStream out) {
		long N = in.nextLong();
		int min = LongStream.rangeClosed(1, (long) Math.sqrt(N))
				.filter(A -> N % A == 0).mapToInt(A -> F(A, N / A)).min()
				.getAsInt();
		out.println(min);
	}

	public static void main(String[] args) {
		exec(new Scanner(System.in), System.out);
	}

}