import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int ans = (a*b)*2+(b*c)*2+(c*a)*2;
        System.out.println(ans);
    }
}