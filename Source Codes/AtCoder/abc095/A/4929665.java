import java.util.Scanner;
class Main {
  public static void main(String[] args) {
        int price = 700;
        Scanner scan = new Scanner(System.in);
        String order = scan.next();
        char[] chars = order.toCharArray();

        for (char ch : chars) {
            if (ch == 'o') {
                price += 100;
            }
        }
        System.out.println(price);
    }
}