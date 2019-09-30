import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int h = sc.nextInt();
        int w = sc.nextInt();
        
        int[][] a = new int[h][w];
        Point[] q = new Point[h*w];
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                a[i][j] = Integer.parseInt(sc.next());
                q[i*w+j] = new Point(i*w+j, a[i][j]);
            }
        }
        
        Arrays.sort(q);
        
        int[][] grd = new int[h][w];
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                grd[i][j] = 1;
            }
        }
        
        final int MOD = (int)1e9 + 7;
        
        int[] dx = {0,1,0,-1};
        int[] dy = {1,0,-1,0};
        for(int i=0; i<q.length; i++){
            Point p = q[i];
            for(int j=0; j<4; j++){
                int x = p.z%w;
                int y = p.z/w;
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(0<=nx && nx<w && 0<=ny && ny<h && a[ny][nx] < a[y][x]){
                    grd[ny][nx] =  (grd[ny][nx] + grd[y][x])%MOD;
                }
            }
        }
        
        long ans = 0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                ans = (ans + grd[i][j])%MOD;
            }
        }
        
        System.out.println(ans);
    }
}

class Point implements Comparable<Point>{
    public int z;
    public int val;
    
    public Point(int z, int val){
        this.z = z;
        this.val = val;
    }
    
    @Override
    public int compareTo(Point o) {
        return o.val - this.val;
    }
}