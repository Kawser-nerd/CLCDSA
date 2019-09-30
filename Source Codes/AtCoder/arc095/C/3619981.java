import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args){
	new Main().run();
    }
    
    void run(){
	Scanner sc=new Scanner();
	int H=sc.nextInt();
	int W=sc.nextInt();
	char[][] map=new char[H][W];
	for(int i=0;i<H;++i){
	    map[i]=sc.next().toCharArray();
	}
	int[] bind=new int[W];
	Arrays.fill(bind,-1);
	System.out.println(func(map,bind,0,W,W%2==1)?"YES":"NO");
    }

    boolean func(char[][] map,int[] bind,int pos,int res,boolean odd){
	if(res==0){
	    return calc(map,bind);
	}
	while(pos<bind.length&&bind[pos]!=-1)
	    ++pos;
	boolean ret=false;
	if(odd){
	    bind[pos]=pos;
	    ret|=func(map,bind,pos+1,res-1,false);
	    bind[pos]=-1;
	}
	for(int i=pos+1;i<bind.length;++i){
	    if(bind[i]!=-1)continue;
	    bind[pos]=i;
	    bind[i]=pos;
	    ret|=func(map,bind,pos+1,res-2,odd);
	    bind[pos]=-1;
	    bind[i]=-1;
	}
	return ret;
    }

    boolean calc(char[][] map,int[] bind){
	int H=map.length;
	int W=map[0].length;
	boolean[] used=new boolean[H];
	for(int i=0;i<H;++i){
	    if(used[i])continue;
	    for(int j=i+1;j<H;++j){
		if(used[j])continue;
		boolean flag=true;
		for(int k=0;k<W;++k){
		    flag&=map[i][k]==map[j][bind[k]];
		}
		if(flag){
		    used[i]=true;
		    used[j]=true;
		    break;
		}
	    }
	}
	for(int i=0;H%2==1&&i<H;++i){
	    if(used[i])continue;
	    boolean flag=true;
	    for(int j=0;j<W;++j){
		flag&=map[i][j]==map[i][bind[j]];
	    }
	    if(flag){
		used[i]=true;
		break;
	    }
	}
	int cnt=0;
	for(int i=0;i<H;++i){
	    if(used[i])++cnt;
	}
	return cnt==H;
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