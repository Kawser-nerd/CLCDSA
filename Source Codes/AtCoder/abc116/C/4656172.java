import java.util.*;

public class Main {
	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int[] h = new int[N];
		for (int i = 0; i < N; i++) {
			h[i] = sc.nextInt();
		}
		
		int operations = 0;
		
		while(true) {
			int start = 0;
			int min = 0;
			int currentOperations = operations;
			for (int i = 0; i < N; i++) {
				if (h[i] > 0) {
					if (min == 0 || h[i] < min) {
						min = h[i];
					}
				} else {
					for (int j = start; j < i; j++) {
						h[j] -= min;
					}
					operations += min;
					start = i+1;
					min = 0;
				}
			}
			for (int j = start; j < N; j++) {
				h[j] -= min;
			}
			operations += min;
			
			if (currentOperations == operations) {
				break;
			}
		}
		
		System.out.println(operations);
	}
}