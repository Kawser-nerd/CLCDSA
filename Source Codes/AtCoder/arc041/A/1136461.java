import java.util.Scanner;

public class Main {
	private static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int x = sc.nextInt();
		int y = sc.nextInt();
		int k = sc.nextInt();
		int sum = x+y;
		int ret = 0;
		if (y<k) {
			ret = sum-(k-y);
		} else {
			ret = x+k;
		}
		System.out.println(ret);
	}
}