import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;


public class Main {
    int H,W;
    char[][] ch;
    boolean[] usedRow,usedColumn;
    int[] swapRow;

    private boolean isSymmetryColumn(int a,int b) {
        for(int i = 0;i < H;i++) {
            if (ch[swapRow[i]][a] != ch[swapRow[H - 1 - i]][b]) {
                return false;
            }
        }
        return true;
    }

    private boolean columnCheck() {
        Arrays.fill(usedColumn,false);
        for(int i = 0;i < W;i++) {
            if (usedColumn[i]) {
                continue;
            }
            for(int j = i+1;j < W;j++) {
                if (usedColumn[j]) {
                    continue;
                }
                if (isSymmetryColumn(i,j)) {
                    usedColumn[i] = true;
                    usedColumn[j] = true;
                    break;
                }
            }
        }
        int notUsedCnt = 0;
        int notSymmetryColumn = -1;
        for (int i = 0; i < W; i++) {
            if (!usedColumn[i]) {
                notSymmetryColumn = i;
                notUsedCnt++;
            }
        }

        if (notUsedCnt >= 2 || (notUsedCnt > 0 && (W % 2 == 0))) {
            return false;
        }

        if (notUsedCnt == 0) {
            return true;
        }

        return isSymmetryColumn(notSymmetryColumn, notSymmetryColumn);
    }

    private boolean dfs(int r,int u,boolean f) {

        if (r >= H) {
            return columnCheck();
        }

        if (usedRow[r]) {
            return dfs(r + 1,u,f);
        }

        if (H % 2 == 1 && !f) {
            swapRow[H / 2] = r;
            usedRow[r] = true;
            if(dfs(r + 1,u,true)){
                return true;
            }
            swapRow[H / 2] = -1;
            usedRow[r] = false;
        }

        if (u < H / 2) {
            for (int i = r + 1; i < H; i++) {
                if (usedRow[i]) {
                    continue;
                }

                usedRow[r] = usedRow[i] = true;
                swapRow[u] = r;
                swapRow[H - 1 - u] = i;

                if (dfs(r + 1,u + 1, f)) {
                    return true;
                }

                swapRow[H - 1 - u] = -1;
                swapRow[u] = -1;
                usedRow[i] = usedRow[r] = false;
            }
        }
        return false;
    }



    private void solve() {
        H = nextInt();
        W = nextInt();

        ch = new char[H][];
        for(int i = 0;i < H;i++) {
            ch[i] = next().toCharArray();
        }

        swapRow = new int[H];
        for(int i = 0;i < H;i++) {
            swapRow[i] = -1;
        }
        usedRow = new boolean[H];
        usedColumn = new boolean[W];

        if (dfs(0,0,false)) {
            out.println("YES");
        } else {
            out.println("NO");
        }
    }
    public static void main(String[] args) {
        out.flush();
        new Main().solve();
        out.close();
    }

    /* Input */
    private static final InputStream in = System.in;
    private static final PrintWriter out = new PrintWriter(System.out);
    private final byte[] buffer = new byte[4096];
    private int p = 0;
    private int buflen = 0;

    private boolean hasNextByte() {
        if (p < buflen)
            return true;
        p = 0;
        try {
            buflen = in.read(buffer);
        } catch (IOException e) {
            e.printStackTrace();
        }
        if (buflen <= 0)
            return false;
        return true;
    }

    public boolean hasNext() {
        while (hasNextByte() && !isPrint(buffer[p])) {
            p++;
        }
        return hasNextByte();
    }

    private boolean isPrint(int ch) {
        if (ch >= '!' && ch <= '~')
            return true;
        return false;
    }

    private int nextByte() {
        if (!hasNextByte())
            return -1;
        return buffer[p++];
    }

    public String next() {
        if (!hasNext())
            throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = -1;
        while (isPrint((b = nextByte()))) {
            sb.appendCodePoint(b);
        }
        return sb.toString();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}