import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(input.readLine());
        int h = Integer.parseInt(tokenizer.nextToken());
        int w = Integer.parseInt(tokenizer.nextToken());
        char [][] letters = new char[h][];
        for (int i = 0; i < h; i++) {
            letters[i] = input.readLine().toCharArray();
        }
        int [] x = {1, 0, 1, 0, -1, 1, -1, -1};
        int [] y = {1, 1, 0, -1, 0, -1, 1, -1};
        int sum;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (letters[i][j] == '.'){
                    sum = 0;
                    for (int k = 0; k < 8; k++) {
                        if (check(h, w, i + x[k], j + y[k]) && letters[i + x[k]][j + y[k]] == '#')
                            sum++;
                    }
                    letters[i][j] = (char)('0' + sum);
                }
            }
        }

       StringBuilder out = new StringBuilder();
        StringBuilder row;
        for (int i = 0; i < h; i++) {
            row = new StringBuilder();
            for (int j = 0; j < w; j++) {
                row.append(letters[i][j]);
            }
            out.append(row).append("\n");
        }
        System.out.print(out);
    }
    public static boolean check (int x1, int y1, int x2, int y2){
        return x2 > -1 && x2 < x1 && y2 > -1 && y2 < y1;
    }
}