import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

	static void exec(Scanner in, PrintStream out) {
		int N = in.nextInt();
		int[] a = new int[3 * N];
		for (int i = 0; i < 3 * N; i += 1) {
			a[i] = in.nextInt();
		}
		Arrays.sort(a);
		long sum = 0;
		for (int i = 0; i < N; i += 1) {
			sum += a[a.length - 2 - 2 * i];
		}
		out.println(sum);
	}

	public static void main(String[] args) {
		exec(new Scanner(System.in), System.out);
	}

}