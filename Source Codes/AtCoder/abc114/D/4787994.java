/*
String[]??????????long???????
???split??contains??????"+"??????????????"\\+"???
???????arr1=arr.clone()
HashSet<>[]???????????????
?????????????????????????ex.-1/2=0??????>k??????????????????
???>=k???????????????
toLowerCase()???????????????????????????
ArrayDeque??pop?push?Stack????????
//import static java.lang.System.*; ??????????(??????exit(0)?????)?return;?????
???out.flush()???out.close()??????????
*/
//?????Ctrl+D
import java.util.*;
import java.io.*;
import java.awt.*;
import java.awt.geom.Point2D;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        int n=sc.nextInt();
        HashMap<Integer,Integer> pf=new HashMap<>();
        for (int i = 1; i <= n; i++) {
            int s=(int)sqrt(n)+1;
            int t=i;
            for (int j = 2; j <= s; j++) {
                while (t%j==0){
                    pf.put(j,pf.getOrDefault(j,0)+1);
                    t/=j;
                }
            }
            if(t!=1)pf.put(t,pf.getOrDefault(t,0)+1);
        }
        int[] p=new int[25];
        int c=0;
        for (Integer key:pf.keySet())p[c++]=pf.get(key);
        int ans=0;
        for (int i = 0; i < 25; i++) {
            if(p[i]+1>=75)ans++;
        }
        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 25; j++) {
                if(i==j)continue;
                if(p[i]+1>=3&&p[j]+1>=25)ans++;
                if(p[i]+1>=5&&p[j]+1>=15)ans++;
            }
        }
        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 25; j++) {
                for (int k = 0; k < 25; k++) {
                    if(i==j||j==k||k==i)continue;
                    if(p[i]+1>=3&&p[j]+1>=5&&p[k]+1>=5&&j>k)ans++;
                }
            }
        }
        out.println(ans);
        out.close();
    }

    static PrintWriter out = new PrintWriter(System.out);

    static class sc {
        static Scanner s = new Scanner(System.in);

        static String next() {
            return s.next();
        }

        static int nextInt() {
            return Integer.parseInt(s.next());
        }

        static long nextLong() {
            return Long.parseLong(s.next());
        }

        static double nextDouble() {
            return Double.parseDouble(s.next());
        }
    }
}