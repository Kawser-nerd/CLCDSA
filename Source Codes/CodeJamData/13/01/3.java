import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.NoSuchElementException;
import java.io.Writer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author ogiekako
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("taska.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("taska.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		MyScanner in = new MyScanner(inputStream);
		MyPrintWriter out = new MyPrintWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, MyScanner in, MyPrintWriter out) {
        char[][] board = new char[4][];
        for(int i=0;i<4;i++)board[i] = in.next().toCharArray();
        boolean filled = true;
        for(int i=0;i<4;i++)for(int j=0;j<4;j++)if(board[i][j] == '.')filled = false;
        boolean oWon = won(board, 'O');
        boolean xWon = won(board, 'X');
        String res = null;
        if(oWon){
            res = "O won";
        }else if(xWon){
            res = "X won";
        }else if(filled){
            res = "Draw";
        }else {
            res = "Game has not completed";
        }
        out.printFormat("Case #%d: %s\n",testNumber, res);
    }

    private boolean won(char[][] board, char c) {
        for(int i=0;i<4;i++){
            boolean won = true;
            for(int j=0;j<4;j++)if(board[i][j] != 'T' && board[i][j] != c)won = false;
            if(won)return true;
        }
        for(int j=0;j<4;j++){
            boolean won = true;
            for(int i=0;i<4;i++)if(board[i][j] != 'T' && board[i][j] != c)won = false;
            if(won)return true;
        }
        boolean won = true;
        for(int i=0;i<4;i++)if(board[i][i] != 'T' && board[i][i] != c)won = false;
        if(won)return true;
        won = true;
        for(int i=0;i<4;i++)if(board[i][3-i] != 'T' && board[i][3-i] != c)won = false;
        if(won)return true;
        return false;
    }
}

class MyScanner {
    private final InputStream in;

    public MyScanner(InputStream in) {
        this.in = in;
    }

    int bufLen;
    int bufPtr;
    byte[] buf = new byte[1024];

    public int read() {
        if (bufLen == -1)
            throw new InputMismatchException();
        if (bufPtr >= bufLen) {
            bufPtr = 0;
            try {
                bufLen = in.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (bufLen <= 0)
                return -1;
        }
        return buf[bufPtr++];
    }

    private char[] strBuf = new char[65536];

    public String next() {
        int strLen = 0;
        int c;
        do {
            c = read();
            if (c == -1) throw new NoSuchElementException();
        } while (Character.isWhitespace(c));
        do {
            if (strLen + 1 >= strBuf.length) {
                char[] tmp = new char[strBuf.length * 2];
                System.arraycopy(strBuf, 0, tmp, 0, strBuf.length);
                strBuf = tmp;
            }
            strBuf[strLen++] = (char) c;
            c = read();
        } while (c != -1 && !Character.isWhitespace(c));
        return new String(strBuf, 0, strLen);
    }


    }

class MyPrintWriter {
    PrintWriter out;

    public MyPrintWriter(OutputStream outputStream) {
        out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public MyPrintWriter(Writer writer) {
        out = new PrintWriter(writer);
    }

    public void close() {
        out.close();
    }

    public void printFormat(String format, Object... args) {
        out.printf(format,args);
    }

}

