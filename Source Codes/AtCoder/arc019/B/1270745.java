import java.util.*;

public class Main {
    public static void main(String[] args) {    	                 
        Scanner sc = new Scanner(System.in);
        
        String A = sc.next();
                
        int N = A.length();
        
        int count = 0;
        for(int i = 0;i < N/2;i++){
            if(A.charAt(i) != A.charAt(N-i-1))
               count++;
        }

        int ans = 0;
        if(count == 0){
           if(N%2 == 1){
              ans = 25*N - 25;
           }else{
              ans = 25*N;   
           }
        }
        else if(count == 1){
              ans = 25*N - 2;
        }  
        else if(count >= 2){
              ans = 25*N;
        }
        
        System.out.println(ans);
        
    }            
}