import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		for (int i = a; i <= b; i++) {
			if (i - a <= k - 1 || b - i <= k - 1) {
				System.out.println(i);
			}
		}
		sc.close();
	}

}