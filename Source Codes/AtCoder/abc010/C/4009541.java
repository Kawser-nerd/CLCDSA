import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int txa=sc.nextInt(),tya=sc.nextInt(),txb=sc.nextInt(),tyb=sc.nextInt(),T=sc.nextInt(),V=sc.nextInt();
        int n=sc.nextInt();
        Point[] ladyhouse=new Point[n+2];
        ladyhouse[0]=new Point(txa,tya);
        ladyhouse[n+1]=new Point(txb,tyb);
        for (int i = 1; i <= n; i++) {
            ladyhouse[i]=new Point(sc.nextInt(),sc.nextInt());
        }
        for (int i = 1; i <= n; i++) {
            double dist=getD(ladyhouse[0],ladyhouse[i])+getD(ladyhouse[i],ladyhouse[n+1]);
            if(dist<=V*T){
                out.println("YES");
                exit(0);
            }
        }
        out.println("NO");
    }
    static double getD(Point s,Point g){
        double dx=s.getX()-g.getX();
        double dy=s.getY()-g.getY();
        return sqrt(dx*dx+dy*dy);
    }
}