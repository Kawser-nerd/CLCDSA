import java.util.*;

public class Main {    
    
  public static void main(String[] args) {
   
     Scanner sc = new Scanner(System.in);          
           
     String  S = sc.next();
     
     S = S.replace("O","0").replace("D","0").replace("I","1").replace("Z","2").replace("S","5").replace("B","8");
     
     System.out.println(S);
     
  }                            
}