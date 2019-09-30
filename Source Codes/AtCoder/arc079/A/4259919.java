import java.util.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n = sc.nextInt(),m=sc.nextInt();
        int[] a=new int[200001];
        int[] b=new int[200001];
        HashSet<Integer>[] via=new HashSet[200001];
        if(n==200001||m==200001){
            while (true){
                
            }
        }
        for (int i = 1; i <= 200000; i++) {
            via[i]=new HashSet<>();
        }
        for (int i = 0; i < m; i++) {
            a[i]=sc.nextInt();
            b[i]=sc.nextInt();
            via[a[i]].add(b[i]);
            via[b[i]].add(a[i]);
        }
        for (Integer k:via[1]){
            for (Integer l:via[k]){
                if(l==n){
                    out.println("POSSIBLE");
                    exit(0);
                }
            }
        }
        out.println("IMPOSSIBLE");
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.