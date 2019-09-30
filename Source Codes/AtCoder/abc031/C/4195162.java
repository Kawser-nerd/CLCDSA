import java.util.Scanner;

public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        
        int[] map = new int[N];
		for (int i = 0; i < N; i++) {
			map[i] = sc.nextInt();
		}
		
		long ans = Integer.MIN_VALUE;
		for (int i = 0; i < N; i++) {
			
			int baseAoki = Integer.MIN_VALUE;
			int baseTakahashi = Integer.MIN_VALUE;
			for (int j = 0; j < N; j++) {
				if (i == j)
					continue;
				
				int aoki = 0;
				int takahashi = 0;
				boolean type = true;
				for (int s = Math.min(i, j); s <= Math.max(i, j); s++) {
					if (type) {
						takahashi += map[s];
					} else {
						aoki += map[s];
					}
					
					type = !type;
				}
				
				if (aoki > baseAoki) {
					baseAoki = aoki;
					baseTakahashi = takahashi;
				}
			}
			ans = Math.max(baseTakahashi, ans);
		}
		
		System.out.println(ans);
    }
}