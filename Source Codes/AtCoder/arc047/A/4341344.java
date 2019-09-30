import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        int l=sc.nextInt();
        String s=sc.next();
        int tab=1,ans=0;
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i)=='+')tab++;
            else tab--;
            if(tab>l){
                tab=1;
                ans++;
            }
        }
        out.println(ans);
    }
}