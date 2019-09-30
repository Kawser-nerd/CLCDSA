import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;
public class SquareTiles {
    
    public static void main(String args[]) throws FileNotFoundException {
        new SquareTiles();
    }
    
    public SquareTiles() throws FileNotFoundException {
        Scanner scanner = new Scanner(System.in);
        PrintWriter writer = new PrintWriter(new File("C:/res.txt"));
        int COUNT = scanner.nextInt();
        for (int y = 1; y <= COUNT; y++) {
            int N = scanner.nextInt(), M = scanner.nextInt();
            char matrix[][] = new char[N][M];
            for (int i = 0; i < N; i++) {
                String t = scanner.next();
                for (int j = 0; j < M; j++)
                    matrix[i][j] = t.charAt(j);
            }
            boolean impossible = false;
            loop: for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (matrix[i][j] == '#') {
                        if (i < N - 1 && j < M - 1 && matrix[i][j] == '#' && matrix[i][j + 1] == '#'
                            && matrix[i + 1][j] == '#' && matrix[i + 1][j + 1] == '#') {
                            matrix[i][j] = '/';
                            matrix[i][j + 1] = '\\';
                            matrix[i + 1][j] = '\\';
                            matrix[i + 1][j + 1] = '/';
                        } else {
                            impossible = true;
                            break loop;
                        }
                    }
                }
            }
            writer.write(String.format("Case #%d:\n", y));
            if (impossible)
                writer.write("Impossible\n");
            else {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < M; j++)
                        writer.write(matrix[i][j]);
                    writer.write("\n");
                }
            }
        }
        writer.close();
    }
}
