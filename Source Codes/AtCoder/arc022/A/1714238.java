import java.util.*;

class Main{           
    
   public static void main(String[] args){
     
       Scanner sc = new Scanner(System.in);                                                          
       
       String S = sc.next();
       
       System.out.println(S.toLowerCase().matches("^.*i.*c.*t.*$") ? "YES":"NO");
       
   }
   
 }