import java.util.*;
import java.util.regex.*;

public class Main{            
    
     public static void main(String[] args){
      
        Scanner sc = new Scanner(System.in);
        
        Pattern pattern = Pattern.compile("[^0-9]");
        
        Matcher matcher = pattern.matcher(sc.next());
        
        String ans = matcher.replaceAll("");
        
        System.out.println(ans);
        
   }              
}