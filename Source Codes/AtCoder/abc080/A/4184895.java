import java.util.*;

public class Main{
  
  public static void main (String[] args){
  
  	Scanner scanner = new Scanner (System.in);
  
   	int N = scanner.nextInt();
    int A = scanner.nextInt();
    int B = scanner.nextInt();
    
    int plan1 = N*A;
    int plan2 = B;
    
    if (plan1 > plan2){
      System.out.println(plan2);
    } if (plan1 <= plan2){
      System.out.println(plan1);
    }
  }
}