import java.util.*;

public class Main {
  public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int M = scanner.nextInt();
    int[] a = new int[M];
    for(int i = 0; i < M; i++){
      a[i] = scanner.nextInt();
    }
    boolean[] used = new boolean[N+1];
    for(int i = 1; i <= N; i++){
      used[i] = false;
    }
    for(int i = M-1; i >= 0; i--){
      if(used[a[i]] != true){
        used[a[i]] = true;
        System.out.println(a[i]);
      }
    }
    for(int i = 1; i <= N; i++){
      if(used[i] != true){
        System.out.println(i);
      }
    }
  }
}