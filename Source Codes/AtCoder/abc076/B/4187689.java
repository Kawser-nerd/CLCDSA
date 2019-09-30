import java.util.*;

public class Main {
  
  public static void main (String[] args){
  
  	Scanner scanner = new Scanner (System.in);
    
    int N = scanner.nextInt();
    int K = scanner.nextInt();
    int sum = 1;
    
    if (K <= 2){
      sum += K*N;
    } else {
      for (int i=0; i<N; i++){
        if (sum<K){
          sum=sum*2;
        } else {
          sum+=K;
        }
      }
    }
  
  	System.out.println(sum);
      
  }
}