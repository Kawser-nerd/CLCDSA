import java.util.*;

public class Main {
    private static String s;

    public static void input(){
        Scanner scan = new Scanner(System.in);

        s = scan.next();
    }

    public static void main(String args[]) {
        //??
        input();

        boolean i_flag = false;
        boolean c_flag = false;
        boolean t_flag = false;
        for (int i=0;i<s.length();i++){
            if (s.charAt(i) == 'i' || s.charAt(i) == 'I') i_flag = true;
            if (i_flag && (s.charAt(i) == 'c' || s.charAt(i) == 'C')) c_flag = true;
            if (c_flag && (s.charAt(i) == 't' || s.charAt(i) == 'T')) t_flag = true;
        }
        if (t_flag) System.out.println("YES");
        else System.out.println("NO");
    }
}