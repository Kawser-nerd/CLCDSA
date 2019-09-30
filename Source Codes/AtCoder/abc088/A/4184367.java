import java.util.*;

public class Main{
  
  public static void main (String[] args){
  
  	Scanner scanner = new Scanner (System.in);
  
 	int N = scanner.nextInt();
    int A = scanner.nextInt();
    
    int remain = N%500;
    
    if (remain <= A){
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}