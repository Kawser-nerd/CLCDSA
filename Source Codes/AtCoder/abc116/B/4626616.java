import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int S = sc.nextInt();
        ArrayList<Integer> done = new ArrayList<>();
        int counter = 1;
        done.add(S);
        while (true) {
            counter++;
            if (S%2==1) {
                S = 3*S + 1;
                if (done.contains(S)) {
                    System.out.println(counter);
                    break;
                }
                done.add(S);
            } else {
                S = S/2;
                if (done.contains(S)) {
                    System.out.println(counter);
                    break;
                }
                done.add(S);
            }
        }
    }
}