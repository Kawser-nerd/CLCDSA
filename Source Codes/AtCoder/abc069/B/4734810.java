import java.util.*;
 
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String n = sc.next();
        int len = n.length()-2;
        char a = n.charAt(0);
        char b = n.charAt(len+1);
      
      	System.out.print(a);
        System.out.print(len);
        System.out.print(b);

    }
}