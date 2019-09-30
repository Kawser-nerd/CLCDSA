import java.util.*;
import java.math.*;

class Main{       
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);            
      
      Set<Integer> E = new HashSet<Integer>();
      
      for(int i =  0;i < 6;i++){
          E.add(sc.nextInt());
      }
      
      //bonus
      int B = sc.nextInt();      
      
      Set<Integer> L = new HashSet<Integer>();      
      for(int i = 0;i < 6;i++){
          L.add(sc.nextInt());
      }
      
      L.removeAll(E);
      
      int diff = L.size();
      
      if(diff == 0){
          System.out.println(1);
      }else if(diff == 1){
          if(L.contains(B)){
              System.out.println(2);
          }else{
              System.out.println(3);
          }
      }else if(diff == 2){
          System.out.println(4);
      }else if(diff == 3){
          System.out.println(5);
      }else{
          System.out.println(0);
      }
      
   }
}