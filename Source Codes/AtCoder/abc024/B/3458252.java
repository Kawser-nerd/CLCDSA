import java.util.Scanner;
import java.util.Arrays;

public class Main{
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int T = scanner.nextInt();
    int[] A = new int[N];
    int ans = 0;
    for(int i = 0; i < N; i++){
      A[i] = scanner.nextInt();
    }
    for(int i = 0; i < N-1; i++){
      if(A[i]+T>A[i+1]){
        ans += A[i+1]-A[i];
      }else{
        ans += T;
      }
    }
    ans += T;
    System.out.println(ans);
  }
}