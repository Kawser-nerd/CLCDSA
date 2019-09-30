import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt(),m=sc.nextInt();
        int[] a=new int[m];
        ArrayDeque<Integer> stack=new ArrayDeque<>();
        for (int i = n; i > 0; i--) {
            stack.addFirst(i);
        }
        for (int i = 0; i < m; i++) {
            a[i]=sc.nextInt();
            stack.addFirst(a[i]);
        }
        int[] used=new int[n+1];
        while (stack.size()>0){
            int ans=stack.pollFirst();
            if(used[ans]==0){
                out.println(ans);
                used[ans]++;
            }
        }
    }
}