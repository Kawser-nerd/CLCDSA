import java.util.*;
class Main
{
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        Map<Integer,Integer> map = new HashMap<>();
        int[] sum = new int[n+1];
        long ans = 0;
        sum[0] = 0;
        map.put(0, 1);
        for(int i = 1; i < n+1; i++){
            sum[i] = (sum[i-1] + sc.nextInt()) % m;
            if(!map.containsKey(sum[i])){
                map.put(sum[i], 1);
            }else{
                map.put(sum[i], map.get(sum[i]) + 1);
            }
            ans += map.get(sum[i]) - 1;
        }
        System.out.println(ans);
    }
}