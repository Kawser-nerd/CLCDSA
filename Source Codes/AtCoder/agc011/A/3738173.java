import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] nck = scanner.nextLine().split(" ");

        int N = Integer.parseInt(nck[0]);
        int C = Integer.parseInt(nck[1]);
        int K = Integer.parseInt(nck[2]);

        List<Integer> passengers = new ArrayList<>();

        for(int i = 0; i < N; i++) {
            passengers.add(Integer.parseInt(scanner.nextLine()));
        }

        passengers.sort(Collections.reverseOrder());
        int bus = 0;

        int current = 0;
        int firstPassenger = 0;
        for (Integer passenger: passengers) {
            if (current == 0) {
                current = 1;
                firstPassenger = passenger;
            } else if ((firstPassenger - passenger) > K) {
                bus++;
                current = 1;
                firstPassenger = passenger;
            } else {
                current++;
            }

            // ??=??????
            if (current == C) {
                bus++;
                current = 0;
                firstPassenger = 0;
            }
        }

        if (current > 0) {
            bus++;
        }

        System.out.println(bus);
    }
}