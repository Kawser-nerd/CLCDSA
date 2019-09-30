package GCJ2008;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;

import common.Helper;

public class Round1B1 {

    
    private static final String INPUT_FILENAME = "data/" + "A-large.in";
    private static final String OUTPUT_FILENAME = INPUT_FILENAME.substring(0, INPUT_FILENAME.length() - 3) + ".out";
  
    public static void main(String[] args) throws Exception {
        String[] allin = Helper.getAllFileContentAsArray(INPUT_FILENAME);
        List<String> allout = new ArrayList<String>();
        int ac = Helper.getIntegersFromString(allin[0])[0];
        //N
        //n, A, B, C, D, x0, y0 and M
        for (int cc = 1; cc <= ac; ++cc) {
            int[] b = Helper.getIntegersFromString(allin[cc]);
            int n = b[0];
            int A = b[1];
            int B = b[2];
            int C = b[3];
            int D = b[4];
            int x0 = b[5],y0 = b[6];
            int M = b[7];
            
            long[][] c = new long[n][2];
            long X = x0, Y = y0;
            c[0][0] = X;
            c[0][1] = Y;
            //print X, Y
            for (int i = 1; i < n; ++i) {
              X = (A * X + B) % M;
              Y = (C * Y + D) % M;
              c[i][0] = X;
              c[i][1] = Y;
            }
            
            long[][] a = new long[3][3];
            for (int i = 0; i < n; ++i) {
                a[(int)c[i][0] % 3][(int)c[i][1] % 3]++; 
            }
            long ret = 0;
            for (int i0 = 0; i0 < 3; ++i0) {
                for (int i1 = 0; i1 < 3; ++i1) {
                    long xx =a[i0][i1];
                    if (xx >= 3) {
                        ret += xx * (xx-1) * (xx-2)/6;
                    }
                }
            }
            for (int i = 0; i < 9; ++i) {
                for (int j = i + 1; j < 9; ++j) {
                    int i0 = i / 3, i1 = i % 3;
                    int j0 = j / 3, j1 = j % 3;
                    long xx = a[i0][i1];
                    long yy = a[j0][j1];
                    if (xx >= 2 && yy >= 1 && (i0+i0+j0)%3==0 && (i1+i1+j1)%3==0) {
                        ret += yy * (xx * (xx-1) / 2);
                    }
                    if (xx >= 1 && yy >= 2 && (i0+j0+j0)%3==0 && (i1+j1+j1)%3==0) {
                        ret += xx * (yy * (yy-1) / 2);
                    }
                }
            }
            for (int i = 0; i < 9; ++i) {
                for (int j = i + 1; j < 9; ++j) {
                    for (int k = j + 1; k < 9; ++k) {
                        long x = a[i/3][i%3];
                        long y = a[j/3][j%3];
                        long z = a[k/3][k%3];
                        int i0 = i/3, i1 = i%3;
                        int j0 = j/3, j1 = j%3;
                        int k0 = k/3, k1 = k%3;
                        if ((i0+j0+k0)%3==0 &&(i1+j1+k1)%3==0) {
                            ret += x*y*z;
                        }
                    }
                }
            }
            String rets = "Case #" + cc + ": " + ret;
            allout.add(rets);
              
        }
        
        for (String ss : allout) {
            log(ss);
        }
        Helper.writeToFile(allout.toArray(new String[0]), OUTPUT_FILENAME);
        

          
        
    }

    public static void log(String s) throws Exception {
        System.out.println(s);
    }
}
