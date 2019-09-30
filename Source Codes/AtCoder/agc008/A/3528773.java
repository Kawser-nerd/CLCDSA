import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[]$){
        Scanner sc = new Scanner(in);
        int x=sc.nextInt();
        int y=sc.nextInt();
        int ans1=(int)1e9+4;
        int ans2=(int)1e9+4;
        int ans3=(int)1e9+4;
        int ans4=(int)1e9+4;
        if(-x<=-y)ans1=-y+x+2;
        if(-x<=y)ans2=y+x+1;
        if(x<=y)ans3=y-x;
        if(x<=-y)ans4=-y-x+1;
        out.println(min(min(ans1,ans2),min(ans3,ans4)));
    }
}