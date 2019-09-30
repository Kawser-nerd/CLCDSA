import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] pos = new int[n];
        for(int i=0; i<n; i++){
            int tmp = sc.nextInt();
            a[i] = tmp;
            pos[tmp-1] = i;
        }

        TreeSet<Integer> ts = new TreeSet<Integer>();
        long ans = 0;

        for(int i=0; i<n; i++){
            int h, l;
            if(ts.higher(pos[i]) == null){
                h = n;
            }else{
                h = ts.higher(pos[i]);
            }
            if(ts.lower(pos[i]) == null){
                l = -1;
            }else{
                l = ts.lower(pos[i]);
            }

            ans += (long)(pos[i] - l) * (long)(h - pos[i]) * (long)(i+1);

            ts.add(pos[i]);
        }

        System.out.println(ans);
    }

}