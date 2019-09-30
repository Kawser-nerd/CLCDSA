import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class Ceasy {

    int[] dx={1,0,-1,0};
    int[] dy={0,-1,0,1};

    void solve() throws IOException {
        int t=nextInt();
        for(int testCase=0;testCase<t;testCase++){
            int r=nextInt();
            int c=nextInt();
            int count=(r+c)*2;
            boolean[][] g=new boolean[count][count];
            for(int i=0;i<count;i+=2){
                int x=nextInt()-1;
                int y=nextInt()-1;
                g[x][y]=g[y][x]=true;
            }
            int maxMask=1<<(r*c);
            boolean veryGood=false;
            out.printf("Case #%d:\n",testCase+1);
            for(int mask=0;mask<maxMask;mask++){
                int[][] a=new int[r][c];
                for(int i=0;i<r;i++)
                    for(int j=0;j<c;j++){
                        int ind=i*c+j;
                        if((mask&(1<<ind))!=0)a[i][j]=1;
                    }
                boolean good=true;
                for(int i=0;i<count;i++) {
                    int iterations = 0;
                    int x,y,dir;
                    if(i<c){
                        x=0;
                        y=i;
                        dir=0;
                    }
                    else if(i<c+r){
                        y=c-1;
                        x=i-c;
                        dir=1;
                    }
                    else if(i<2*c+r){
                        y=2*c+r-i-1;
                        x=r-1;
                        dir=2;
                    }
                    else{
                        x=2*c+2*r-i-1;
                        y=0;
                        dir=3;
                    }
                    while(iterations<100){
                        iterations++;
                        if(x<0||x>=r||y<0||y>=c)break;
                        switch (dir){
                            case 0:
                                if(a[x][y]==0)dir=1;
                                else dir=3;
                                break;
                            case 1:
                                if(a[x][y]==0)dir=0;
                                else dir=2;
                                break;
                            case 2:
                                if(a[x][y]==0)dir=3;
                                else dir=1;
                                break;
                            case 3:
                                if(a[x][y]==0)dir=2;
                                else dir=0;
                        }
                        x+=dx[dir];
                        y+=dy[dir];
                    }
                    int res=0;
                    if(x<0)res=y;
                    if(y>=c)res=x+c;
                    if(x>=r)res=2*c+r-y-1;
                    if(y<0)res=2*r+2*c-x-1;
                    if(!g[i][res]){
                        good=false;
                        break;
                    }
                }
                if(good){
                    veryGood=true;
                    for(int i=0;i<r;i++) {
                        for (int j = 0; j < c; j++)
                            if (a[i][j]==0)out.print('/');
                        else out.print('\\');
                        out.println();
                    }

                    break;
                }

            }
            if(!veryGood)out.println("IMPOSSIBLE");
        }
    }

    public static void main(String[] args) throws IOException {
        new Ceasy().run();
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
