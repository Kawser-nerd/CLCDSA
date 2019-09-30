import java.util.*;

public class Main {
  
  public static void main (String[] args){
  
  	Scanner scanner = new Scanner (System.in);
  
  	int N = scanner.nextInt();
    int A = scanner.nextInt();
    
    int blackColor = N*N-A;
  
  	System.out.println(blackColor);
  }
}