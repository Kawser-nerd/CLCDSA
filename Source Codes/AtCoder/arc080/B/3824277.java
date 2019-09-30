import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    static long ans=0;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt(), W = sc.nextInt();
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i=0;i<n;i++) a[i] = sc.nextInt();
        int[][] ans = new int[H][W];
        int row=0,col=0;
        int flag=1;
        for(int i=0;i<n;i++){
            int cnt = a[i];
            for(int j=0;j<cnt;j++){
                if(col==-1||col==W){
                    col = col==-1?0:W-1;
                    row++;
                    flag=flag*(-1);
                }
                ans[row][col] = i+1;
                col += flag;
            }
        }
        for(int i=0;i<H;i++){
            for(int j=0;j<W-1;j++){
                System.out.print(Integer.toString(ans[i][j])+" ");
            }
            System.out.println(ans[i][W-1]);
        }
    }
}