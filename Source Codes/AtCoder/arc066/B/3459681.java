import java.util.HashMap;
import java.util.Scanner;

public class Main {
	static HashMap<Long, Long> map = new HashMap<>();
	static final long MOD = 1000000007;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		sc.close();
		
		System.out.println(dfs(n+1));
	}

	static long dfs(long n){
		if(n == 1) return 1;
		if(n == 0) return 0;
		if(map.containsKey(n)) return map.get(n);
		long ret;
		if(n % 2 ==  1){
			ret = (2*dfs(n/2) + dfs(n/2+1)) % MOD;
			map.put(n, ret);
		}else{
			ret = (2*dfs(n/2) + dfs(n/2-1)) % MOD;
			map.put(n, ret);
		}
		return ret;
	}

}