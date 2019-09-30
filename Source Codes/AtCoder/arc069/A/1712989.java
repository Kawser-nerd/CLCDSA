import java.util.*;

class Main{       
   public static void main(String[] args){

      Scanner sc = new Scanner(System.in);                                            
  
      long N = sc.nextLong();
      long M = sc.nextLong();

      if(M >= 2*N){
          System.out.println(N + (M-2*N)/4);                    
      }else{
          System.out.println(M/2);          
      }
      
     
   }
}