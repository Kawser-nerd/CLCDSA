import java.util.*;

public class Main {                     
   public static void main(String[] args) {		                
      Scanner sc = new Scanner(System.in);    
       
      int N = sc.nextInt();
      
      if(N == 1){
          System.out.println("Not Prime");
          return;
      }
      
      for(int i = 2 ;i*i <= N;i++){
          if(N%i == 0){
              
              if(N%2 == 0 || N%5 == 0){
                  System.out.println("Not Prime");
                  return;
              }
              
              int sum = 0;
              
              while(N!=0){
                  sum += N%10;
                  N/= 10;
              }
              
              System.out.println(sum%3 == 0 ? "Not Prime":"Prime");                                          
              return;
          }                                        
      }
      
      System.out.println("Prime");

   }       
}