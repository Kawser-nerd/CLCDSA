import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int x = 100*a + 10*b + c;
        if(x%4==0) {
            System.out.println("YES");
        }else {
            System.out.println("NO");
        }
    }
}