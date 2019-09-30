import java.io.*;
import java.util.Scanner;

public class C {

    private static final String FILE_NAME = "C-small-attempt0";

    public static void main (String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(FILE_NAME+".in"));
        Scanner scanner = new Scanner(in);
        BufferedWriter out = new BufferedWriter(new FileWriter(FILE_NAME+".out"));
        int t = scanner.nextInt();
        for (int c = 1; c <= t; ++c) {
            int n = scanner.nextInt();
            int l = scanner.nextInt();
            int h = scanner.nextInt();
            int[] f = new int[n];
            for (int i = 0; i < n; ++i) {
                f[i] = scanner.nextInt();
            }
            int ret = -1;
            for (int i = l; i <= h; ++i) {
                ret = i;
                for (int j = 0; j < n; ++j) {
                    if (f[j] == i) {
                    } else if (f[j] > i && f[j]%i == 0) {
                    } else if (f[j] < i && i%f[j] == 0) {
                    } else {
                        ret = -1;
                        break;
                    }
                }
                if (ret != -1) {
                    break;
                }
            }
            StringBuilder ans = new StringBuilder();
            ans.append("Case #");
            ans.append(c);
            ans.append(": ");
            if (ret == -1) {
                ans.append("NO");
            } else {
                ans.append(ret);
            }
            out.write(ans.toString()+"\n");
            System.out.println(ans.toString());
        }
        out.close();
    }
}
