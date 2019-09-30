import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int h = sc.nextInt();
        int w = sc.nextInt();
        
        int sx,sy,gx,gy;
        sx = sy = gx = gy = -1;
        
        boolean[][] grd = new boolean[h][w];
        
        for(int i=0; i<h; i++){
            String line = sc.next();
            for(int j=0; j<w; j++){
                char c = line.charAt(j);
                if(c=='s'){
                    sy = i;
                    sx = j;
                }else if(c=='g'){
                    gy = i;
                    gx = j;
                }else if(c=='#'){
                    grd[i][j] = true;
                }
            }
        }
        
        int[][] memo = new int[h][w];
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                memo[i][j] = (int)1e9;
            }
        }
        memo[sy][sx] = 0;
        
        ArrayDeque<Integer> q = new ArrayDeque<>();
        q.addFirst(sy*w + sx);
        while(q.size() != 0){
            int tmp = q.pollFirst();
            int y = tmp/w;
            int x = tmp%w;
            int[] d = {0,1,0,-1};
            for(int i=0; i<4; i++){
                int ny = y+d[i^1];
                int nx = x+d[i];
                if(0<=nx && nx<w && 0<=ny && ny<h){
                    if(grd[ny][nx]){
                        if(memo[ny][nx] > memo[y][x]+1){
                            memo[ny][nx] = memo[y][x]+1;
                            q.addLast(ny*w + nx);
                        }
                    }else{
                        if(memo[ny][nx] > memo[y][x]){
                            memo[ny][nx] = memo[y][x];
                            q.addFirst(ny*w + nx);
                        }
                    }
                }
            }
        }
        
        //System.out.println(memo[gy][gx]);
        System.out.println((memo[gy][gx]<=2)?"YES":"NO");
    }
}