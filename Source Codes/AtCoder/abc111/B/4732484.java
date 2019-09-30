import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		System.out.println(ans(n));
	}

	public static int ans(int n) {
		if (n < 112) {
			return 111;
		} else if (n < 223) {
			return 222;
		} else if (n < 334) {
			return 333;
		} else if (n < 445) {
			return 444;
		} else if (n < 556) {
			return 555;
		} else if (n < 667) {
			return 666;
		} else if (n < 778) {
			return 777;
		} else if (n < 889) {
			return 888;
		} else {
			return 999;
		}
	}
}