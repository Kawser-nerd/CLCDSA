import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] A = new int[n+1];
        for(int i=1;i<=n;i++) A[i]=sc.nextInt();
        int[] rec = new int[n+1];
        for(int i=1;i<=n;i++) rec[A[i]] = i;
        int[] dp = new int[n+1];
        Arrays.fill(dp,1);
        boolean[] visited = new boolean[n+1];
        for(int i=1;i<=n-1;i++){
            if(visited[i]) continue;
            visited[i]=true;
            int cur = i;
            int len=1;
            while(cur<=n-1&&rec[cur+1]>rec[cur]){
                cur++;
                len++;
                visited[cur]=true;
            }
            dp[i]=len;
        }
        int res = 0;
        for(int i=1;i<=n;i++) res=Math.max(dp[i],res);
        System.out.println(n-res);
    }
}