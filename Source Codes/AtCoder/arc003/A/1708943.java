import java.util.*;
import java.math.*;

class Main{       
   public static void main(String[] args){

      Scanner sc = new Scanner(System.in);            
      
      int N    = sc.nextInt();
      String S = sc.next();

      int sum = 0;
      for(int i = 0;i < N;i++){
          if(S.charAt(i) == 'A'){
              sum += 4;
          }   
          if(S.charAt(i) == 'B'){
              sum += 3;
          }
          if(S.charAt(i) == 'C'){
              sum += 2;
          }
          if(S.charAt(i) == 'D'){
              sum += 1;
          }
          if(S.charAt(i) == 'F'){
              sum += 0;   
          }          
      }      
      
      System.out.println((double)sum/N);
      
   }
}