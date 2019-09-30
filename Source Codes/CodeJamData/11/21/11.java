import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class A{
    public static void main(String[] args) throws Exception{
        new A().run();
    }

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        //BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available
        int T = sc.nextInt();
        for(int o = 1; o <= T; o++){
          int n = sc.nextInt();
          char[][] tbl = new char[n][n];
          for(int i = 0; i < n; i++)
            tbl[i] = sc.next().toCharArray();
          double[] wp = new double[n];
          for(int i = 0; i < n; i++){
            int win = 0;
            int lose = 0;
            for(int j = 0; j < n; j++){
              if(tbl[i][j] == '1')win++;
              if(tbl[i][j] == '0')lose++;
            }
            wp[i] = 1.0 * win / (win + lose);
            //System.out.printf("wp[%d] = %f\n", i, wp[i]);
          }
          double[] owp = new double[n];
          for(int i = 0; i < n; i++){
            double sum = 0;
            int total = 0;
            for(int j = 0; j < n; j++){
              if(tbl[i][j] != '.'){
                int w = 0, l = 0;
                for(int k = 0; k < n; k++){
                  if(k == i)continue;
                  if(tbl[j][k] == '1')w++;
                  if(tbl[j][k] == '0')l++;
                }
                sum += 1.0 * w / (w+l); //wp[j];
                total++;
              }
            }
            owp[i] = sum / total;
            //System.out.printf("owp[%d] = %f\n", i, owp[i]);
          }
          double[] oowp = new double[n];
          for(int i = 0; i < n; i++){
            double sum = 0;
            int total = 0;
            for(int j = 0; j < n; j++){
              if(tbl[i][j] != '.'){
                sum += owp[j];
                total++;
              }
            }
            oowp[i] = sum / total;
            //System.out.printf("oowp[%d] = %f\n", i, oowp[i]);
          }
          System.out.printf("Case #%d:\n", o);
          for(int i = 0; i < n; i++){
            double a = 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i];
            System.out.println(a);
          }
        }
    }
}
