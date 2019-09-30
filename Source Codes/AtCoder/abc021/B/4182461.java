import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt();
		int a = sc.nextInt(), b = sc.nextInt();
		int k = sc.nextInt();
		List<Integer> list = new ArrayList<>();
		String ans = "YES";
		for (int i = 0; i < k; i++) {
			int t = sc.nextInt();
			if (list.contains(t) || t == a || t == b) {
				ans = "NO";
			}
			list.add(t);
		}
		System.out.println(ans);
	}
}