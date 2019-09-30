import java.util.*;

public class Main{    

        static int N;    

        static ArrayList<Integer>[] list;                   
        
        static int []dp;        
            
	public static void main(String[] args) {
		
           Scanner sc = new Scanner(System.in);                                                            
           
           N = sc.nextInt();
           
           list = new ArrayList[N];           
           dp = new int[N];
           
           for(int i = 0 ;i < N;i++){
               list[i] = new ArrayList<Integer>();
           }
           
           for(int i = 1;i < N;i++){
               int x = sc.nextInt();
               list[x].add(i);
           }
           
           dfs(0);
           
           StringBuilder sb = new StringBuilder();

	   for (int i = 0; i < N; i++) {
			int ans = N - dp[i];
			for (int item : list[i]) {
				ans = Math.max(ans, dp[item]);
			}
			sb.append(ans + "\n");
            }
		System.out.print(sb);
           
	}    
        
        static int dfs(int now) {
		int res = 1;
		for (int next : list[now]) {
			res += dfs(next);
		}
		return dp[now] = res;
	}
        
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.