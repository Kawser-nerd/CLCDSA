import java.util.*;

public class Main {    
    
  public static void main(String[] args) {
   
     Scanner sc = new Scanner(System.in);          
      
     int N = sc.nextInt();
     
     double max = Integer.MIN_VALUE;
     
     for(int i = 0;i < N;i++){
         int a = sc.nextInt();
         int b = sc.nextInt();
         int c = sc.nextInt();
         int d = sc.nextInt();
         int e = sc.nextInt();
         max = Math.max((a + b + c + d + e*110/900.0),max);
     }     
     
     System.out.println(max);
          
  }                            
}