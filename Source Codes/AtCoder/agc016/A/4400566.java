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
            String temp="";
            for (int i = 0; i < s.length() - 1; i++) {
                if(s.charAt(i+1)==c){
                    temp+=c;
                }else {
                    temp+=s.charAt(i);
                }
            }
            return solve(temp,c,ans+1);
        }
    }
}