import java.util.*;
 
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int log = s.length();
      
      if(s.charAt(log-1)=='T'){
        System.out.print("YES");
      }else{
        System.out.print("NO");
      }

    }
}