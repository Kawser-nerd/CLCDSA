import java.util.*;

public class Main {               
    
  public static void main(String[] args) {     
     
      Scanner sc = new Scanner(System.in);
 
      long N = sc.nextLong();
      int depth = 0;
      for(long n = N;n > 0;n /=2){
          depth++;         
      }
      
      if(depth%2 == 1){
          long x = 1;
          while(true){
            if(x*2 > N){
                System.out.println("Aoki");
                return;
            }  
            x = x*2 +1;
            if(x*2 > N){
                System.out.println("Takahashi");
                return;
            }
            x *= 2;            
          }          
      }else{
          long x= 1;
          while(true){
            if(x*2 > N){
                System.out.println("Aoki");
                return;
            }   
            x *= 2;
            if(x*2 > N){
                System.out.println("Takahashi");
                return;
            }
            x = x*2 + 1;
          }          
      }
      
     
  }   
   
}