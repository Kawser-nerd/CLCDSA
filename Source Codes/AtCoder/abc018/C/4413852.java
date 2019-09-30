/*
String[]??????????long???????
???split??contains??????"+"??????????????"\\+"???
???????arr1=arr.clone()
HashSet<>[]???????????????
 */
import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int r=sc.nextInt(),c=sc.nextInt(),k=sc.nextInt();
        //s[row][column]
        char[][] s=new char[r+1][c+1];
        for (int i = 0; i < r; i++) {
            String t=sc.next();
            for (int j = 0; j < c; j++) {
                s[i+1][j+1]=t.charAt(j);
            }
        }
        int[][][] count=new int[r+1][c+1][2];
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                int up = i + 1, down = i - 1;
                while (up <= r && s[up][j] == 'o') {
                    count[i][j][0]++;
                    up++;
                }
                while (0 < down && s[down][j] == 'o') {
                    count[i][j][1]++;
                    down--;
                }
            }
        }
        int[][] cnt=new int[r+1][c+1];
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                cnt[i][j]=min(count[i][j][0],count[i][j][1]);
            }
        }
        int ans=0;
        for (int i = k; i <= r-k+1; i++) {
            for (int j = k; j <= c-k+1; j++) {
                if(s[i][j]!='o')continue;
                boolean f=true;
                for (int l = 0; l < k; l++) {
                    if(s[i][j+l]!='o'||s[i][j-l]!='o')f=false;
                    if(cnt[i][j+l]<k-1-l||cnt[i][j-l]<k-1-l)f=false;
                }
                if(f){
                    ans++;
                    //out.println(i+" "+j);
                }
            }
        }
        out.println(ans);
        /*
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                out.print(Arrays.toString(count[i+1][j+1]));
            }
            out.println();
        }
        //*/
    }
}