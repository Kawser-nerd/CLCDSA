import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class PerfectHarmony {
    public static void main(String args[]) throws FileNotFoundException {
        new PerfectHarmony();
    }
    
    public PerfectHarmony() throws FileNotFoundException {
        Scanner scanner = new Scanner(System.in);
        PrintWriter writer = new PrintWriter(new File("C:/res.txt"));
        int COUNT = scanner.nextInt();
        for (int y = 1; y <= COUNT; y++) {
            int N = scanner.nextInt(), L = scanner.nextInt(), H = scanner.nextInt();
            int nums[] = new int[N];
            for (int i = 0; i < N; i++)
                nums[i] = scanner.nextInt();
            boolean result = false;
            loop: for (int i = L; i <= H; i++) {
                for (int j = 0; j < N; j++)
                    if (i % nums[j] != 0 && nums[j] % i != 0)
                        continue loop;
                writer.write(String.format("Case #%d: %d\n", y, i));
                result = true;
                break loop;
            }
            if (!result) {
                writer.write(String.format("Case #%d: NO\n", y));
            }
        }
        writer.close();
    }
}
