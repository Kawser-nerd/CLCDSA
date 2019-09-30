import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(input.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int m = Integer.parseInt(tokenizer.nextToken());

        Pair[] studant = new Pair[n];
        Pair[] checkPoint = new Pair[m];

        for (int i = 0; i < n; i++) {
            tokenizer = new StringTokenizer(input.readLine());
            studant[i] = new Pair(Integer.parseInt(tokenizer.nextToken()), Integer.parseInt(tokenizer.nextToken()));
        }

        for (int i = 0; i < m; i++) {
            tokenizer = new StringTokenizer(input.readLine());
            checkPoint[i] = new Pair(Integer.parseInt(tokenizer.nextToken()), Integer.parseInt(tokenizer.nextToken()));
        }
        int x;
        Pair out;
        int index;
        StringBuilder output = new StringBuilder();
        for (int i = 0; i < n; i++) {
            x = Integer.MAX_VALUE;
            out = null;
            index = 0;
            for (int j = 0; j < m; j++) {
                int dis = studant[i].getDistance(checkPoint[j]);
                if (dis < x) {
                    x = dis;
                    out = checkPoint[j];
                    index = j + 1;
                } else if (dis == x && checkPoint[j].iAmSmaller(out)) {
                    x = dis;
                    out = checkPoint[j];
                    index = j + 1;
                }
            }
            output.append(index).append("\n");
        }
        System.out.print(output);
    }


    static class Pair {
        int x;
        int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public boolean iAmSmaller(Pair p) {
            if (p == null)
                return true;

            if (this.x < p.x) {
                return true;
            } else if (this.x > p.x) {
                return false;
            } else if (this.y < p.y) {
                return true;
            } else {
                return false;
            }
        }

        public int getDistance(Pair p) {
            return Math.abs(p.x - this.x) + Math.abs(this.y - p.y);
        }

    }
}