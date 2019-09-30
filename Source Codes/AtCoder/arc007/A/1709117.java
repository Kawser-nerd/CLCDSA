import java.util.*;
import java.math.*;

class Main{       
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);            
      
      String X = sc.next();            
                  
      String S = sc.next();      
      
      for(int i = 0;i < S.length();i++){
          if(S.charAt(i) == X.charAt(0)){
              continue;   
          }          
          System.out.print(S.charAt(i));
      }
      
      System.out.println();
      
   }
}