import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] st = sc.nextLine().split(" ");
		sc.close();
		int n = Integer.parseInt(st[0]);
		int m = Integer.parseInt(st[1]);
		n = n >= 12 ? n - 12 : n ;
		double shortHand = (n * 30) + (m * 0.5);
		double longHand = m * 6;
		double ans = Math.abs(shortHand - longHand);
		ans = ans > 180 ? Math.abs(360 - ans) : ans;
		System.out.println(Math.round(ans*1000.0)/1000.0);
	}
}