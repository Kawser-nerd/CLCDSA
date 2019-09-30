import java.util.*;
import java.awt.geom.Point2D;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[]$){
        Scanner sc = new Scanner(in);
        int h=sc.nextInt();
        int w=sc.nextInt();
        char[][] f=new char[h][w];
        for (int i = 0; i <h ; i++) {
            String s=sc.next();
            for (int j = 0; j < w; j++) {
                f[i][j]=s.charAt(j);
            }
        }
        Point p=new Point(0,0);
        //?,?
        int[] dx={-1,0,1,0};
        int[] dy={0,-1,0,1};
        Deque<Point> stack=new ArrayDeque<>();
        stack.addFirst(p);
        int k=1;
        while(stack.size()>0){
            k++;
            Point t=stack.pollFirst();
            for (int i = 0; i <4 ; i++) {
                int x=t.x+dx[i],y=t.y+dy[i];
                if(D(h,w,x,y)){
                    if(f[y][x]=='#') {
                        if (i == 2 || i == 3) {
                            stack.addFirst(new Point(x , y ));
                            f[t.y][t.x]='0';
                        } else {
                            out.println("Impossible");
                            exit(0);
                        }
                    }
                }
            }
            if(stack.size()>1){
                out.println("Impossible");
                exit(0);
            }
        }
        out.println("Possible");
    }
    static boolean D(int h,int w,int x,int y){
        return 0<=x&&x<w&&0<=y&&y<h;
    }
}