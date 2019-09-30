import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(in);
        String s=sc.next();
        long ans=0;
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i)=='U'){
                ans+=s.length()-i-1+2*(i);
            }else{
                ans+=i+2*(s.length()-i-1);
            }
        }
        out.println(ans);
    }
}