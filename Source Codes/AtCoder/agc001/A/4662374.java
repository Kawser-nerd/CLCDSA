import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] kusi = new int[2 * n];
		for (int i = 0; i < 2 * n; i++) {
			kusi[i] = sc.nextInt();
		}
		sc.close();
		Arrays.sort(kusi);
		int ans = 0;
		for (int i = 0; i < 2 * n; i += 2) {
			ans += kusi[i];
		}
		System.out.println(ans);
	}
}