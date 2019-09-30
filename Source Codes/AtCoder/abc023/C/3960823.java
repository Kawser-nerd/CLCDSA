import java.util.*;
import java.awt.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int R=sc.nextInt(),C=sc.nextInt(),K=sc.nextInt();
        int N=sc.nextInt();
        int[] r=new int[N];
        int[] c=new int[N];
        int[] candy_r=new int[R];
        int[] candy_c=new int[C];
        long ans=0;
        HashMap<Integer,Integer> Row=new HashMap<>();
        HashMap<Integer,Integer> Column=new HashMap<>();
        HashMap<Point,Point> dis=new HashMap<>();
        for (int i = 0; i < N; i++) {
            r[i]=sc.nextInt();
            c[i]=sc.nextInt();
            candy_r[r[i]-1]++;
            candy_c[c[i]-1]++;
        }
        for (int i = 0; i < N; i++) {
            dis.put(new Point(r[i],c[i]),new Point(candy_r[r[i]-1],candy_c[c[i]-1]));
        }
        for (int i = 0; i <R; i++) Row.put(candy_r[i], Row.getOrDefault(candy_r[i], 0) + 1);
        for (int i = 0; i <C; i++) Column.put(candy_c[i], Column.getOrDefault(candy_c[i], 0) + 1);
        for (int i = 0; i <=K; i++) {
            int t=K-i;
            ans+=Row.getOrDefault(i,0)*Column.getOrDefault(t,0);
        }
        for (int i = 0; i <N; i++) {
            Point p=dis.get(new Point(r[i],c[i]));
            if(p.x+p.y==K)ans--;
            if(p.x+p.y==K+1)ans++;
        }
        out.println(ans);
    }
}