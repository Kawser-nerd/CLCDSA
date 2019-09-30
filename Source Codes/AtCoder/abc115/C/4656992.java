import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int[] h = new int[n];
		for(int i = 0; i < n; i++) {
			h[i] = sc.nextInt();
		}
		Arrays.sort(h);
		int[] gap = new int[n-k+1];
		for(int i = 0; i < n-k+1; i++) {
			gap[i] = h[i+k-1] - h[i];
		}
		Arrays.sort(gap);
		System.out.println(gap[0]);
	}

}