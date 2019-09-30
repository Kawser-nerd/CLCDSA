import java.util.*;

public class Main {
	public static final int[] PRIME = new int[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173 , 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281 , 283, 293, 307, 311, 313, 317};

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int[] sums = new int[100000 / 2 + 1];
		int count = 0;
		for (int i = 3; i < 100000; i += 2) {
			if (isPrime(i) && isPrime((i + 1) / 2)) {
				count++;
			}
			sums[i / 2 + 1] = count;
		}
		StringBuilder sb = new StringBuilder();
		int q = sc.nextInt();
		for (int i = 0; i < q; i++) {
			int l = sc.nextInt();
			int r = sc.nextInt();
			sb.append(sums[r / 2 + 1] - sums[l / 2]).append("\n");
		}
		System.out.print(sb);
	}
	
	public static boolean isPrime(int x) {
		for (int i = 0; i < PRIME.length; i++) {
			if (x <= PRIME[i]) {
				break;
			}
			if (x % PRIME[i] == 0) {
				return false;
			}
		}
		return true;
	}
}