import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int bd = (int)(Math.log10(b))+1;
        a = a*(int)(Math.pow(10,bd)) + b;
        System.out.println(a*2);
    }
}