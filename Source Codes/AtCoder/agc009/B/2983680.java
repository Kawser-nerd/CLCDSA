import java.util.*;

public class Main {

	public static int[] dp;
	public static ArrayList<Integer>[] win;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		a[0] = 0;
		for(int i=1; i<n; i++){
			a[i] = sc.nextInt();
		}
		sc.close();
		
		win = new ArrayList[n];
		for(int i=0; i<n; i++){
			win[i] = new ArrayList<Integer>();
		}
		
		for(int i=1; i<n; i++){
			win[a[i]-1].add(i);
		}
		dp = new int[n];

		solve(0);
		
		System.out.println(dp[0]-1);
		
	}

	public static void solve(int v){
		int size = win[v].size();
		if(size ==0){
			dp[v] = 1;
			return;
		}
		int[] d = new int[size];
		for(int i=0; i<size; i++){
			int t = win[v].get(i);
			solve(t);
			d[i] = dp[t];
		}
		Arrays.sort(d);
		int depth = 0;
		for(int i=0; i<size; i++){
			if(depth < size - i + d[i]) depth = size - i + d[i];
		}
		dp[v] = depth;
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.