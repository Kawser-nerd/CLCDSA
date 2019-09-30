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
public class R1_Q1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        new R1_Q1().run();
        
        
        
    }
    
    void run() throws Exception{
        BufferedReader br=new BufferedReader(new FileReader("A-large.in"));
        PrintWriter pw=new PrintWriter("R1_Q1.out");
        StringTokenizer st=new StringTokenizer(br.readLine());

        int L,D,N;
        L=Integer.parseInt(st.nextToken());
        D=Integer.parseInt(st.nextToken());
        N=Integer.parseInt(st.nextToken());

        ArrayList<String> set=new ArrayList<String>();
        for(int i=0;i<D;i++){
            set.add(br.readLine());
        }

        for(int n_case=1;n_case<=N;n_case++){
            String o_p=br.readLine();
            String p=o_p.replaceAll("\\(", "[");
            p=p.replaceAll("\\)", "]");
            //Pattern pa=Pattern.compile(p);
            int result=0;
            for(int i=0;i<D;i++){
                if(set.get(i).matches(p)){
                    result++;
                }
            }
            pw.println("Case #"+n_case+": "+result);
        }

        pw.close();
    }
}
