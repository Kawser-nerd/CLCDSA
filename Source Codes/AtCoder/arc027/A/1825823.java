import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int m = sc.nextInt();
		int ans = 18 * 60 - 60 * h - m;
		System.out.println(ans);
	}
}