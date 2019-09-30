import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		long N = sc.nextLong();
		long M = sc.nextLong();
		String S = sc.next();
		String T = sc.next();
		
		long lcm = N * M / gcd(N,M);
		
		Map<Long,Character> map = new HashMap<>();
		for (int i = 0; i < N; i++) {
			if (i == 0) {
				map.put(1L, S.charAt(0));
			} else {
				map.put(i*lcm/N+1, S.charAt(i));
			}
		}
		
		for (int i = 0; i < M; i++) {
			if (i == 0) {
				if (map.get(1L) != T.charAt(0)) {
					System.out.println(-1);
					return;
				}
			} else {
				if (map.containsKey(i*lcm/M+1)) {
					if (map.get(i*lcm/M+1) != T.charAt(i)) {
						System.out.println(-1);
						return;
					}
				}
			}
		}
		
		System.out.println(lcm);
	}
	
	static long gcd(long a, long b) {
		long tmp = 0;
		while((tmp = a%b) != 0) {
			a = b;
			b = tmp;
		}
		return b;
	}
}