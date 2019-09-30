import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;

/**
 * Created by IntelliJ IDEA.
 * User: Geo
 * Date: Jul 27, 2008
 * Time: 12:06:56 PM
 * To change this template use File | Settings | File Templates.
 */
public class Telkey {
    public static void main(String[] args) throws Exception {
        BufferedReader in=new BufferedReader(new FileReader("input.txt"));
        PrintWriter out=new PrintWriter("output.txt");
        int n=Integer.parseInt(in.readLine());
        for (int ncase=0;ncase<n;ncase++) {
            String ln=in.readLine();
            String tks[]=ln.split(" ");
            int p=Integer.parseInt(tks[0]);
            int k=Integer.parseInt(tks[1]);
            int l=Integer.parseInt(tks[2]);
            ln=in.readLine();
            tks=ln.split(" ");
            int freq[]=new int[l];
            for (int i=0;i<l;i++)
                freq[i]=Integer.parseInt(tks[i]);
            Arrays.sort(freq);
            if (p*k<l) {
                out.println("Case #"+(ncase+1)+": Impossible");
                continue;
            }
            long presses=0;
            for (int i=l-1;i>=0;i--)
                presses+=freq[i]*((l-1-i)/k+1);
            out.println("Case #"+(ncase+1)+": "+presses);
        }
        out.close();
        in.close();
    }
}
