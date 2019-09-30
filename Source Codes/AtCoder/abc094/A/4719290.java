import java.util.*;

public class Main {
 
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt();
    int B = sc.nextInt();
    int X = sc.nextInt();
    if(A > X)
      answer(false);
    else
      answer(B >= X - A);
      
  }
  
  public static void answer(boolean yes){
    System.out.println(yes ? "YES" : "NO"); 
  }
  
}