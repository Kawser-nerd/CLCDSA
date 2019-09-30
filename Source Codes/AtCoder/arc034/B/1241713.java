import java.util.*;

public class Main {
            
       private static long f(long x){

           long ret = 0;
           
           while(x > 0){
               ret += x%10;
               x /= 10;
           }           
           
           return ret;
       }        
    
	public static void main(String[] args) {
              Scanner sc = new Scanner(System.in);                                                                                     
                                                 
              long N = sc.nextLong();
              
              ArrayList<Long> set = new ArrayList<Long>();              
              
              for(long i = Math.max(1,N-1000) ;i < N;i++){
                  long val = i + f(i);
                  if(val == N){
                      set.add(i);
                  }
              }
              
              System.out.println(set.size());
              for(long c: set){
                  System.out.println(c);
              }
                          
        }     
        
}