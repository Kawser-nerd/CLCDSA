import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] arr = new int[4];
		for (int i = 0; i < 4; i++) {
			int prev = 1;
			for (int j = 0; j < 4; j++) {
				int a = sc.nextInt();
				if (a == prev) {
					System.out.println("CONTINUE");
					return;
				}
				if (a == arr[j]) {
					System.out.println("CONTINUE");
					return;
				}
				prev = a;
				arr[j] = a;
			}
		}
		System.out.println("GAMEOVER");
	}
}