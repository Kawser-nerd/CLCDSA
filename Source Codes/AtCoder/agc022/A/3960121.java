import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[]$) {
        Scanner sc = new Scanner(in);
        boolean[] d=new boolean[26];
        for (int i = 0; i < 26; i++) {
            d[i]=false;
        }
        char[] c=new char[26];
        for (int i = 0; i < 26; i++) {
            c[i]=(char)('a'+i);
        }
        String s=sc.next();
        if(s.length()<26) {
            for (int i = 0; i < s.length(); i++) {
                char p = s.charAt(i);
                d[p-97]=true;
            }
            for (int i = 0; i < 26; i++) {
                if(!d[i]){
                    out.println(s+c[i]);
                    break;
                }
            }
        }else{
            int countR=25;
            while(countR>0&&s.charAt(countR)<s.charAt(countR-1)){
                d[s.charAt(countR)-97]=true;
                countR--;
            }
            if(countR==0){
                out.println(-1);
            }else{
                TreeSet<Character> ts=new TreeSet<>();
                for (int i = countR; i < 26; i++) {
                    if(s.charAt(countR-1)<s.charAt(i))ts.add(s.charAt(i));
                }
                for (int i = 0; i <countR-1; i++) {
                    out.print(s.charAt(i));
                }
                out.println(ts.pollFirst());
            }
        }
    }
}