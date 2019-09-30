import java.util.*;

public class Main{

  public static void main (String[] args){
    
    Scanner scanner = new Scanner (System.in);
    
    int A = scanner.nextInt();
    String op = scanner.next();
    int B = scanner.nextInt();
    
    if(op.equals("+")){
      System.out.println(A+B);
    } else {
      System.out.println(A-B);
    }
  }
}