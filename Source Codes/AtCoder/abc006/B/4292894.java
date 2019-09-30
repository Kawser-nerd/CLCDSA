import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		
		long[] map = new long[1_000_000];
		map[0] = 0;
		map[1] = 0;
		map[2] = 1;
		for (int i = 3; i < map.length; i++) {
			long num = map[i-3] + map[i-2] + map[i-1];
			map[i] = num % 10_007;
		}
		
		System.out.println(map[N-1]);
	}
}