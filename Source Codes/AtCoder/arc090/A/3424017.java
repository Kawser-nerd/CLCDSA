import java.util.*;
class Main
{
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for(int i = 0; i < n; i++) a[i] = sc.nextInt();
        for(int i = 0; i < n; i++) b[i] = sc.nextInt();
        int[] suma = new int[n];
        int[] sumb = new int[n];
        suma[0] = a[0];
        sumb[n-1] = b[n-1];
        for(int i = 1; i < n; i++){
            suma[i] = suma[i-1] + a[i];
            sumb[n - i - 1] = sumb[n - i] + b[n - i - 1];
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = Math.max(ans, suma[i] + sumb[i]);
        System.out.println(ans);
    }
}