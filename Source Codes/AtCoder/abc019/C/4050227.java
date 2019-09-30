import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        int[] a=new int[n];
        HashSet<Integer> ans=new HashSet<>();
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextInt();
            while (a[i]%2==0){
                a[i]/=2;
            }
            ans.add(a[i]);
        }
        out.println(ans.size());
    }
}