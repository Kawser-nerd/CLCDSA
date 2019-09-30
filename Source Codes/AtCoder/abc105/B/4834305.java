import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// ?????
		int a = sc.nextInt();
		sc.close();
		boolean ans = false;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				if (i * 4 + j * 7 == a) {
					ans = true;
					break;
				}
			}
		}
		System.out.println(ans ? "Yes" : "No");
	}
}