import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] cards = new int[100];
        int alice = 0;
        int bob = 0;
        for (int i = 0; i < n; i++) {
            cards[i] = sc.nextInt();
        }
        Arrays.sort(cards);
        for (int i = 0; i < cards.length; i++) {
            if(i % 2 == 0) {
                bob += cards[i];
            } else {
                alice += cards[i];
            }
        }
        System.out.println(alice - bob);
    }
}