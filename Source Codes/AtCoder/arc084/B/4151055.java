import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int k=sc.nextInt();
		
		int[] dp =new int[k];
		Arrays.fill(dp,Integer.MAX_VALUE/10);
		dp[1]=1;
		PriorityQueue<Integer> queue=new PriorityQueue<>((x,y) -> dp[x]-dp[y]);
		queue.add(1);
		while(queue.size()>0){
			int cur=queue.poll();
			for(int i=0;i<10;i++){
				int next=(10*cur+i)%k;
				if(dp[next]>(dp[cur]+i)){
					dp[next]=dp[cur]+i;
					queue.add(next);
				}
			}
		}
		System.out.println(dp[0]);
	}
}