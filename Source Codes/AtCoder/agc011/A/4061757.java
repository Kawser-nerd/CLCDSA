import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int C = sc.nextInt();
        int K = sc.nextInt();
        
        int[] map = new int[N];
        for (int i = 0; i < N; i++) {
        	map[i] = sc.nextInt();
        }
        
        Arrays.sort(map);
        
        int ans = 0;
        int first = map[0];
        int count = 1;
        for (int i = 1; i < N; i++) {
        	
        	if (first + K < map[i]) {
        		ans++;
        		count = 1;
        		first = map[i];
        	} else {
        		if (count == C) {
            		ans++;
            		count = 1;
            		first = map[i];
            	} else {
            		count++;
            	}
        	}
        }
        
        System.out.println(ans+1);
    }
}