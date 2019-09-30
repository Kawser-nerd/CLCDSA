import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[]$) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        //d[i][j]:(i,j)??
        int[][] d=new int[n+1][n+1];
      //areasize:?????????????????????????
        int[][] areasize=new int[n+1][n+1];
        for (int row = 1; row <=n; row++) {
            for (int col = 1; col <= n; col++) {
                d[row][col]=sc.nextInt();
                areasize[row][col]=1;
            }
        }
        int Q=sc.nextInt();
        int[] p=new int[Q];
        for (int i = 0; i <Q; i++) {
            p[i]=sc.nextInt();
        }
      //??????
        for (int row = 1; row <=n; row++) {
            for (int col = 1; col <= n; col++) {
                d[row][col]+=d[row][col-1];
                areasize[row][col]+=areasize[row][col-1];
            }
            for (int col = 1; col <= n; col++) {
                d[row][col]+=d[row-1][col];
                areasize[row][col]+=areasize[row-1][col];
            }
        }
        int[] ans=new int[n*n+1];
        //ans[i]:??????????i???????????????
        for (int row1 = 1; row1 <= n; row1++) {
            for (int col1 = 1; col1 <= n; col1++) {
                for (int row2 = 0; row2 < row1; row2++) {
                    for (int col2 = 0; col2 < col1; col2++) {
                        int TakoNum=calc(areasize,row1,col1,row2,col2);
                        //?????????????????i??????????????????
                        ans[TakoNum]=max(ans[TakoNum],calc(d,row1,col1,row2,col2));
                    }
                }
            }
        }
        int maximum=0;
      //i??????i???
        for (int i = 1; i < n*n+1; i++) {
            maximum=max(maximum,ans[i]);
            ans[i]=max(ans[i],maximum);
        }
        for (int k:p)out.println(ans[k]);
    }
  //?????????????????
    static int calc(int[][] x,int r1,int c1,int r2,int c2){
        return x[r1][c1]-x[r1][c2]-x[r2][c1]+x[r2][c2];
    }
}