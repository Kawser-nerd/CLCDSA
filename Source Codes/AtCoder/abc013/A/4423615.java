import java.util.*;

public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        char c = a.charAt(0);
        System.out.println(c-'A'+1);
    }
}