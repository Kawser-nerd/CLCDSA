import java.util.Scanner;
import java.util.Collections;

class Main{
    static int[][] map;

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);

        int N = scan.nextInt();
        int K = scan.nextInt();
        map = new int[4*K+1][4*K+1];
        for(int i=0;i<N;++i){
            int x = scan.nextInt();
            int y = scan.nextInt();
            if(scan.next().equals("W"))x+=K;
            y%=2*K;x%=2*K;
            map[y+1][x+1]++;
        }
        for(int i=0;i<2*K;++i)for(int j=0;j<2*K;++j)map[i+1][j+2*K+1]=map[i+1][j+1];
        for(int i=0;i<2*K;++i)for(int j=0;j<2*K;++j)map[i+2*K+1][j+1]=map[i+1][j+1];
        for(int i=0;i<2*K;++i)for(int j=0;j<2*K;++j)map[i+2*K+1][j+2*K+1]=map[i+1][j+1];
        for(int i=0;i<4*K;++i)for(int j=0;j<4*K;++j){
            map[i+1][j+1]+=map[i][j+1]+map[i+1][j]-map[i][j];
        }

        int ans = 0;
        for(int i=1;i<=2*K;++i)for(int j=1;j<=2*K;++j){
            ans = Math.max(ans, map[i+2*K-1][j+2*K-1]-map[i+K-1][j+2*K-1]-map[i+2*K-1][j+K-1]+map[i+K-1][j+K-1]
                               +map[i+K-1][j+K-1]    -map[i-1][j+K-1]    -map[i+K-1][j-1]    +map[i-1][j-1]);
        }
        System.out.println(ans);


    }

}