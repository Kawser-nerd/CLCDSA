
import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.StringTokenizer;

/**
 *
 * @author igor_kz
 */
public class SquareTiles {

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int test = Integer.parseInt(in.nextLine());
        for (int t = 1; t <= test; t++) {
            String nums = in.nextLine();
            StringTokenizer st = new StringTokenizer(nums);
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            char[][] map = new char[r][c];
            for (int i = 0 ; i < r ; i++) {
                String row = in.nextLine();
                map[i] = row.toCharArray();
            }
            for (int i = 0 ; i < r - 1; i++) {
                for (int j = 0 ; j < c - 1; j++) {
                    if (map[i][j] == '#' && map[i][j + 1] == '#' && map[i + 1][j] == '#' && map[i + 1][j + 1] == '#') {
                        map[i][j] = '/';
                        map[i + 1][j + 1] = '/';
                        map[i][j + 1] = '\\';
                        map[i + 1][j] = '\\';
                    }
                }
            }
            boolean ok = true;
            for (int i = 0 ; i < r ; i++)
                for (int j = 0 ; j < c ; j++)
                    if (map[i][j] == '#') ok = false;
            out.println("Case #" + t + ":");
            if (!ok) out.println("Impossible"); else {
                for (int i = 0 ; i < r ; i++) {
                    for (int j = 0 ; j < c ; j++)
                        out.print(map[i][j]);
                    out.println();
                }
            }
        }
        out.close();
    }
}
