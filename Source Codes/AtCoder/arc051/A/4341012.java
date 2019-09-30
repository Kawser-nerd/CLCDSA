import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        Point[] p=new Point[3];
        p[0]=new Point(sc.nextInt(),sc.nextInt());
        int r=sc.nextInt();
        for(int i=1;i<3;i++)p[i]=new Point(sc.nextInt(),sc.nextInt());
        if(c(p,r)){
            out.println("YES");
            out.println("NO");
        }else if(d(p,r)){
            out.println("NO");
            out.println("YES");
        }else {
            out.println("YES");
            out.println("YES");
        }
    }
    static boolean c(Point[] p,int r){
        r*=r;
        int d1=g(p[0],p[1]);
        int d2=g(p[0],p[2]);
        int d3=g(p[0],new Point(p[1].x,p[2].y));
        int d4=g(p[0],new Point(p[2].x,p[1].y));
        return d1<=r&&d2<=r&&d3<=r&&d4<=r;
    }
    static boolean d(Point[] p,int r){
        return p[1].y<=p[0].y-r&&p[0].y+r<=p[2].y&&p[1].x<=p[0].x-r&&p[1].x+r<=p[2].x;
    }
    static int g(Point p1,Point p2){
        return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
    }
}