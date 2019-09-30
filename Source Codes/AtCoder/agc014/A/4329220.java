import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int a=sc.nextInt(),b=sc.nextInt(),c=sc.nextInt();
        if((a+b+c)%2==1){
            out.println(0);
        }else if(a==b&&b==c&&c==a){
            out.println(-1);
        }else {
            int ans=0;
            while (a%2+b%2+c%2==0){
                ans++;
                int tempA=(b+c)/2;
                int tempB=(a+c)/2;
                int tempC=(b+a)/2;
                a=tempA;
                b=tempB;
                c=tempC;
            }
            out.println(ans);
        }
    }
}