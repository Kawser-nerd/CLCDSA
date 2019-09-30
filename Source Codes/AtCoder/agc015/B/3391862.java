import java.util.*;

class Main
{
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int[] a = new int[s.length()];
        long ans = 0;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) =='U') ans += (s.length() - i - 1) + i * 2;
            else ans += (s.length() - i - 1) * 2 + i;
        }
        System.out.println(ans);
    }
}