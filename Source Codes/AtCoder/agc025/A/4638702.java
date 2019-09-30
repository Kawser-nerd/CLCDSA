import java.io.PrintStream;
import java.util.Scanner;
import java.util.stream.Stream;

public class Main {

	static void exec(Scanner in, PrintStream out) {
		String N = in.next();
		if (N.length() == 1) {
			out.println(N);
			return;
		}
		if (N.substring(0, 2).equals("10")) {
			int sum = 10;
			if (N.length() > 2) {
				sum += Stream.of(N.substring(2).split(""))
						.mapToInt(Integer::valueOf).sum();
			}
			out.println(sum);
		} else {
			int sum = Stream.of(N.split("")).mapToInt(Integer::valueOf).sum();
			out.println(sum);
		}
	}

	public static void main(String[] args) {
		exec(new Scanner(System.in), System.out);
	}

}