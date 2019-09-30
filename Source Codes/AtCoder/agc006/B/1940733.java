import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int x = sc.nextInt();
		int max = n*2-1;
		if(x==1 || x==2*n-1) {
			System.out.println("No");
		} else {
			System.out.println("Yes");
			final String sep = System.lineSeparator();
			String ans = IntStream.range(x+n-1, x+n+max-1)
					.mapToObj(e -> (e % max + 1) + sep)
					.collect(StringBuilder::new, StringBuilder::append, StringBuilder::append).toString();
			System.out.println(ans);
		}
	}
}