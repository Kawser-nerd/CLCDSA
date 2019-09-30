package gcj_r2.FreshChocolate;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class FreshChocolate {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("src/gcj_r2/FreshChocolate/A-large.in"));

        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for (int t_i = 1; t_i <= T; t_i++) {
            String[] split = br.readLine().split(" ");
            int N = Integer.parseInt(split[0]);
            int P = Integer.parseInt(split[1]);

            int[] m = new int[P];

            split = br.readLine().split(" ");
            for (int n_i = 0; n_i < N; n_i++) {
                m[Integer.parseInt(split[n_i]) % P]++;
            }

            int answer = 0;
            switch (P) {
                case 2:
                    answer = m[0] + (m[1] + 1) / 2;
                    break;
                case 3:
                    int canPair = Math.min(m[1], m[2]);
                    // this divides by 3
                    answer = m[0] + canPair + (m[1] - canPair) / 3 + (m[2] - canPair) / 3;
                    if ((m[1] - canPair) % 3 != 0 || (m[2] - canPair) % 3 != 0) {
                        answer++;
                    }
                    break;
                case 4:
                    
                    answer += m[0];
                    m[0] = 0;
                    
                    answer += m[2] / 2;
                    m[2] = m[2] % 2;

                    int set13 = Math.min(m[1], m[3]);
                    answer += set13;
                    m[1] -= set13;
                    m[3] -= set13;
                    
                    if (m[2] == 1 && m[1] >= 2) {
                        answer++;
                        m[2] = 0;
                        m[1] -= 2;
                    }

                    if (m[2] == 1 && m[3] >= 2) {
                        answer++;
                        m[2] = 0;
                        m[3] -= 2;
                    }
                    
                    int set1 = m[1] / 4;
                    answer += set1;
                    m[1] -= 4 * set1;

                    int set3 = m[3] / 4;
                    answer += set3;
                    m[3] -= 4 * set3;
                    
                    if (m[1] > 0 || m[2] > 0 || m[3] > 0) {
                        answer++;
                    }
                    
                    break;
                default: throw new IllegalArgumentException();
            }

            sb.append("Case #").append(t_i).append(": ").append(answer).append("\n");
        }

        Files.write(Paths.get("src/gcj_r2/FreshChocolate/A-large.out"), sb.toString().getBytes());
        System.out.println(sb.toString());
    }
}
