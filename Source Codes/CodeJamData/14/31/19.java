import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class A {
	private static Scanner scan = new Scanner(System.in);
	public static void main(String[] args) throws FileNotFoundException {
		int cases = scan.nextInt();
		PrintStream outfile = new PrintStream("A-small.out.txt");

		String input;
		String result = "";
		for (int c = 1; c <= cases; c++) {
			input = scan.next();
			int index = input.indexOf('/');
			int res = test(Long.valueOf(input.substring(0,index)), Long.valueOf(input.substring(1+index)));
			result = "Case #" + c + ": " +
					(res >= 0 ? String.valueOf(res) : "impossible");
			
			outfile.println(result);
			System.out.println(result);
		}
		outfile.close();
	}
	
	private static int test(long num, long denom) {
		long factor = gcd(num, denom);
		num /= factor;
		denom /= factor;
		int max = 0;
		for (long test = denom; test > 1; test >>= 1) {
			if ((test & 1L) == 1)
				return -1;
			max++;
		}
		int min = 0;
		for (long test = num; test > 1; test >>= 1) {
			min++;
		}
		return max - min;
	}

	private static long gcd(long a, long b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}
}
