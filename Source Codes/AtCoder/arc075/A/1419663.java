import java.util.*;

public class Main {    
    
  public static void main(String[] args) {              
     Scanner sc = new Scanner(System.in);
     
     int N = sc.nextInt();
     
     int sum = 0;
     int min = Integer.MAX_VALUE;
     
     int count = 0;
     for(int i = 0;i < N;i++){
         int a = sc.nextInt();
         if(a%10 == 0){
               count++;
         }
         sum += a;
         if(a%10 != 0){
           min = Math.min(min,a);
         }
     }
     
     if(count == N){
         System.out.println(0);
         return;
     }     
                           
     if(sum%10 != 0){
         System.out.println(sum);
         return;
     }else{
         System.out.println(sum - min);
         return;
     }
      
  }          
}