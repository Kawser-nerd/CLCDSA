import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		int min = Math.min(5, n);
		int ans = min * b + (n - min) * a;
		System.out.println(ans);
	}
}