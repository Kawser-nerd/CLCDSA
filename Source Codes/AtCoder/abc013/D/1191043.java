import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    int D = sc.nextInt();
    int[] id = new int[N + 1];
    for(int i = 0; i < N + 1; i++) {
      id[i] = i;
    }
    for(int i = 0; i < M; i++) {
      int a = sc.nextInt();
      int temp = id[a];
      id[a] = id[a + 1];
      id[a + 1] = temp;
    }
    int[] goal = new int[N + 1];
    for(int i = 1; i < N + 1; i++) {
      goal[id[i]] = i;
    }
    // powGoal[i][j]?i???????2^j????????????goal???
    int[][] powGoal = new int[N + 1][31];
    for(int i = 1; i < N + 1; i++) {
      powGoal[i][0] = goal[i];
    }
    for(int j = 1; j < 31; j++) {
      for(int i = 1; i < N + 1; i++) {
        powGoal[i][j] = powGoal[powGoal[i][j - 1]][j - 1];
      } 
    }
    for(int i = 1; i < N + 1; i++) {
      int g = i;
      for(int j = 0; j < 30; j++) {
        if((D & (1 << j)) != 0) {
          g = powGoal[g][j];
        }
      }
      System.out.println(g);
    }
  }
}