import java.util.*;
public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int A = 0;
    A = N * (N + 1) / 2;
    System.out.println( A * 10000 / N);
  }
}