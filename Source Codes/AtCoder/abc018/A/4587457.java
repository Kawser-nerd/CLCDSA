import java.util.*;

public class Main{
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    int A = scan.nextInt();
    int B = scan.nextInt();
    int C = scan.nextInt();

    if(A< B && B < C){
      System.out.println(3);
      System.out.println(2);
      System.out.println(1);
    }else if(A < C && C < B){
      System.out.println(3);
      System.out.println(1);
      System.out.println(2);
    }else if(B < C && C < A){
      System.out.println(1);
      System.out.println(3);
      System.out.println(2);
    }else if(B < A && A < C){
      System.out.println(2);
      System.out.println(3);
      System.out.println(1);
    }else if(C < A && A < B){
      System.out.println(2);
      System.out.println(1);
      System.out.println(3);
    }else if(C < B && B < A){
      System.out.println(1);
      System.out.println(2);
      System.out.println(3);
    }
}
}