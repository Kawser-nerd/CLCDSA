import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        final int N = sc.nextInt();
        final int M = sc.nextInt();
        long[] sum = new long[N+1];
        sum[0] = 0;
        for(int i = 1;i <= N;i++){
            sum[i] = sc.nextInt()+sum[i-1];
        }
        Map<Integer, Integer> modN = new HashMap<>();
        for(int i = 0;i <= N;i++){
            int r = (int)(sum[i]%M);
            if(!modN.containsKey(r)) modN.put(r, 1);
            else    modN.put(r, modN.get(r)+1);
        }
        long ans = 0;
        for(Integer key : modN.keySet()){
            long value = modN.get(key);
            ans += value*(value-1)/2;
        }
        System.out.println(ans);
    }
}