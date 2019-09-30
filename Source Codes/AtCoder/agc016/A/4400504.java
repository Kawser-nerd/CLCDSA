import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        String s = sc.next();
        int ans=s.length();
        for (char i = 'a'; i <= 'z'; i++) {
            String t=s;
            int count = 0;
            if (!t.contains(Character.toString(i))) continue;
            while (!d(t)) {
                String temp = "";
                count++;
                for (int j = 0; j < t.length() - 1; j++) {
                    if (t.charAt(j + 1) == i) {
                        temp+=i;
                    }else {
                        temp+=t.charAt(j);
                    }
                }
                t=temp;
            }
            ans = min(ans, count);
        }
        out.println(ans);
    }
    static boolean d(String s){
        int c=0;
        for (int i = 0; i < s.length()-1; i++) {
            if(s.charAt(i)!=s.charAt(i+1)){
                c++;
                break;
            }
        }
        return c==0;
    }
}