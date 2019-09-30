/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package gcj;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.regex.Pattern;

/**
 *
 * @author superlukia
 */
public class QR_Q2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        new QR_Q2().run();



    }
    final int MAX=10001;
    int[][] map;
    char[][] result;
    char current_c='a'-1;
    void run() throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("B-large.in"));
        PrintWriter pw = new PrintWriter("QR_Q2.out");
        int T = Integer.parseInt(br.readLine());



        for (int n_case = 1; n_case <= T; n_case++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int H,W;
            H=Integer.parseInt(st.nextToken());
            W=Integer.parseInt(st.nextToken());
            current_c='a'-1;
            map=new int[H+2][W+2];
            for(int i=0;i<H+2;i++){
                for(int j=0;j<W+2;j++){
                    map[i][j]=MAX;
                }
            }
            result=new char[H+2][W+2];
            for(int i=0;i<H+2;i++){
                for(int j=0;j<W+2;j++){
                    result[i][j]=0;
                }
            }

            for(int i=1;i<H+1;i++){
                st=new StringTokenizer(br.readLine());
                for(int j=1;j<W+1;j++){
                    map[i][j]=Integer.parseInt(st.nextToken());
                }
            }

            for(int i=1;i<H+1;i++){
                for(int j=1;j<W+1;j++){
                    check(i,j);
                }
            }

            pw.println("Case #" + n_case + ":");
            for(int i=1;i<H+1;i++){
                for(int j=1;j<W+1;j++){
                    if(j==1){
                        pw.print(result[i][j]);
                    }else{
                        pw.print(" "+result[i][j]);
                    }
                }
                pw.println();
            }
        }

        pw.close();
    }

    private void check(int i, int j) {
        if(result[i][j]==0){
            find(i,j);
        }
    }
char now_c=0;
    private void find(int i, int j) {
        int min=map[i][j];
        int i2,j2,f_i = 0,f_j = 0;
        boolean f=false;

        i2=i-1;
        j2=j;
        if(map[i2][j2]<min){
            f_i=i2;
            f_j=j2;
            min=map[i2][j2];
            f=true;
        }

        i2=i;
        j2=j-1;
        if(map[i2][j2]<min){
            f_i=i2;
            f_j=j2;
            min=map[i2][j2];
            f=true;
        }
        i2=i;
        j2=j+1;
        if(map[i2][j2]<min){
            f_i=i2;
            f_j=j2;
            min=map[i2][j2];
            f=true;
        }
        i2=i+1;
        j2=j;
        if(map[i2][j2]<min){
            f_i=i2;
            f_j=j2;
            min=map[i2][j2];
            f=true;
        }

        if(f) {
            find(f_i,f_j);
            result[i][j]=now_c;
        }else{
            if(result[i][j]==0){
                current_c++;
                now_c=current_c;
                result[i][j]=now_c;
            }else{
                now_c=result[i][j];
            }
        }
    }
}
