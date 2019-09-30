import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;

/**
 * Created by IntelliJ IDEA.
 * User: Geo
 * Date: Jul 27, 2008
 * Time: 12:34:37 PM
 * To change this template use File | Settings | File Templates.
 */
public class Divisibility {
    //st/end/2/3/5/7
    static long dpm[][][][][][]=new long [41][41][2][3][5][7];
    static String nr=null;
    static final BigInteger sdoi=new BigInteger("2");
    static final BigInteger strei=new BigInteger("3");
    static final BigInteger scinci=new BigInteger("5");
    static final BigInteger ssapte=new BigInteger("7");
    static long  calcmat(int st,int en,int doi,int trei,int cinci,int sapte) {
        //System.out.println(st+" "+en);
        if (st==en) {
            if ((doi==0)&&(trei==0)&&(cinci==0)&&(sapte==0))
                return 1;
            else
                return 0;
        }
        //System.err.println(dpm[st][en][doi][trei][cinci][sapte]);
        if (dpm[st][en][doi][trei][cinci][sapte]!=-1) {
            //System.out.println("shap");
            return dpm[st][en][doi][trei][cinci][sapte];
        }
        long answ=0;
        for (int i=st+1;i<=en;i++) {
            BigInteger binr=new BigInteger(nr.substring(st,i));
            int ndoi=binr.remainder(sdoi).intValue();
            int ntrei=binr.remainder(strei).intValue();
            int ncinci=binr.remainder(scinci).intValue();
            int nsapte=binr.remainder(ssapte).intValue();
            //System.out.println("rec");
            answ+=calcmat(i,en,(doi+ndoi)%2,(trei+ntrei)%3,(cinci+ncinci)%5,(sapte+nsapte)%7);
            if (i<en)
                answ+=calcmat(i,en,(doi-ndoi+2)%2,(trei-ntrei+3)%3,(cinci-ncinci+5)%5,(sapte-nsapte+7)%7);
        }
        dpm[st][en][doi][trei][cinci][sapte]=answ;
        return answ;
    }
    public static void main(String[] args) throws Exception {
        BufferedReader in=new BufferedReader(new FileReader("input.txt"));
        PrintWriter out=new PrintWriter("output.txt");
        int n=Integer.parseInt(in.readLine());
        for (int tcase=0;tcase<n;tcase++) {
            System.err.println(tcase);
            nr=in.readLine();
            for (int i=0;i<=nr.length();i++)
                for (int j=0;j<=nr.length();j++)
                    for (int k=0;k<2;k++)
                        for (int l=0;l<3;l++)
                            for (int m=0;m<5;m++)
                                for (int o=0;o<7;o++) {
                                    dpm[i][j][k][l][m][o]=-1;
                                    //System.err.println(dpm[i][j][k][l][m][o]);
                                }
            long answ=0;
            for (int i=0;i<2;i++)
                for (int j=0;j<3;j++)
                    for (int k=0;k<5;k++)
                        for (int l=0;l<7;l++) {
                            if ((i==0)||(j==0)||(k==0)||(l==0)) {
                                answ+=calcmat(0,nr.length(),i,j,k,l);
                            }
                        }
            out.println("Case #"+(tcase+1)+": "+answ);
        }
        out.close();
        in.close();
    }
}
