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
//import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        int n=sc.nextInt(),m=sc.nextInt();
        UF.Init(n);
        TreeSet<Integer> ts=new TreeSet<>();
        for (int i = 0; i < m; i++) {
            int u=sc.nextInt()-1,v=sc.nextInt()-1;
            if(ts.contains(UF.find(u))&&ts.contains(UF.find(v))){
                continue;
            }else if(ts.contains(UF.find(u))){
                ts.remove(UF.find(u));
                UF.unite(u,v);
                ts.add(UF.find(u));
            }else if(ts.contains(UF.find(v))){
                ts.remove(UF.find(v));
                UF.unite(u,v);
                ts.add(UF.find(u));
            }else if(!UF.unite(u,v)){
                ts.add(UF.find(u));
            }
        }
        //
        HashSet<Integer> set=new HashSet<>();
        for (int i = 0; i < n; i++) {
            if(!ts.contains(UF.find(i)))set.add(UF.find(i));
        }
        out.println(set.size());
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

    static class UF {
        static int[] d;

        static void Init(int size) {
            d = new int[size];
            for (int i = 0; i < size; i++) {
                d[i] = -1;
            }
        }

        static boolean unite(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) return false;
            if (d[x] > d[y]) {
                int t = d[y];
                d[y] = d[x];
                d[x] = t;
            }
            d[x] += d[y];
            d[y] = x;
            return true;
        }

        static boolean same(int x, int y) {
            return find(x) == find(y);
        }

        static int find(int k) {
            return d[k] < 0 ? k : (d[k] = find(d[k]));
        }

        static int size(int k) {
            return -d[find(k)];
        }
    }
}
/*
6
7
1 2
2 3
3 1
4 5
5 6
6 4
1 6

???0???
 */