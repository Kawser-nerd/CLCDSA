import java.util.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        String s=sc.next();
        int a=sc.nextInt(),b=sc.nextInt(),c=sc.nextInt(),d=sc.nextInt();
        String[] sub=new String[5];
        sub[0]=s.substring(0,a);
        sub[1]=s.substring(a,b);
        sub[2]=s.substring(b,c);
        sub[3]=s.substring(c,d);
        sub[4]=s.substring(d,s.length());
        for (int i = 0; i < 5; i++) {
            out.print(sub[i]);
            if(i<4)out.print("\"");
        }
        out.println();
    }
}