import java.util.*;

public class Main {
    static int n, k, q;
    static int[] a;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        q = sc.nextInt();
        a = new int[n];
        for(int i=0; i<n; i++){
            a[i] = sc.nextInt();
        }
        sc.close();

        int ans = Integer.MAX_VALUE;
        for(int i=0; i<n; i++){
            int y = a[i];
            int x = calcMax(y);
            if(x > 0){
                ans = Math.min(ans, x-y);
            }
        }

        System.out.println(ans);
    }

    public static int calcMax(int min){
        int max = 0;
        ArrayList<Integer> all = new ArrayList<Integer>();
        ArrayList<Integer> cont = new ArrayList<Integer>();
        for(int i=0; i<n; i++){
            if(a[i] >= min){
                cont.add(a[i]);
            }else{
                if(cont.size() >= k){
                    Collections.sort(cont);
                    for(int j=0; j<cont.size()-k+1; j++){
                        all.add(cont.get(j));
                    }
                }
                cont.clear();
            }
        }
        if(cont.size() >= k){
            Collections.sort(cont);
            for(int j=0; j<cont.size()-k+1; j++){
                all.add(cont.get(j));
            }
        }

        if(all.size() >= q){
            Collections.sort(all);
            max = all.get(q-1);
        }else{
            max = -1;
        }
        return max;
    }
}