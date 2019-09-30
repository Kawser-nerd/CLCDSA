/*
????????????????long???????
???split??contains??????"+"??????????????"\\+"???
???????arr1=arr.clone()
HashSet<>[]???????????????
 */
import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int L=sc.nextInt();
        int X=sc.nextInt();
        int Y=sc.nextInt();
        int S=sc.nextInt();
        int D=sc.nextInt();
        double ans;
        if(S>=D){
            double t1=(double)(S-D)/(double)(Y-X);
            double t2=(double)(L-(S-D))/(double)(Y+X);
            if(t1<0)ans=t2;
            else ans=min(t1,t2);
        }else {
            double t1=(double)(D-S)/(double)(Y+X);
            double t2=(double)(L-(D-S))/(double)(Y-X);
            if(t2<0)ans=t1;
            else ans=min(t1,t2);
        }
        if(S==D)ans=0;
        out.println(ans);
    }
}