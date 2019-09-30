import java.util.*;

class Main{       
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);            
      
      int N = sc.nextInt();
      
      int sum = 0;

      for(int i = 0;i < N;i++){
          int a = sc.nextInt();
          int b = sc.nextInt();
          sum += a*b;          
      }      
            
      System.out.println((int)Math.floor(sum*1.05));
      
      
   }
}