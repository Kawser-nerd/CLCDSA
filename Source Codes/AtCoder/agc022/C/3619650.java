import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args){
	new Main().run();
    }
    
    void run(){
	Scanner sc=new Scanner();
	int N=sc.nextInt();
	int[] a=new int[N];
	int[] b=new int[N];
	for(int i=0;i<N;++i){
	    a[i]=sc.nextInt();
	}
	for(int i=0;i<N;++i){
	    b[i]=sc.nextInt();
	}
	boolean[] need=new boolean[51];
	Arrays.fill(need,true);
	need[0]=false;
	if(!ok(need,a,b)){
	    System.out.println(-1);
	    return;
	}
	for(int i=50;i>=1;--i){
	    need[i]=false;
	    if(!ok(need,a,b)){
		need[i]=true;
	    }
	}
	long ans=0;
	for(int i=1;i<=50;++i){
	    if(need[i]){
		ans+=1L<<i;
	    }
	}
	System.out.println(ans);
    }

    boolean ok(boolean[] need,int[] a,int[] b){
	boolean[][] to=new boolean[51][51];
	int n=a.length;
	for(int i=0;i<n;++i){
	    to[a[i]][a[i]]=true;
	}
	for(int i=1;i<=50;++i){
	    if(!need[i])continue;
	    for(int j=0;j<=50;++j){
		to[j][j%i]=true;
	    }
	}
	for(int i=0;i<=50;++i){
	    for(int j=0;j<=50;++j){
		for(int k=0;k<=50;++k){
		    to[j][k]|=to[j][i]&&to[i][k];
		}
	    }
	}
	boolean ans=true;
	for(int i=0;i<n;++i){
	    ans&=to[a[i]][b[i]];
	}
	return ans;
    }


    void tr(Object...o){
	System.out.println(Arrays.deepToString(o));
    }
    
}


class Scanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        }else{
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
    private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
    private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
    private void skipUnprintable() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;}
    public boolean hasNext() { skipUnprintable(); return hasNextByte();}
    public String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while(isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    public long nextLong() {
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
        while(true){
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            }else if(b == -1 || !isPrintableChar(b)){
                return minus ? -n : n;
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }

    public int nextInt(){
	return (int)nextLong();
    }
}