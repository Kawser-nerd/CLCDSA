package gcj_r2.RollerCoasterScheduling;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class RollerCoasterScheduling {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("src/gcj_r2/RollerCoasterScheduling/B-large.in"));

        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for (int t_i = 1; t_i <= T; t_i++) {
            String[] split = br.readLine().split(" ");
            int N = Integer.parseInt(split[0]);
            int C = Integer.parseInt(split[1]);
            int M = Integer.parseInt(split[2]);

            int[] ticketsPerCustomer = new int[C];
            int[] ticketsPerSeat = new int[N];

            for (int m_i = 0; m_i < M; m_i++) {
                split = br.readLine().split(" ");
                int seat = Integer.parseInt(split[0]) - 1;
                int cust = Integer.parseInt(split[1]) - 1;
                
                ticketsPerCustomer[cust]++;
                ticketsPerSeat[seat]++;
            }
            
            int rides = 0;
            for (int count : ticketsPerCustomer) {
                if (count > rides) {
                    rides = count;
                }
            }

            int sum = 0;
            for (int seat = 0; seat < N; seat++) {
                sum += ticketsPerSeat[seat];
                int ridesReq = (sum + seat) / (seat + 1);
                if (ridesReq > rides) {
                    rides = ridesReq;
                }
            }
            
            // now calculate promotions
            int proms = 0;
            int freeUps = 0;
            for (int seat = 0; seat < N; seat++) {
                int count = ticketsPerSeat[seat];
                freeUps += rides - count;
                if (count > rides) {
                    proms += count - rides;
                }
            }

            sb.append("Case #").append(t_i).append(": ").append(rides).append(' ').append(proms).append("\n");
        }

        Files.write(Paths.get("src/gcj_r2/RollerCoasterScheduling/B-large.out"), sb.toString().getBytes());
        System.out.println(sb.toString());
    }

}
