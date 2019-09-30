import java.util.*;

public class Main {        
    
  public static void main(String[] args) {              
     
      Scanner sc = new Scanner(System.in);                                    
     
      long A = sc.nextLong();
      long B = sc.nextLong();
      
      if(A*B < 0){
          System.out.println(B-A-1);
      }else{
          System.out.println(B-A);
      }
      
  }     
}