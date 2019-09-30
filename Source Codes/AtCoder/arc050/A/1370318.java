import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {    
    
    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);
        
        String C = sc.next();
        String c = sc.next();
        
        if(c.toUpperCase().equals(C)){
            System.out.println("Yes");
        }else{
            System.out.println("No");            
        }
        
    }        
}