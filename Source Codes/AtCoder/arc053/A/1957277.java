import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		long h = sc.nextLong();
		long w = sc.nextLong();
		long ans = 0L;
		ans += (w-1)*h;
		ans += (h-1)*w;
		System.out.println(ans);
	}
}