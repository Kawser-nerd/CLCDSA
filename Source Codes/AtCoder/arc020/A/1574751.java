import java.util.*;

public class Main {    
    
  public static void main(String[] args) {
   
     Scanner sc = new Scanner(System.in);          
           
     int A = sc.nextInt();
     int B = sc.nextInt();
     
     if(Math.abs(A) == Math.abs(B)){
         System.out.println("Draw");
         return;
     }else if(Math.abs(A) > Math.abs(B)){
         System.out.println("Bug");
         return;
     }else{
         System.out.println("Ant");         
         return;
     }
     
  }                            
}