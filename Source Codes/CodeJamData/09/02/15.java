import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class B {
    public static void main(String[] args) {
        new B().run();
    }
    void run() {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int cases=1;cases<=T;++cases){
            int H = sc.nextInt();
            int W = sc.nextInt();
            int[][] map = new int[H][W];
            int[][] sinkMap = new int[H][W];
            for(int i=0;i<H;++i)for(int j=0;j<W;++j)map[i][j]=sc.nextInt();
            //N W E S
            int[] dx = new int[]{ 0,-1,1,0};
            int[] dy = new int[]{-1, 0,0,1};
            for(int i=0;i<H;++i)for(int j=0;j<W;++j){
                    int ci = i, cj = j;
                    while(true){
                        int min = map[ci][cj];
                        for(int k=0;k<4;++k){
                            if(0<=ci+dy[k]&&ci+dy[k]<H&&0<=cj+dx[k]&&cj+dx[k]<W)
                                min=min(min,map[ci+dy[k]][cj+dx[k]]);
                        }
                        if(min==map[ci][cj])break;
                        for(int k=0;k<4;++k)
                            if(0<=ci+dy[k]&&ci+dy[k]<H&&0<=cj+dx[k]&&cj+dx[k]<W)
                                if(min==map[ci+dy[k]][cj+dx[k]]){
                                    ci=ci+dy[k];
                                    cj=cj+dx[k];
                                    break;
                        }                        
                    }
                    sinkMap[i][j]=ci*W+cj;
            }
            
            int[][] altitudes = new int[H][W];
            int a = 'a';
            TreeMap<Integer,Integer> tm = new TreeMap<Integer,Integer>();
            for(int i=0;i<H;++i)for(int j=0;j<W;++j){
                    if(tm.containsKey(sinkMap[i][j]))altitudes[i][j]=tm.get(sinkMap[i][j]);
                    else{
                        altitudes[i][j]=a;
                        tm.put(sinkMap[i][j],a++);
                    }
            }
            

            int result = 0;
            System.out.println("Case #"+cases+": ");
            for(int i=0;i<H;++i){
                for(int j=0;j<W;++j){
                    System.out.print((char)(altitudes[i][j])+" ");
                }
                System.out.println();
            }
            
        }
        
    }
}

