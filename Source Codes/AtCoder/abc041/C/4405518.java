import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int[] a = new int[N + 1];
        for(int i = 1; i <= N; i++){
            a[i] = sc.nextInt();
        }
        
        Map<Integer,Integer> map = new HashMap<>();
        for(int i = 1; i <= N; i++){
            map.put(a[i],i);
        }
        
        Arrays.sort(a);

        for(int i = N; i > 0; i--){
            int ans = map.get(a[i]);
            System.out.println(ans);
        }
    }
}