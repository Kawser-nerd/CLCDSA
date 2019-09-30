import java.util.*;
public class Main {
  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();

    if((N * 2) > M || (N * 4) < M){
      System.out.println("-1 -1 -1");
    } else {
      if ((N * 3) <= M){
        System.out.println(0 + " " + (4 * N - M) + " " + (M - 3 * N));  
      } else {
        System.out.println((3 * N - M) + " " + (M -2 * N) + " " + 0);
      }
    }

  }
}