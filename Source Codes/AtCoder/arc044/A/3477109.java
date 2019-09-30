import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
//Loop?????????????
//int????????????????
//Loop??????10?????????Loop?????
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        int c=0;
        for (int i = 2; i < n; i++) {
            if(n%i==0)break;
            c++;
        }
        if(c==n-2&&n>1){
            out.println("Prime");
        }else{
            int n0=n%10,digsum=0,nt=n;
            while(n>0){
                digsum+=n%10;
                n/=10;
            }
            if(digsum%3!=0&&n0!=5&&n0%2!=0&&nt>1){
                out.println("Prime");
            }else{
                out.println("Not Prime");
            }
        }
    }
}