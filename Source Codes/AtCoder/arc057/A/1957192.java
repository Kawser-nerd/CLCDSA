import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		long now = sc.nextLong();
		final long k = sc.nextLong();
		long count = 0L;
		if(k==0) {
			System.out.println(2_000_000_000_000L-now);
			return;
		}
		while(now < 2_000_000_000_000L) {
			now += 1 + now * k;
			count++;
		}
		System.out.println(count);
	}
}