import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String b = sc.next();
        System.out.println(pair(b));
    }
    public static String pair(String b){
        final String A = "A",
        C = "C",
        G = "G",
        T = "T";
        switch(b){
            case A:
            return T;
            case T:
            return A;
            case G:
            return C;
            case C:
            return G;
            default :
            return "";
        }
    }
}