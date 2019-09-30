import java.util.*;

public class Main{             
    public static void main(String[] args){
      
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        
        int A = sc.nextInt();
        int B = sc.nextInt();        
        
        if(N <= 5){
           System.out.println(B*N);
           return;
        }else{
           System.out.println(A*(N-5) + B*5);            
           return;
        }
        
       
        
    }
    
}