import java.util.*;

public class Main {    
    
  public static void main(String[] args) {
      
    Scanner sc = new Scanner(System.in);    
               
    long N = sc.nextLong();
    long M = sc.nextLong();    
    
    if(Math.abs(M-N) >= 2){
        System.out.println(0);
        return;
    }
    
    long MOD = 1000_000_007;            
    long ans = 1;

    for(int i = 1;i <= N;i++){
        ans = (ans*i)%MOD;
    }
    
    for(int i = 1;i <= M;i++){
        ans = (ans*i)%MOD;
    }
       
    if(N == M){
        ans = (2*ans)%MOD;
    }
    
    System.out.println(ans);
      
  }          
}