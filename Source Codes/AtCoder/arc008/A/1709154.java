import java.util.*;

class Main{       
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);            
      
      int N = sc.nextInt();
      
      int count = 0;
      
      while(N >= 10){
          N-=10;
          count++;
      }
      
      if(0 <= N && N<=6){
          System.out.println(count*100 + 15*N);
      }else if(7 <= N && N <= 9){
          System.out.println(100*(count+1));
      }
      
      
   }
}