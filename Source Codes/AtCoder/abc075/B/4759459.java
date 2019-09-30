import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int W = sc.nextInt();
        String[][] s = new String[N][W];
        for (int i=0; i<N; i++) {
            String row = sc.next();
            String[] cols = row.split("");
            for (int j=0; j<cols.length; j++) {
                s[i][j] = cols[j];
            }
        }
        String[][] t = new String[N][W];
        Integer[] dx = new Integer[]{0, 1, 0, -1, 1, 1, -1, -1};
        Integer[] dy = new Integer[]{1, 0, -1, 0, 1, -1, 1, -1};
        for (int i=0; i<N; i++) {
            for (int j = 0; j < W; j++) {
                if ("#".equals(s[i][j])) {
                    t[i][j] = "#";
                } else {
                    int cnt = 0;
                    for (int d=0; d<8; d++) {
                        int posx = i + dx[d];
                        int posy = j + dy[d];
                        if (0 <= posx && posx < N && 0 <= posy && posy < W) {
                            if ("#".equals(s[posx][posy]))
                                cnt++;
                        }
                    }
                    t[i][j] = String.valueOf(cnt);
                }
            }
        }
        for (int i=0; i<N; i++) {
            StringBuffer sb = new StringBuffer();
            for (int j = 0; j < W; j++) {
                sb.append(t[i][j]);
            }
            System.out.println(sb);
        }
    }
}