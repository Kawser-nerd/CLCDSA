import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        a = (int)(Math.abs(x-a));
        b = (int)(Math.abs(x-b));
        if(a<b) {
            System.out.println("A");
        }else {
            System.out.println("B");
        }
    }
}