import java.io.*;
import java.util.*;

public class Main {

	static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            try {
                br = new BufferedReader(new InputStreamReader(System.in));
                st = new StringTokenizer(br.readLine());
            } catch (Exception e){e.printStackTrace();}
        }

        public String next() {
            if (st.hasMoreTokens()) return st.nextToken();
            try {st = new StringTokenizer(br.readLine());}
            catch (Exception e) {e.printStackTrace();}
            return st.nextToken();
        }

        public int nextInt() {return Integer.parseInt(next());}

        public long nextLong() {return Long.parseLong(next());}

        public double nextDouble() {return Double.parseDouble(next());}

        public String nextLine() {
            String line = "";
            if(st.hasMoreTokens()) line = st.nextToken();
            else try {return br.readLine();}catch(IOException e){e.printStackTrace();}
            while(st.hasMoreTokens()) line += " "+st.nextToken();
            return line;
        }
    }

	public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        PrintWriter pw = new PrintWriter(System.out);

        String s = sc.nextLine();
        int k = s.length();

        while(k > 0) {
            if(k >= 5 && s.substring(k-5, k).equals("dream")) {
                k -= 5;
            }
            else if(k >= 7 && s.substring(k-7, k).equals("dreamer")) {
                k -= 7;
            }
            else if(k >= 5 && s.substring(k-5, k).equals("erase")) {
                k -= 5;
            }
            else if(k >= 6 && s.substring(k-6, k).equals("eraser")) {
                k -= 6;
            }
            else {
                pw.println("NO");
                pw.close();
                return;
            }
        }

        pw.println("YES");
        pw.close();
	}

}

// dream, dreamer, erase, eraser