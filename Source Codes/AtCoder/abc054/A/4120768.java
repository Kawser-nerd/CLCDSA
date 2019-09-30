import java.util.*;
import java.io.*;

public class Main {

    private static FastScanner sc = new FastScanner();
    private static Solution solution = new Solution();

    public static void main(String[] args) {

        int a = sc.nextInt();
        int b = sc.nextInt();


        if(a==b){
            System.out.println("Draw");
        }else if(a==1){
            System.out.println("Alice");
        }else if(b==1){
            System.out.println("Bob");
        }else if(a>b){
            System.out.println("Alice");
        }else{
            System.out.println("Bob");
        }

    }
}

class Solution {
    public String stringLCS(String s1,String s2){//??????????????
        int l1 = s1.length();//s1???
        int l2 = s2.length();//s2???
        StringBuilder ans = new StringBuilder();
        int last = 0;
        if(l1==0||l2==0){
            return ans.toString();
        }

        int[][] m = new int[l1][l2];
        int maxLen = 0;

        for(int i = 0;i < l1;i++){
            if(s1.charAt(i)==s2.charAt(0)){
                m[i][0] = 1;
                maxLen = 1;
            }else{
                m[i][0] = 0;
            }
        }

        for(int i = 0;i < l2;i++){
            if(s1.charAt(0)==s2.charAt(i)){
                m[0][i] = 1;
                maxLen = 1;
                last = i;
            }else{
                m[0][i] = 0;
            }
        }

        for(int i = 1;i < l1;i ++){
            for(int j = 1;j < l2;j ++){
                if(s1.charAt(i)!=s2.charAt(j)){
                    m[i][j] = 0;
                }else{
                    m[i][j] = m[i-1][j-1] + 1;
                    if(m[i][j] > maxLen){
                        maxLen = m[i][j];
                        last = i;
                    }
                }
            }
        }

        for(int i = last - maxLen +1;i <= last;i++){
            ans.append(String.valueOf(s1.charAt(i)));
        }

        return ans.toString();

    }
    public int countLCS(String s1,String s2){//????????? ??????
        int l1 = s1.length();//s1???
        int l2 = s2.length();//s2???
        if(l1==0||l2==0){
            return 0;
        }

        int[][] m = new int[l1][l2];
        int maxLen = 0;

        for(int i = 0;i < l1;i++){
            if(s1.charAt(i)==s2.charAt(0)){
                m[i][0] = 1;
                maxLen = 1;
            }else{
                m[i][0] = 0;
            }
        }

        for(int i = 0;i < l2;i++){
            if(s1.charAt(0)==s2.charAt(i)){
                m[0][i] = 1;
                maxLen = 1;
            }else{
                m[0][i] = 0;
            }
        }

        for(int i = 1;i < l1;i ++){
            for(int j = 1;j < l2;j ++){
                if(s1.charAt(i)!=s2.charAt(j)){
                    m[i][j] = 0;
                }else{
                    m[i][j] = m[i-1][j-1] + 1;
                    maxLen = m[i][j] > maxLen?m[i][j]:maxLen;
                }
            }
        }
        return maxLen;


    }

    public List<Integer> prime_factorization(int n){//????????????n=12...2,2,3
        final List<Integer> list = new ArrayList<Integer>();
        if(n < 2){
            return list;
        }

        while(n!=1&&n%2==0){
            list.add(2);
            n >>>= 1;
        }

        for(int i = 3;i*i<n;i+=2){
            while(n%i==0){
                list.add(i);
                n/=i;
            }
        }
        if(n!=1){
            list.add(n);
        }
        return list;
    }

    public int count_divisor(int n) {//???????
        final List<Integer> list = new ArrayList<Integer>();
        int count = 1;
        int temp;
        if (n < 2) {
            return count;
        }

        temp = 0;
        while (n != 1 && n % 2 == 0) {
            temp++;
            n >>>= 1;
        }
        count *= temp + 1;


        for (int i = 3; i * i < n; i += 2) {
            temp = 0;
            while (n % i == 0) {
                temp++;
                n /= i;
            }
            count *= temp + 1;
        }
        if (n != 1) {
            count*=2;
        }
        return count;
    }
}

class FastScanner extends PrintWriter {
    private final InputStream in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    FastScanner() {
        this(System.in);
    }

    FastScanner(InputStream source) {
        super(System.out);
        this.in = source;
    }

    boolean hasNextByte() {
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

    int readByte() {
        if (hasNextByte()) return buffer[ptr++];
        else return -1;
    }

    boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    boolean isNewLine(int c) {
        return c == '\n' || c == '\r';
    }

    void skipUnprintable() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
    }

    void skipNewLine() {
        while (hasNextByte() && isNewLine(buffer[ptr])) ptr++;
    }

    boolean hasNext() {
        skipUnprintable();
        return hasNextByte();
    }

    boolean hasNextLine() {
        skipNewLine();
        return hasNextByte();
    }

    String next() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    char[] nextCharArray(int len) {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        char[] s = new char[len];
        int i = 0;
        int b = readByte();
        while (isPrintableChar(b)) {
            if (i == len) {
                throw new InputMismatchException();
            }
            s[i++] = (char) b;
            b = readByte();
        }
        return s;
    }

    String nextLine() {
        if (!hasNextLine()) {
            throw new NoSuchElementException();
        }
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (!isNewLine(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    long nextLong() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
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
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }

    int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) {
            throw new NumberFormatException();
        }
        return (int) nl;
    }

    char nextChar() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        return (char) readByte();
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }

    int[] arrayInt(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = nextInt();
        return a;
    }

    long[] arrayLong(int n) {
        long[] a = new long[n];
        for (int i = 0; i < n; i++) a[i] = nextLong();
        return a;
    }

    double[] arrayDouble(int n) {
        double[] a = new double[n];
        for (int i = 0; i < n; i++) a[i] = nextDouble();
        return a;
    }

    void arrayInt(int[]... a) {
        for (int i = 0; i < a[0].length; i++) for (int j = 0; j < a.length; j++) a[j][i] = nextInt();
    }

    int[][] matrixInt(int n, int m) {
        int[][] a = new int[n][];
        for (int i = 0; i < n; i++) a[i] = arrayInt(m);
        return a;
    }

    char[][] charMap(int n, int m) {
        char[][] a = new char[n][];
        for (int i = 0; i < n; i++) a[i] = nextCharArray(m);
        return a;
    }

    public void close() {
        super.close();
        try {
            in.close();
        } catch (IOException ignored) {
        }
    }
}