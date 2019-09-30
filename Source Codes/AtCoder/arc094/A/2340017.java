import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {

    public static void main(String[] args) throws IOException {
        init(System.in);
        int[] abc = new int[3];
        for (int i = 0; i < abc.length; i++) abc[i] = nextInt();
        Arrays.sort(abc);
        int diff1 = abc[2] - abc[0];
        int diff2 = abc[2] - abc[1];
        if (diff1 % 2 == 0 && diff2 % 2 == 0) System.out.println(diff1/2 + diff2/2);
        else if (diff1 % 2 == 1 && diff2 % 2 == 0) System.out.println(1 + diff2/2 + (diff1 + 1)/2);
        else if (diff1 % 2 == 0 && diff2 % 2 == 1) System.out.println(1 + diff1/2 + (diff2 + 1)/2);
        else System.out.println(1 + (diff1 - 1)/2 + (diff2 - 1)/2);
    }

    //Input Reader
    private static BufferedReader reader;
    private static StringTokenizer tokenizer;

    private static void init(InputStream inputStream) {
        reader = new BufferedReader(new InputStreamReader(inputStream));
        tokenizer = new StringTokenizer("");
    }

    private static String next() throws IOException {
        String read;
        while (!tokenizer.hasMoreTokens()) {
            read = reader.readLine();
            if (read == null || read.equals(""))
                return "-1";
            tokenizer = new StringTokenizer(read);
        }

        return tokenizer.nextToken();
    }

    private static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

//    private static long nextLong() throws IOException {
//        return Long.parseLong(next());
//    }
//
//    //    Get a whole line.
//    private static String line() throws IOException {
//        return reader.readLine();
//    }
//
//    private static double nextDouble() throws IOException {
//        return Double.parseDouble(next());
//    }
}