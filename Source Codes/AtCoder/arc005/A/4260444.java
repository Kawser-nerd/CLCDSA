import java.util.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        int ans=0;
        for (int i = 0; i < n; i++) {
            String w=sc.next();
            if(i==n-1)w=w.replaceAll("\\.","");
            switch (w){
                case "TAKAHASHIKUN":
                    ans++;
                    break;
                case "Takahashikun":
                    ans++;
                    break;
                case "takahashikun":
                    ans++;
                    break;
                    default:
                        break;
            }
        }
        out.println(ans);
    }
}