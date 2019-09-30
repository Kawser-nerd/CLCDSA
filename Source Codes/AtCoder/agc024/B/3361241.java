import java.util.*;

class Main
{
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] p = new int[n];
        int[] q = new int[n];
        for(int i = 0; i < n; i++){
            q[ sc.nextInt() - 1 ] = i;
        }
        int ans = n - 1;
        int tmp = 1;
        for(int i = 1; i < n; i++){
            if(q[i-1] < q[i]){
                tmp++;
            }else{
                tmp = 1;
            }
            ans = Math.min(ans, n - tmp);
        }
        System.out.println(ans);
    }
}