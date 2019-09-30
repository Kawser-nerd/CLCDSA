import java.util.*;

class Main{       
   public static void main(String[] args){

      Scanner sc = new Scanner(System.in);                                            
      
      int N = sc.nextInt();
      
      for(int i = 2;i <= N - 1;i++){
          if(N%i == 0){
              System.out.println("NO");
              return;
          }          
      }
      
      System.out.println("YES");
       
   }      
}