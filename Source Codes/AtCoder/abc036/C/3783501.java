import java.util.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[]$){
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        int[] a=new int[n];
        TreeSet<Integer> set1=new TreeSet<>();
        for (int i = 0; i <n ; i++) {
            a[i]=sc.nextInt();
            set1.add(a[i]);
        }
        HashMap<Integer,Integer> m=new HashMap<>();
        int t=set1.size();
        for (int i = 0; i < t; i++) {
            m.put(set1.pollFirst(),i);
        }
        for (int i = 0; i <n ; i++) {
            out.println(m.get(a[i]));
        }
    }
}