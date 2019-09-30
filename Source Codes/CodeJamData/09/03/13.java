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
public class QR_Q3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        new QR_Q3().run();



    }
    int N;
    int[] map=new int[256];
    int mod=10000;
    void run() throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("C-large.in"));
        PrintWriter pw = new PrintWriter("QR_Q3.out");
        N = Integer.parseInt(br.readLine());
        String ph="welcome to code jam";
        int l=ph.length();
        digest(ph);

        for (int n_case = 1; n_case <= N; n_case++) {
            String line=br.readLine();
            int[] result=new int[l+1];
            result[0]=1;
            for(int i=0;i<line.length();i++){
                char c=line.charAt(i);
                int amap=map[c];
                for(int i_p=0;i_p<l;i_p++){
                    if((amap & 1<<i_p)==0){
                    }
                    else{
                        result[i_p+1]=(result[i_p]+result[i_p+1]) % mod;
                    }
                }
            }

            pw.printf("Case #%d: %04d",n_case,result[l]);
            pw.println();
        }


        pw.close();
    }

    private void digest(String ph) {
        for(int i=0;i<ph.length();i++){
            char c=ph.charAt(i);
            map[c] |=1<<i;
        }
    }


}
