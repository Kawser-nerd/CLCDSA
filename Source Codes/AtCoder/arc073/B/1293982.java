import java.util.*;

public class Main {
	
	/*
	 * default function
	 * */	
	int ni() {
		return cin.nextInt();
	}
	
	String nl() {
		return cin.nextLine();
	}
	
	void println(String str) {	
		System.out.println(str);
	}
	
	void print(String str) {
		System.out.print(str);
	}
	
	/*
	 * default variable
	 */
	
	static final int MOD = 1000000007;
	
	Scanner cin = new Scanner(System.in);	
	String  output;
	
	public static void main(String[] args) {			
		new Main().run();						
	}
	/* default above */
		
	public void run() {
			
		input();
		/* 
		 * start
		 */	
		
		long res = dfs(0, 0);
		/*
		 * finish
		 */
		
		output = res+"";
		println(output);
			
	}
	/* 
	 * define variable
	 */
	
	int N;
	long W;
	long[] weight;
	long[] value;
	
	Map<String, Long> map;
	
	void input() {
		
		N = ni();
		W = cin.nextLong();
		
		weight = new long[N];
		value  = new long[N];
		
		for (int i = 0; i < N; i ++) {
			weight[i] = cin.nextLong();
			value[i]  = cin.nextLong();
		}
		
		map = new HashMap<>();
	}
	
	long dfs(int i, long w) {
		
		
		String key = i +" " + w;
		
		long res = 0;
		
		if (i == N) {
			res = 0;
		}
		
		else if (map.containsKey(key)) {
			return map.get(key);
		}
				
		else if (w > W - weight[i]) {
			
			res = dfs(i + 1, w);
		} else {
			
			long r1 = dfs(i + 1, w);
			long r2 = dfs(i + 1, w + weight[i]) + value[i];
			
			res = Math.max(r1, r2);
		}
		
		map.put(key, res);
		return res;		
	}	
}