import java.util.*;
import java.math.*;

class Main{       
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);            
      
      String T1 = "TAKAHASHIKUN";
      String T2 = "Takahashikun";
      String T3 = "takahashikun";
            
      int N = sc.nextInt();
      
      int count = 0;
      
      for(int i = 0;i <= N-2;i++){
          String w = sc.next();
          if(w.equals(T1) || w.equals(T2) || w.equals(T3)){
              count++;
          }          
      }
      
      String last = sc.next();
      
      if(last.equals(T1 + ".") || last.equals(T2 + ".") || last.equals(T3 + ".")){
          count++;
      }
      
      System.out.println(count);
      
   }
}