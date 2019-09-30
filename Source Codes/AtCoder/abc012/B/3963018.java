import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int h = N / 3600;
        int m = (N % 3600) / 60;
        int s = (N % 3600) % 60;
        System.out.println(String.format("%02d", h) + ":" + String.format("%02d", m) + ":" + String.format("%02d", s));
    }
}