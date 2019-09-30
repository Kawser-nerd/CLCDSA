package gcj4;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class MainA {

    public static void main(String[] args) throws NumberFormatException,
            IOException {

        BufferedReader cin = new BufferedReader(
                new InputStreamReader(
                        new FileInputStream(
                                "c:\\cc\\eclipse-workspace\\ACM\\gcj4\\A-small.in")));
        PrintWriter out = new PrintWriter(
                "c:\\cc\\eclipse-workspace\\ACM\\gcj4\\Aout.txt");
        int testcase = Integer.parseInt(cin.readLine());
        for (int tst = 1; tst <= testcase; tst++) {
            int res = 0;
            int n=Integer.parseInt(cin.readLine());
            int [] h=new int[n];
            int [] w=new int[n];
            boolean [] b=new boolean[n];
            for(int i=0;i<n;i++) {
                StringTokenizer st=new StringTokenizer(cin.readLine());
                int x=Integer.parseInt(st.nextToken());
                int y=Integer.parseInt(st.nextToken());
                String s=st.nextToken();
                h[i]=x;
                w[i]=y;
                b[i]=s.equals("BIRD");

            }
            out.println("Case #" + tst + ": ");
            int m=Integer.parseInt(cin.readLine());
            for(int i=0;i<m;i++) {
                StringTokenizer st=new StringTokenizer(cin.readLine());
                int x=Integer.parseInt(st.nextToken());
                int y=Integer.parseInt(st.nextToken());
                String result="UNKNOWN";
                out:for(int j=0;j<n;j++) {
                    for(int k=0;k<n;k++) {
                        if(b[j]&&b[k]) {
                            if(x>=h[j]&&x<=h[k]&&y<=w[j]&&y>=w[k]) {
                                result="BIRD";
                                break out;
                            }
                        }
                        if(!b[j]&&b[k]) {
                            int minx=Math.min(x,h[k]);
                            int maxx=Math.max(x, h[k]);
                            int miny=Math.min(y,w[k]);
                            int maxy=Math.max(y,w[k]);
                            if(h[j]>=minx&&h[j]<=maxx&&w[j]>=miny&&w[j]<=maxy) {
                                result="NOT BIRD";
                                break out;
                            }
                        }
                    }
                }
                out.println(result);
            }
        }

        out.close();
    }

}
