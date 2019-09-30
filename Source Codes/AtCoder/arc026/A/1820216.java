import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		int ans = 0;
		if(n >= 5) {
			ans = 5 * b + (n - 5) * a;
		} else {
			ans = n * b;
		}
		System.out.println(ans);
	}
}