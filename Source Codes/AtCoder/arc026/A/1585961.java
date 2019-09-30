import java.util.*;

public class Main {    
    
  public static void main(String[] args) {
   
     Scanner sc = new Scanner(System.in);          
    
     int N = sc.nextInt();
     int A = sc.nextInt();
     int B = sc.nextInt();
     
     if(N > 5){
         System.out.println((N-5)*A + B*5);
         return;
     }else{
         System.out.println(N*B);
         return;
     }
     
  }
  
  
}