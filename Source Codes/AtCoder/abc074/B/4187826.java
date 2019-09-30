import java.util.*;

public class Main {
  
  public static void main (String[] args){
  
  	Scanner scanner = new Scanner (System.in);
    
  	int N = scanner.nextInt();
    int K = scanner.nextInt();
    int sum = 0;
    
  	for (int i=0; i<N; i++){
      int temp = scanner.nextInt();
      
      if (temp>Math.abs(temp-K)){
        sum+=Math.abs((temp-K)*2);
      } else {
        sum+=temp*2;
      }
    }
    System.out.println(sum);
  }
}