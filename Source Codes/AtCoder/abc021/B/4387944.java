import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		int K = sc.nextInt();
		
		int[] map = new int[K+2];
		map[0] = a;
		map[1] = b;
		for (int i = 2; i < K+2; i++) {
			map[i] = sc.nextInt();
		}
		
		
		long count = Arrays.stream(map).distinct().count();
		
		System.out.println(count == K+2 ? "YES": "NO");
	}
}