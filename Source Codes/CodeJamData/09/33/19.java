/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */



import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.regex.Pattern;

/**
 *
 * @author superlukia
 */
public class R1CPC {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        if(args.length>0) infile=args[0];
        if(args.length>1) outfile=args[1];
        new R1CPC().run();
        
        
        
    }
    static String infile="test.txt";
    static String outfile="R1CPC.out";
    int P,Q;
    int[][] best;
    int[] list;

    void run() throws Exception{
        //BufferedReader br=new BufferedReader(new FileReader("A-large.in"));
        PrintWriter pw=new PrintWriter(outfile);
        //StringTokenizer st=new StringTokenizer(br.readLine());
        Scanner sc=new Scanner(new BufferedInputStream(new FileInputStream(infile)));

        int T=sc.nextInt();
        best=new int[105][105];
        for(int n_case=1;n_case<=T;n_case++){
            P=sc.nextInt(); //P
            Q=sc.nextInt(); //Q
            sc.nextLine();  //无视
            StringTokenizer st=new StringTokenizer(sc.nextLine());  //读下一行
            list=new int[Q+2];    //list
            list[0]=0;
            list[Q+1]=P+1;
            for(int i=1;i<=Q;i++)
                list[i]=Integer.parseInt(st.nextToken());   //list赋值
            for(int i=0;i<Q+2;i++)
                for(int j=0;j<Q+2;j++)
                    best[i][j]=-1;  //best初始化
            int result=dp(0,Q+1);   //出结果
            pw.printf("Case #%d: %d\n",n_case,result);  //输出
            System.out.printf("Case #%d: %d\n",n_case,result);
        }

        pw.close();
    }
    int dp(int start,int end){

        if(best[start][end]!=-1) return best[start][end];

        int r=Integer.MAX_VALUE;
        for(int i=start+1;i<end;i++){
            
                r=Math.min(r, list[end]-list[start]-2+dp(start,i)+dp(i,end));
            
        }
        if(r==Integer.MAX_VALUE) r=0;
        best[start][end]=r;
        return r;
    }
}
