import java.util.Arrays;
import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		
		int[] map = new int[N];
		for (int i = 0; i < N; i++) {
			int target = sc.nextInt();
			while(target % 2 == 0) {
				target /= 2;
			}
			map[i] = target;
		}
		
		long ans = Arrays.stream(map).distinct().count();
		
		System.out.println(ans);
	}
	
	
}