import java.util.*;
class Main
{
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] b = new int[m];
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < m; i++){
            int x = sc.nextInt() - 1;
            b[i] = sc.nextInt() - 1;
            if(map.containsKey(b[i])){
                x = Math.max(x, map.get(b[i]));
            }
            map.put(b[i], x);
        }
        Arrays.sort(b);
        int[] a = new int[m];
        for(int i = 0; i < m; i++){
            a[i] = map.get(b[i]);
        }
        int ans = 0;
        int index = 0, tmp;
        while(index < m){
            ans++;
            tmp = b[index];
            while(index < m && a[index] < tmp){
                index++;
            }
        }
        System.out.println(ans);
    }
}