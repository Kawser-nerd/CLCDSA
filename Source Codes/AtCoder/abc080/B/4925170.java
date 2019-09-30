import java.util.*;

public class Main {
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        long n = Long.parseLong(sc.next());
        
        String s = String.valueOf(n);
        
        char[] ch = s.toCharArray();
        
        int sum = 0;
        
        for(char c : ch){
            sum += c - '0';
        }
        System.out.println(n%sum==0?"Yes":"No");
    }
}