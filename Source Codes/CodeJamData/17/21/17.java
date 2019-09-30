package codejam;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Horse {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("src/codejam/A-large.in"));

        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for (int t_i = 1; t_i <= T; t_i++) {
            String[] split = br.readLine().split(" ");
            int D = Integer.parseInt(split[0]);
            int N = Integer.parseInt(split[1]);
            
            int[] k = new int[N];
            int[] s = new int[N];
            
            double latest = 0;
            
            for (int n_i = 0; n_i < N; n_i++) {
                split = br.readLine().split(" ");
                k[n_i] = Integer.parseInt(split[0]);
                s[n_i] = Integer.parseInt(split[1]);
                
                double time = 1. * (D - k[n_i]) / s[n_i];
                if (time > latest) latest = time;
            }

            sb.append("Case #").append(t_i).append(": ").append(D / latest).append("\n");
        }

        Files.write(Paths.get("src/codejam/horse.out"), sb.toString().getBytes());
        System.out.println(sb.toString());
    }
}
