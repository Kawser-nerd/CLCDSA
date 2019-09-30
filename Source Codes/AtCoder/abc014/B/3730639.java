import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long x = sc.nextLong();
        char[] _list = Long.toBinaryString(x).toCharArray();
        char[] list = new char[n];
        for (int i = 0; i < _list.length; i++) {
            list[i] = _list[_list.length - i - 1];
        }

        int totalPrice = 0;
        for (int i = 0; i < n; i++) {
            int price = sc.nextInt();
            if (list[i] == '1') {
                totalPrice += price;
            }
        }
        System.out.println(totalPrice);
    }
}