import java.util.*;

public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        
        int[] map = new int[N];
		int sum = 0;
        for (int i = 0; i < N; i++) {
			map[i] = sc.nextInt();
			sum += map[i];
		}
        
        int M = sc.nextInt();
		for (int i = 0; i < M; i++) {
			int p = sc.nextInt();
			int x = sc.nextInt();
			
			System.out.println(sum - map[p-1] + x);
		}
		
		
    }
}