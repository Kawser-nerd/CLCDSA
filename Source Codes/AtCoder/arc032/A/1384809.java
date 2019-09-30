import java.util.*;

public class Main {                     
    public static void main(String[] args) {		        
        
       Scanner s = new Scanner(System.in);    
       
       int N = s.nextInt();
       
       if(N == 1){
           System.out.println("BOWWOW");
           return;
       }
       
       N = N*(N+1)/2;
       
       for(int i = 2;i < N;i++){
           if(N%i == 0){
              System.out.println("BOWWOW");
              return;
           }           
       }       
       
       System.out.println("WANWAN");
       
    }
}