package gcj.round1._11;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 *
 * @author epizend
 */
public class A {

    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio(System.in, new FileOutputStream("a.out"));
        int cases = io.getInt();
        int at = 0;
        CASE: while(at++ < cases){
            int r = io.getInt();
            int c = io.getInt();
            boolean[][] board = new boolean[r][c];
            char[][] out = new char[r][c];
            for (int i = 0; i < r; i++) {
                String str = io.getWord();
                out[i] = str.toCharArray();
                for (int j = 0; j < c; j++) {
                    board[i][j] = str.charAt(j) == '#';
                }
            }
            io.println("Case #"+at+":");
            for (int i = 0; i < r-1; i++) {
                for (int j = 0; j < c-1; j++) {
                    if(board[i][j]){
                        if(!board[i+1][j] || !board[i+1][j+1] || !board[i][j+1]){
                            io.println("Impossible");
                            continue CASE;
                        }
                        //System.out.println("color "+i+" "+j);
                        out[i][j] = '/';
                        out[i+1][j+1] = '/';
                        out[i][j+1] = '\\';
                        out[i+1][j] = '\\';
                        board[i][j] = false;
                        board[i][j+1] = false;
                        board[i+1][j] = false;
                        board[i+1][j+1] = false;
                    }
                }
            }
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if(board[i][j]){
                        io.println("Impossible");
                        continue CASE;
                    }
                }
            }
            for (int i = 0; i < r; i++) {
                io.println(out[i]);
            }
        }
        io.flush();
        io.close();
    }
    
    static class Kattio extends PrintWriter {

    public Kattio(InputStream i) {
        super(new BufferedOutputStream(System.out));
        r = new BufferedReader(new InputStreamReader(i));
    }

    public Kattio(InputStream i, OutputStream o) {
        super(new BufferedOutputStream(o));
        r = new BufferedReader(new InputStreamReader(i));
    }

    public boolean hasMoreTokens() {
        return peekToken() != null;
    }

    public int getInt() {
        return Integer.parseInt(nextToken());
    }

    public double getDouble() {
        return Double.parseDouble(nextToken());
    }

    public long getLong() {
        return Long.parseLong(nextToken());
    }

    public String getWord() {
        return nextToken();
    }
    private BufferedReader r;
    private String line;
    private StringTokenizer st;
    private String token;

    private String peekToken() {
        if (token == null) {
            try {
                while (st == null || !st.hasMoreTokens()) {
                    line = r.readLine();
                    if (line == null) {
                        return null;
                    }
                    st = new StringTokenizer(line);
                }
                token = st.nextToken();
            } catch (IOException e) {
            }
        }
        return token;
    }

    private String nextToken() {
        String ans = peekToken();
        token = null;
        return ans;
    }
}
    
}
