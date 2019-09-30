import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        String s=sc.next();
        int l=0,r=1;
        int n=s.length();
        int ans=0;
        while (r<n&&l<n-1){
            if(l==r)r++;
            if(s.charAt(l)=='S'){
                if(s.charAt(r)=='T'){
                    ans++;
                    r++;
                    l++;
                }else {
                    r++;
                }
            }else{
                l++;
            }
        }
        out.println(n-ans*2);
    }
}