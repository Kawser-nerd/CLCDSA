import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {    
    
    public static void main(String[] args){
                
       Scanner sc = new Scanner(System.in);
       
       int N = sc.nextInt();       

       double max = 0;       
       
       for(int i = 0;i < N;i++){
           double sum = 0;
           
           for(int j = 0;j < 4;j++){
               sum += sc.nextInt();
           }
           
           sum += (110*sc.nextInt()/900.0);
           
           max = Math.max(max,sum);           
       }                         
       
       System.out.println(max);
        
    }        
}