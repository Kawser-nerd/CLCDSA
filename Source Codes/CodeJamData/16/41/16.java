import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class A {

    String doit(char c,int deep){
        if(deep==0)
            return new String(""+c);
        switch (c){
            case 'S': {
                String s1=doit('P', deep - 1);
                String s2=doit(c, deep - 1);
                if(s1.compareTo(s2)<0)return s1+s2;
                else return s2+s1;
            }
            case 'P': {

                String s1 = doit('R', deep - 1);
                String s2 = doit(c, deep - 1);
                if (s1.compareTo(s2) < 0) return s1 + s2;
                else return s2 + s1;
            }
            case 'R':{
                String s1 = doit('S', deep - 1);
                String s2 = doit(c, deep - 1);
                if (s1.compareTo(s2) < 0) return s1 + s2;
                else return s2 + s1;
            }
        }
        return new String();
    }

    boolean check(String q,int r,int p,int s){
        for(int i=0;i<q.length();i++){
            switch (q.charAt(i)){
                case 'S':
                    s--;
                    break;
                case 'R':
                    r--;
                    break;
                case 'P':
                    p--;
                    break;
            }
        }
        return (s==0&&r==0&&p==0);
    }

    void solve() throws IOException {
        int t=nextInt();
        for(int testCase=0;testCase<t;testCase++){
            int n=nextInt();
            int r=nextInt();
            int p=nextInt();
            int s=nextInt();
            String q1=doit('S',n).toString();
            String q2=doit('R',n).toString();
            String q3=doit('P',n).toString();
            String res="";
            if(check(q1,r,p,s))res=q1;
            if(check(q2,r,p,s))
                if(res.equals("")||res.compareTo(q2)>0)res=q2;
            if(check(q3,r,p,s))
                if(res.equals("")||res.compareTo(q3)>0)res=q3;
            if(res.equals(""))res="IMPOSSIBLE";
            out.printf("Case #%d: %s\n",testCase+1,res);

        }

    }

    public static void main(String[] args) throws IOException {
        new A().run();
    }

    void run() throws IOException {
        reader = new BufferedReader(new InputStreamReader(System.in));
		reader = new BufferedReader(new FileReader("input.txt"));
        tokenizer = null;
        out = new PrintWriter(new OutputStreamWriter(System.out));
		out = new PrintWriter(new FileWriter("output.txt"));
        solve();
        reader.close();
        out.flush();

    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}
