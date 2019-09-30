import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int x = sc.nextInt();
        if(x<a) {
            System.out.println("NO");
        }else if(x>=a && a+b>=x) {
            System.out.println("YES");
        }else {
            System.out.println("NO");
        }
    }
}