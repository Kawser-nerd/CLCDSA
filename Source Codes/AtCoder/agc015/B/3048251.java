import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = s.length();
        long ans = (n-1)*2;
        for(int i=1; i<n-1; i++){
            if(s.charAt(i) == 'U'){
                ans += i * 2 + n-1-i;
            }else{
                ans += i + (n-1-i)*2;
            }
        }
        System.out.println(ans);
    }
}