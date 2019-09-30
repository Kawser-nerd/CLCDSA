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
        int n = sc.nextInt(), k = sc.nextInt(), l = sc.nextInt();
        road.Init(n + 1);
        rail.Init(n + 1);
        int[] ans = new int[n + 1];

        for (int i = 0; i < k; i++) {
            int a = sc.nextInt(), b = sc.nextInt();
            road.unite(a, b);
        }

        for (int i = 0; i < l; i++) {
            int a = sc.nextInt(), b = sc.nextInt();
            rail.unite(a, b);
        }

        int[] d1=new int[n+1];
        int[] d2=new int[n+1];
        HashMap<Point,ArrayDeque<Integer>> map=new HashMap<>();

        for (int i = 1; i < n + 1; i++) {
            d1[i]=road.find(i);
            d2[i]=rail.find(i);
            Point p=new Point(d1[i],d2[i]);
            if(map.get(p)==null){
                ArrayDeque<Integer> temp=new ArrayDeque<>();
                temp.add(i);
                map.put(p,temp);
            }else {
                ArrayDeque<Integer> temp=map.get(p);
                temp.add(i);
                map.put(p,temp);
            }
        }

        for (Point p:map.keySet()){
            ArrayDeque<Integer> temp=map.get(p);
            int size=temp.size();
            while (!temp.isEmpty()){
                ans[temp.poll()]=size;
            }
        }

        for (int i = 1; i < n + 1; i++) {
            out.print(ans[i]);
            if (i < n) out.print(" ");
        }
        out.println();
        out.close();
    }

    static class road {
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

    }

    static class rail {
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