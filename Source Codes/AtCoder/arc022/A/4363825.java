import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        String s=sc.next();
        int I=-1,C=-1,T=-1;
        for (int i = 0; i < s.length(); i++) {
            if(I==-1&&(s.charAt(i)=='I'||s.charAt(i)=='i'))I=i;
        }
        for (int i = s.length()-1; i > -1; i--) {
            if(T==-1&&(s.charAt(i)=='T'||s.charAt(i)=='t'))T=i;
        }
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i)=='C'||s.charAt(i)=='c'){
                if(I!=-1&&T!=-1){
                    if(I<i&&i<T){
                        out.println("YES");
                        exit(0);
                    }
                }
            }
        }
        out.println("NO");
    }
}