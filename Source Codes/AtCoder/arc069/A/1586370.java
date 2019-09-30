import java.util.*;

public class Main {    
    
  public static void main(String[] args) {
   
    Scanner sc = new Scanner(System.in);                  
                
    long N = sc.nextLong();
    long M = sc.nextLong();
    
    long result = 0;
    
    if(M >= 2*N){
       result = N + (M - 2*N)/4;
    }else{              
       result = M/2;
    }      
    
    System.out.println(result);
    
  }    
}