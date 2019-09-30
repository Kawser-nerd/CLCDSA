import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int a = Integer.parseInt(sc.next());
        int b = Integer.parseInt(sc.next());
        
        String s = sc.next();
        
        if(s.length() == a+b+1 && s.charAt(a) == '-'){
            for(int i = 0; i < s.length(); i++){
               char c = s.charAt(i);
               
               if(i != a && c == '-'){
                   System.out.println("No");
                   return;
               }
          }
          System.out.println("Yes");
          return;
        }
        
        System.out.println("No");
    }
}