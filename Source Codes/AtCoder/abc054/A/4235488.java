import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt();
    int B = sc.nextInt();
    if(A == 1){
      A = 14;
    }
    if(B == 1){
      B = 14;
    }
    if(A == B){
      System.out.println("Draw");
    }else if(A > B){
      System.out.println("Alice");
    }else{
      System.out.println("Bob");
    }
  }
}