import java.util.*;

class Main{       
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);            
            
      int N = sc.nextInt();
      int M = sc.nextInt();
      int A = sc.nextInt();
      int B = sc.nextInt();
      
      for(int i = 0;i < M;i++){
          int c = sc.nextInt();
          if(N <= A){
              N += B;
          }
          N -= c;          
          if(N < 0){
              System.out.println(i+1);
              return;
          }          
      }
      
      System.out.println("complete");
      
   }
}