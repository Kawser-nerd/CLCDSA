import java.util.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        Queue<String> q=new ArrayDeque<>();
        String[] s=sc.nextLine().split(" ");
        for (int i = 0; i < s.length; i++) {
            char c=s[i].charAt(0);
            char t;
            if(c=='R')t='>';
            else if(c=='L')t='<';
            else t='A';
            out.print(t);
            if(i<s.length-1)out.print(" ");
        }
        out.println();
    }
}