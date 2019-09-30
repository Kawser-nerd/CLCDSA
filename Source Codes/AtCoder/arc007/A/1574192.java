import java.util.*;

public class Main {    
    
  public static void main(String[] args) {
   
     Scanner sc = new Scanner(System.in);          
               
    String X = sc.next();
    
    String s = sc.next();
    
    s = s.replace(X,"");
     
    System.out.println(s);
     
  }                            
}