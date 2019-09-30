import java.util.*;

public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        
		int ans = 0;
        for (int i = 0; i < N; i++) {
			int a = sc.nextInt();
			int max = 1;
			for (int j = 1; j <= a; j++) {
				if (j % 3 != 2 && j % 2 == 1) {
					max = j;
				}
			}
			ans += a-max;
		}	
		
		System.out.println(ans);
    }
}