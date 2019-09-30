import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        
        long[] map = new long[N];
		for (int i = 0; i < N; i++) {
			map[i] = sc.nextLong();
		}
		
		long[] sum = new long[N+1];
		for (int i = 1; i <= N; i++) {
			sum[i] = map[i-1] + sum[i-1];
		}
		
		Map<Long, Integer> table = new HashMap<>();
		for (long total : sum) {
			if (table.containsKey(total)) {
				table.put(total, table.get(total)+1);
			} else {
				table.put(total, 1);
			}
		}
		
		long ans = 0;
		for (long key: table.keySet()) {
			if (table.get(key) > 1) {
				long num = table.get(key);
				ans += (num * (num-1) / 2);
			}
		}
        
        System.out.println(ans);
    }
}