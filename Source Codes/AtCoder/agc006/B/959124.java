import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int x = scanner.nextInt();
		
		print(x, n);
	}
	
	public static void print(int x,int n){
		int max =  n * 2 - 1;
		if (x == 1 || x == max) {
			System.out.println("No");
			return;
		}
		System.out.println("Yes");
		String sep = System.lineSeparator();
		String ans = IntStream.range(x + n - 1, x + n + max -1)
				.mapToObj(e -> (e % max + 1) + sep)
				.collect(StringBuilder::new, StringBuilder::append, StringBuilder::append).toString();
		System.out.println(ans);
	}
}