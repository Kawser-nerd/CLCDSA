import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {    
    
    public static void main(String[] args){
                
       Scanner sc = new Scanner(System.in);
        
       int N = sc.nextInt();

       StringBuilder sb = new StringBuilder();
       sb.append(1);
       
       for(int i = 1;i <= N - 1;i++)
          sb.append(0);    
       
       sb.append(7);
       
       System.out.println(sb.toString());
        
    }        
}