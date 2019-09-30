import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long x = Long.parseLong(sc.next());
		long count = x / 11 * 2;
		long sum = count / 2 * 11;
		if (sum < x) {
			sum += 6;
			count++;
			if (sum < x) {
				sum += 5;
				count++;
			}
		}
		System.out.println(count);
	}
}