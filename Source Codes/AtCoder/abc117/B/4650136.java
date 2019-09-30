import java.util.*;

public class Main {
	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int max = 0;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			int L = sc.nextInt();
			sum += L;
			if (L > max) {
				max = L;
			}
		}
		
		if (max < sum/2.0) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}