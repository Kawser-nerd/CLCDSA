import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {           
    public static void main(String[] args) {		        
        Scanner sc = new Scanner(System.in);                                       
                      
        int m = sc.nextInt();
        int n = sc.nextInt();        
        int N = sc.nextInt();        
        
        int sum = N;       
        
        int e;
        
        while(N >= m){           
           e = N%m;            
           sum  += n*((N-e)/m);
           N = e + n*((N-e)/m);
        }          
        
        System.out.println(sum);
        
  }
}