import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s1 = sc.next();
        String s2 = sc.next();
        ArrayList<Integer> d = new ArrayList<Integer>();
        for(int i=0; i<n; i++){
            if(s1.charAt(i) == s2.charAt(i)){
                d.add(1);
            }else{
                d.add(2);
                i++;
            }
        }
        sc.close();

        long mod = 1000000007;
        long ans;
        if(d.get(0) == 1){
            ans = 3;
        }else{
            ans = 6;
        }

        for(int i=1; i<d.size(); i++){
            if(d.get(i) == 1){
                if(d.get(i-1) == 1){
                    ans *= 2;
                }else{
                    ans *= 1;
                }
            }else{
                if(d.get(i-1) == 1){
                    ans *= 2;
                }else{
                    ans *= 3;
                }
            }
            if(ans > mod) ans %= mod;
        }

        System.out.println(ans);
    }
}