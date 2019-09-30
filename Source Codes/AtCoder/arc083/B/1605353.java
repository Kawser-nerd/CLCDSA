import java.util.Scanner;

public class Main{
  static int n;
  static int[][] dist;

  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    n = sc.nextInt();
    dist = new int[n][n];
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        dist[i][j] = sc.nextInt();
      }
    }

    long sum = 0;
    for(int i = 0; i < n; i++){
      for(int j = i + 1; j < n; j++){
        sum += (long)dist[i][j];
      }
    }

    boolean[][] subtracted = new boolean[n][n];
    for(int i = 0; i < n; i++){
      for(int j = i + 1; j < n; j++){
        for(int k = 0; k < n; k++){
          if(k == i || k == j){
            continue;
          }
          if(dist[i][j] > dist[i][k] + dist[k][j]){
            System.out.println(-1);
            return;
          }
          if(!subtracted[i][j] && 
            dist[i][j] == dist[i][k] + dist[k][j]){
            sum -= (long)dist[i][j];
            subtracted[i][j] = true;
          }
        }
      }
    }

    System.out.println(sum);
  }
}