import java.util.*;
import java.awt.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int[] dx={-1,0,1,0};
        int[] dy={0,-1,0,1};
        int[][] A=new int[4][4];//A[y][x]
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                A[i][j]=sc.nextInt();
            }
        }
        int c=0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    int x=j+dx[k];
                    int y=i+dy[k];
                    if(d(x,y)){
                        if(A[i][j]==A[y][x])c++;
                    }
                }
            }
        }
        out.println(c==0?"GAMEOVER":"CONTINUE");
    }
    static boolean d(int x,int y){
        return 0<=x&&x<4&&0<=y&&y<4;
    }
}