import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        String s = sc.next();
        int ans=s.length();
        for (char i = 'a'; i <= 'z'; i++) {
            ans = min(ans, solve(s,i,0));
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
    static int solve(String s,char c,int ans){
        if(d(s))return ans;
        else {
            return solve(DaikuStr(s,c),c,ans+1);
        }
    }
    static String DaikuStr(String s,char c){
        String t="";
        for (int i = 0; i < s.length() - 1; i++) {
            t+=s.charAt(i+1)==c?c:s.charAt(i);
        }
        return t;
    }
}