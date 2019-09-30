import java.util.*;

class Main{       
   public static void main(String[] args){

      Scanner sc = new Scanner(System.in);                                            
      
      long A = sc.nextLong();

      long K = sc.nextInt();
      
      long M = 2000000000000L;
      
      if(K == 0){
          System.out.println(M - A);
          return;
      }

      long sum = A;
      long index = -1;
      for(int i = 1;;i++){
          sum += 1 + K*sum;
          if(sum >= M){
              index = i;
              break;
          }          
      }      

      System.out.println(index);
      
   }           
 }