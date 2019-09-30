import java.util.*;

public class Main{
  
  public static void main (String[] args){
  
  	Scanner scanner = new Scanner (System.in);
  
   	int N = scanner.nextInt();
    int sum = 0;
    
    for (int i=0; i<N; i++){
      int l = scanner.nextInt();
      int r = scanner.nextInt();
      sum += (r-l+1);
    }
    System.out.println(sum);
  }
}