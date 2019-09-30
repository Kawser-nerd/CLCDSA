import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
//Loop?????????????
//int????????????????
//Loop??????10?????????Loop?????
public class Main {
    public static void main(String[]$){
        Scanner sc = new Scanner(in);
        int N=0,W=0,E=0,S=0;
        String s=sc.next();
        int n=s.length();
        for (int i = 0; i < n; i++) {
            switch(s.charAt(i)){
                case 'N':
                    ++N;
                    break;
                case 'W':
                    ++W;
                    break;
                case 'S':
                    ++S;
                    break;
                case 'E':
                    ++E;
                    break;
                default:
                    break;
            }
        }
        String ans="Yes";
        if((N==0||S==0)&&(N+S>0))ans="No";
        else if((W==0||E==0)&&(W+E>0))ans="No";
        out.println(ans);
    }
}