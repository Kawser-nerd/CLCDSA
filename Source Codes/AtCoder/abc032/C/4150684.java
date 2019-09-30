import java.math.BigInteger;
import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        long K = sc.nextLong();
        
        long[] map = new long[N];
        long min = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {
        	map[i] = sc.nextLong();
        	if (map[i] == 0) {
        		System.out.println(N);
        		return;
        	}
        	
        	min = Math.min(min, map[i]);
        }
        
        if (min > K) {
        	System.out.println(0);
    		return;
        }
        
        int ans = 1;
        BigInteger now = BigInteger.valueOf(map[0]);
        int start = 0;
        int end = 0;
        while(start < map.length) {
        	while(true) {
        		
        		if (end < map.length-1 && now.multiply(BigInteger.valueOf(map[end+1])).compareTo(BigInteger.valueOf(K)) < 1) {
        			end++;
        			now = now.multiply(BigInteger.valueOf(map[end]));
        			ans = Math.max(ans, end-start+1);
        		} else {
        			break;
        		}
        	}
        	
        	if (end < map.length-1 && end == start) {
        		end++;
        		now = now.multiply(BigInteger.valueOf(map[end]));
        	}
        	
        	now = now.divide(BigInteger.valueOf(map[start]));
        	start++;
        }
        
        System.out.println(ans);
    }
    
}