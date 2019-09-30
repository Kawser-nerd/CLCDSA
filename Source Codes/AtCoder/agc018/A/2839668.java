import java.util.Arrays;
import java.util.Scanner;
public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long K = sc.nextLong();
		
		long[] map = new long[N];
		for (int i = 0; i < N; i++) {
			map[i] = sc.nextLong();
		}
		
		Arrays.sort(map);
		
		int index = Arrays.binarySearch(map, K);
		//???????
		if (index >= 0) {
			System.out.println("POSSIBLE");
			return;
		}
		//???????????
		if (~index >= N) {
			System.out.println("IMPOSSIBLE");
			return;
		}
		
		for (int i = 0; i < (N - 1); i++) {
			long A = map[i];
			if (Arrays.binarySearch(map, A + 1) >= 0 || Arrays.binarySearch(map, A - 1) >= 0) {
				System.out.println("POSSIBLE");
				return;
			}
			
			if (Arrays.binarySearch(map, A + A + 1) >= 0 || Arrays.binarySearch(map, A - A - 1) >= 0) {
				System.out.println("POSSIBLE");
				return;
			}
			
			if (A > K && Arrays.binarySearch(map, A - K) >= 0) {
				System.out.println("POSSIBLE");
				return;
			}
		}

		System.out.println("IMPOSSIBLE");
	}

}