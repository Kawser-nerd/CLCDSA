import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long mod=1000000007;
        System.out.println((sc.nextLong()*sc.nextLong()%mod)*sc.nextLong()%mod);
    }
}