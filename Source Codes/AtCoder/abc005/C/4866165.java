import java.util.*;
public class Main {
  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    int N = sc.nextInt();
    int[] A = new int[N];
    for (int i = 0; i < N; i++) {
      A[i] = sc.nextInt();
    }
    int M = sc.nextInt();
    int[] B = new int[M];
    for (int i = 0; i < M; i++) {
      B[i] = sc.nextInt();
    }
    
    int r = 0;

    // B?????????????
    if (A.length >= B.length) {
      int c = 0;
      for (int i = 0; i < B.length; i++) {
        for(int j = c; j < A.length; j++) {
          if (B[i] - A[j] <= T && 0 <= B[i] - A[j]) {
            c = j + 1;
            r++;
            break;
          }
        }
      }
    }

    if(r == B.length){
      System.out.println("yes");
    } else {
      System.out.println("no");
    }
  }
}