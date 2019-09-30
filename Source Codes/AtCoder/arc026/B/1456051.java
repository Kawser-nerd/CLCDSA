import java.util.*;

public class Main {           
    public static void main(String[] args) {		        
       Scanner sc = new Scanner(System.in);               
        
       long N = sc.nextLong();
                
       long M = (long) Math.floor(Math.sqrt(N));
       
       if(N == 1){
           System.out.println("Deficient");
           return;
       }       
       
       long ans = 1l;
       
       for(long i = 2l;i <= M;i++){
           if(N%i == 0){               
                  if(i != N/i){
                      ans += N/i;
                  }
                  ans += i;
           }           
       }
       
       if(ans == N){
           System.out.println("Perfect");
       }else if(ans < N){
           System.out.println("Deficient");           
       }else if(ans > N){
           System.out.println("Abundant");                      
       }       
       
    }           
}