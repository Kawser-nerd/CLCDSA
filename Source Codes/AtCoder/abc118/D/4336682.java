import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
 
public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
 
    // N matchsticks
    int N = scanner.nextInt();
    // M: Every digit in the integer must be one of the digits A1~AM
    int M = scanner.nextInt();
    int[] a = new int[M];
    for (int i = 0; i < M; i++)
    {
      a[i] = scanner.nextInt();
    }
      
    int[] cost = new int[] {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int[] dp = new int[N + 1];
    
    // dp[1]~dp[N] = -1
    for (int i = 1; i <= N; i++) 
    {
      dp[i] = -1;
    }
    
    // Trace from the a[i] with smallest cost
    for (int i = 1; i <= N; i++)
    {  
      for (int j = 0; j < M; j++)
      {  
        if (i >= cost[a[j]]) 
          dp[i] = Math.max(dp[i], dp[i - cost[a[j]]] + 1);
      }
    }
    int k = dp[N];
    List<Integer> list = new ArrayList<>();


    for (int i = 0; i < k; i++) 
    {
      int d = 0;
      for (int j = 0; j < M; j++)
      {
        if (N >= cost[a[j]] && dp[N] - dp[N - cost[a[j]]] == 1)
        {
          d = Math.max(d, a[j]);
        }
      }
      list.add(d);
      N -= cost[d];
    }
    Collections.sort(list);
    StringBuilder sb = new StringBuilder();
    for (int i = list.size() - 1; i >= 0; i--) 
    {
      sb.append(list.get(i));
    }
    System.out.println(sb.toString());
  }
}