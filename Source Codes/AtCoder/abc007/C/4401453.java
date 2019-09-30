import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(in);
        int H=sc.nextInt();
        int W=sc.nextInt();
        int sy=sc.nextInt()-1,sx=sc.nextInt()-1,gy=sc.nextInt()-1,gx=sc.nextInt()-1;
        int[] dx={-1,0,1,0};
        int[] dy={0,1,0,-1};
        char[][] c=new char[W][H];
        int[][] step=new int[W][H];
        for (int i = 0; i < H; i++) {
            String s=sc.next();
            for (int j = 0; j < W; j++) {
                c[j][i]=s.charAt(j);
                step[j][i]=100000;
            }
        }
        Deque<Point> stack=new ArrayDeque<>();
        step[sx][sy]=0;
        stack.addFirst(new Point(sx,sy));
        while(stack.size()>0){
            Point p=stack.pollFirst();
            for (int i = 0; i < 4; i++) {
                int x=p.x+dx[i];
                int y=p.y+dy[i];
                if(0<=x&&x<W&&0<=y&&y<H&&c[x][y]=='.'){
                    if(step[x][y]>step[p.x][p.y]+1){
                        stack.addFirst(new Point(x,y));
                        step[x][y]=step[p.x][p.y]+1;
                    }
                }
            }
        }
        out.println(step[gx][gy]);
    }
}