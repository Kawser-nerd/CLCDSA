import java.util.*;

class Main
{
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long a = sc.nextInt();
        long b = sc.nextInt();
        long c = sc.nextInt();
        long d = sc.nextInt();

        boolean bl = false;
        for(int i = 0; i < n; i++){
            if( a + c * i - d * (n - i - 1) <= b && b <= a + d * i - c * (n - i - 1)){
                bl = true;
            }
        }

        String ans = (bl == true)? "YES" : "NO";
        System.out.println(ans);

    }
}