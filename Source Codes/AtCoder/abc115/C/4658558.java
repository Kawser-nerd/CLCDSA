import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int[] h = new int[N];
		for (int i = 0; i < N; i++) {
			h[i] = sc.nextInt();
		}
		Arrays.sort(h);
		int min = Integer.MAX_VALUE;
		for (int i = 0; i + K - 1 < N; i++) {
			min = Math.min(min, h[i+K-1] - h[i]);
		}
		System.out.println(min);
	}
}