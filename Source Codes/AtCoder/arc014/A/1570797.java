import java.util.*;

public class Main {    
    
  public static void main(String[] args) {
   
     Scanner sc = new Scanner(System.in);          
     
     int N = sc.nextInt();
     
     if(N%2 == 0){
         System.out.println("Blue");
         return;
     }else{
         System.out.println("Red");         
         return;
     }
     
  }                            
}