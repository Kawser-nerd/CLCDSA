import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        long A = sc.nextLong();
        long B = sc.nextLong();
        long C = sc.nextLong();
        int mod = 1000000007;
        
        //ab ? r mod n ?? abc ? rc mod n ????
        //r = ab % n ????abc ? (((a*b) % n)*c) mod n ???????
        System.out.println((((A * B)% mod)*C)% mod);
    }
}