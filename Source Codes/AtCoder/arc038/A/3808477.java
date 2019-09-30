import java.util.*;

public class Main {
  public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int[] A = new int[N];
    for(int i = 0; i < N; i++){
      A[i] = scanner.nextInt();
    }
    Arrays.sort(A);
    int sum = 0;
    if(A.length%2==0){
      for(int i = (N-2)/2; i>= 0; i--){
        sum += A[2 * i + 1];
      }
    }else if(A.length%2!=0){
      for(int i = (N-1)/2; i >= 0; i--){
        sum += A[2*i];
      }
    }
    System.out.println(sum);
  }
}