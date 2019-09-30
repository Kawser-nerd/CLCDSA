import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();
        String ans = a + b;
        int answer = Integer.parseInt(ans);
        System.out.println(answer * 2);
        sc.close();
    }
}