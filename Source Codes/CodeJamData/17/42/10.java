package round2;

import java.util.Scanner;

public class B {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        for (int caze = 1; caze <= cases; caze++) {
            int N = sc.nextInt();
            int C = sc.nextInt();
            int M = sc.nextInt();
            int[] seats = new int[N];
            int[] clients = new int[C];
            for (int i = 0; i < M; i++) {
                int pos = sc.nextInt() - 1;
                int client = sc.nextInt() - 1;
                seats[pos]++;
                clients[client]++;
            }
            int ansA = 0;
            for (int i = 0; i < clients.length; i++) {
                int client = clients[i];
                ansA = Math.max(ansA, client);
            }
            int acum = 0;
            for (int i = 0; i < seats.length; i++) {
                int seat = seats[i];
                acum += seat;
                ansA = Math.max(ansA, (acum+i) / (i+1));
            }
            int ansB = 0;
            for (int i = 0; i < seats.length; i++) {
                int seat = seats[i];
                if (seat > ansA) ansB += seat - ansA;
            }
            System.out.println("Case #" + caze + ": " + ansA + " " + ansB);
        }
    }
}
