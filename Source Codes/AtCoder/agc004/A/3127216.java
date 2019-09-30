import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long A = sc.nextLong();
        long B = sc.nextLong();
        long C = sc.nextLong();
        long ans = Math.min(Math.min((A-A/2-A/2)*B*C,(B-B/2-B/2)*C*A),(C-C/2-C/2)*A*B);
        System.out.println(ans);
    }
}