import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		long[] arr = new long[3];
		for (int i = 0; i < 3; i++) {
			arr[i] = sc.nextInt();
			if (arr[i] % 2 == 0) {
				System.out.println(0);
				return;
			}
		}
		Arrays.sort(arr);
		System.out.println(arr[0] * arr[1]);
	}
}