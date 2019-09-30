import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    int[] A = new int[M];
    for (int i = 0; i < M; i++) {
      A[i] = sc.nextInt();
    }
    Main abc118D = new Main();
    System.out.println(abc118D.solve(N, M, A));
  }

  public String solve(int N, int M, int[] A) {
    ABC118DSolve abc118DSolve = new ABC118DSolve(A);
    return abc118DSolve.solve(N);
  }

  class ABC118DSolve {
    int[] dp = new int[10001];
    int[] costs = {2, 5, 5, 4, 5, 6, 3, 7, 6};
    int[] A;
    Map<Integer, Integer> numCosts = new HashMap();

    public ABC118DSolve(int[] A) {
      this.A = A;
      Arrays.fill(dp, -1);
      Arrays.sort(this.A);
      for (int i = 0; i < this.A.length; i++) {
        numCosts.put(costs[this.A[i] - 1], this.A[i]);
      }
      dp[0] = 0;
      for (Map.Entry<Integer, Integer> numCost : numCosts.entrySet()) {
        dp[numCost.getKey()] = 1;
      }
    }

    public String solve(int N) {
      for (int i = 1; i <= N; i++) {
        for (Map.Entry<Integer, Integer> numCost : numCosts.entrySet()) {
          int cost = numCost.getKey();
          if (i > cost && dp[i - cost] > 0) {
            dp[i] = Math.max(dp[i], dp[i - cost] + 1);
          }
        }
      }
      StringBuilder sb = new StringBuilder();
      while(N > 0){
        for(int i = this.A.length -1; i >= 0; i--){
          int cost = this.costs[this.A[i]-1];
          if(N-cost >= 0 && dp[N] - 1 == dp[N-cost]) {
            sb.append(this.A[i]);
            N -= cost;
            break;
          }
        }
      }
      return sb.toString();
    }
  }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.