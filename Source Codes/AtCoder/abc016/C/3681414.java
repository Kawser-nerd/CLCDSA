import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int M = scanner.nextInt();
    int[] A = new int[M];
    int[] B = new int[M];
    for(int i = 0; i < M; i++){
      A[i] = scanner.nextInt()-1;
      B[i] = scanner.nextInt()-1;
    }
    int[][] Adj = new int[N][N];
    for(int i = 0; i < M; i++){
      for(int j = 0; j < M; j++){
        Adj[A[i]][B[i]] = 1;
        Adj[B[i]][A[i]] = 1;
      }
    }
    int[] count = new int[N];
    for(int i = 0; i < N; i++){
      count[i] = 0;
    }
    boolean[] visited = new boolean[N];
    for(int i = 0; i < N; i++){
      for(int l = 0; l < N; l++){
        visited[l] = false;
      }
      visited[i] = true;
      for(int j = 0; j < N; j++){
        if(Adj[i][j]==1){
          visited[j]=true;
          for(int k = 0; k < N; k++){
            if(visited[k] == false && Adj[j][k]==1 && k!=j && Adj[i][k] == 0){
              visited[k] = true;
              count[i]++;

            }
          }
        }
      }
    }
    for(int i = 0; i < N; i++){
      System.out.println(count[i]);
    }
  }
}