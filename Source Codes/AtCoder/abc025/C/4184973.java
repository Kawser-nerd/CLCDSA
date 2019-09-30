import java.io.IOException;
import java.util.NoSuchElementException;

import java.io.InputStream;

import java.io.PrintWriter;

import java.util.HashMap;

public class Main {
    // ?
    static HashMap<String, int[]> d = new HashMap<>();

    // 2?3? bAry
    static final int rowB = 2;
    static final int clmB = 3;
    static int[][] bAry = new int[rowB][clmB];

    // 3?2? cAry
    static final int rowC = 3;
    static final int clmC = 2;
    static int[][] cAry = new int[rowC][clmC];

    // player??
    static final int player = 2;

    // ?????
    static final int naohiro = 0;

    // ?????
    static final int naoko = 1;

    // Any ?????????
    static final char any = '9';
    static final String strany = String.valueOf(any);
    static final int intAny = Character.getNumericValue(any);

    static int[] anySearch(String s, int i)
    {
        int[] result = {0, 0};
        // zero origin
        int foundIndex = s.length();

        foundIndex = s.indexOf(any);

        if (i != 0) {
            // zero origin but i
            int j = 1;
            while (j <= i) {
                int nextIndex = foundIndex + 1;
                if (nextIndex < s.length()) {
                    foundIndex = s.indexOf(any, nextIndex);
                    j++;
                } else break;
            }
        }

        result[0] = s.length() - s.replaceAll(String.valueOf(any), "").length();
        result[1] = foundIndex;
        return result;
    }

    static int[] calc(String board)
    {
        int[] calc = {0, 0};

        // 2?
        for (int i = 0; i < rowB; i++) {
            // 3?
            for (int j = 0; j < clmB; j++) {
                if (board.charAt(i * 3 + j) == board.charAt((i + 1) * 3 + j)) {
                    // ???????????
                    // ????????
                    calc[0] += bAry[i][j];
                } else {
                    // ???????????
                    // ????????
                    calc[1] += bAry[i][j];
                }
            }
        }
        // 3?
        for (int i = 0; i < rowC; i++) {
            // 2?
            for (int j = 0; j < clmC; j++) {
                if (board.charAt(i * 3 + j) == board.charAt(i * 3 + (j + 1))) {
                    // ???????????
                    // ????????
                    calc[0] += cAry[i][j];
                } else {
                    // ???????????
                    // ????????
                    calc[1] += cAry[i][j];
                }
            }
        }
        return calc;
    }

    static int[] search(String board) {
        // ?????????????
        if (d.containsKey(board)) return d.get(board);

        // any ????
        // ????????????????????
        int[] tmp = anySearch(board, 0);
        int times = tmp[0];
        int first = tmp[1];

        if (times == 0) {
            // ?????????
            // ????
            return calc(board);
        }

        // ????
        // times 1 origin
        int teban = (times - 1) % 2;

        int max = -1;
        int other = 0;

        // times 1 origin
        for (int i = 0; i < times; i++) {
            // ??? board ??
            String copy = new String(board);

            // ??? any ???????
            //copy[first] = Integer.toString(teban).charAt(0);
            char[] c = copy.toCharArray();
            c[first] = Integer.toString(teban).charAt(0);
            int[] point = search(String.valueOf(c));

            if (max < point[teban]) {
                max = point[teban];
                other = point[teban == naohiro ? naoko : naohiro];
            }
            // for?????(i)?????
            first = anySearch(board, i + 1)[1];
        }

        int[] nowResult = new int[player];
        nowResult[teban] = max;
        nowResult[teban == naohiro ? naoko : naohiro] = other;

        // ???????
        d.put(board, nowResult);

        return d.get(board);
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);

        for (int i = 0; i < rowB; i++)
            for (int j = 0; j < clmB; j++) bAry[i][j] = nextInt();

        for (int i = 0; i < rowC; i++)
            for (int j = 0; j < clmC; j++) cAry[i][j] = nextInt();

        // board
        // start position
        // 0 ????
        // 1 ????
        // 9 any
        // 9 9 9 9 9 9 9 9 9

        String board = strany + strany + strany
            + strany + strany + strany
            + strany + strany + strany;

        // ?????????
        // 9?????????????????????
        int[] ans = search(board);

        out.println(ans[0]);
        out.println(ans[1]);

        out.flush();
    }

    // FastScanner start
    static final InputStream in = System.in;
    static final byte[] buffer = new byte[1024];
    static int ptr = 0;
    static int buflen = 0;
    static boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        } else {
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }
    static int readByte() {
        if (hasNextByte()) return buffer[ptr++];
        else return -1;
    }
    static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }
    static boolean hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }
    static String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    static long nextLong() {
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if(b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    static int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
            throw new NumberFormatException();
        return (int) nl;
    }
    static double nextDouble() {
        return Double.parseDouble(next());
    }
    // FastScanner end
}