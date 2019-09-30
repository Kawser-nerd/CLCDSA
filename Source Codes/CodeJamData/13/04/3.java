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
			inputStream = new FileInputStream("taskd.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("taskd.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		MyScanner in = new MyScanner(inputStream);
		MyPrintWriter out = new MyPrintWriter(outputStream);
		TaskD solver = new TaskD();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskD {
    int T = 201;
    public void solve(int testNumber, MyScanner in, MyPrintWriter out) {
        out.printFormat("Case #%d: ",testNumber);
        int K = in.nextInt(), N = in.nextInt();
        int[] init = new int[K];
        for(int i=0;i<K;i++)init[i] = in.nextInt();
        int[] lock = new int[N];
        int[][] key = new int[N][];
        for (int i = 0; i < N; i++){
            lock[i] = in.nextInt();
            key[i] = new int[in.nextInt()];
            for (int j = 0; j < key[i].length; j++)key[i][j] = in.nextInt();
        }
        int[] last = new int[T];
        for(int i:init)last[i]++;
        for(int i:lock)last[i]--;
        for(int[] i:key)for(int j:i)last[j]++;
        for(int i:last)if(i<0){
            out.println("IMPOSSIBLE");
            return;
        }
        boolean[] used = new boolean[N];
        int[] has = new int[T];
        for(int i:init)has[i]++;
        if(!possible(used,has,lock,key)){
            out.println("IMPOSSIBLE");
            return;
        }
        int[] res = new int[N];
        for(int i=0;i<N;i++){
            for(int j=0;;j++){
                if(j>=N)throw new AssertionError();
                if(used[j])continue;
                if(has[lock[j]]<=0)continue;
                has[lock[j]]--;
                for(int k:key[j])has[k]++;
                used[j]=true;
                if(possible(used,has,lock,key)){
                    res[i]=j;break;
                }
                has[lock[j]]++;
                for(int k:key[j])has[k]--;
                used[j]=false;
            }
        }
        for (int i = 0; i < res.length; i++){
            out.printFormat("%d%c",res[i]+1,i==res.length-1?'\n':' ');
        }
    }

    private boolean possible(boolean[] used, int[] has, int[] lock, int[][] key) {
        int N = used.length;
        ListInt[] graph = new ListInt[T];
        for(int i=0;i<N;i++)if(!used[i]){
            if(graph[lock[i]] == null)graph[lock[i]] = new ListInt();
            for(int j:key[i])graph[lock[i]].add(j);
        }
        QueueInt que = new QueueInt();
        boolean[] visited = new boolean[T];
        for(int i=0;i<T;i++)if(has[i]>0){
            que.offer(i);
            visited[i] = true;
        }
        while(!que.isEmpty()){
            int i = que.poll();
            if(graph[i] == null)continue;
            for(IntIterator it = graph[i].iterator();it.hasNext();){
                int j = it.next();
                if(!visited[j]){
                    que.offer(j);
                    visited[j] = true;
                }
            }
        }
        for(int i=0;i<N;i++)if(!used[i] && !visited[lock[i]])return false;
        return true;
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

    public int nextInt() {
        int c = read();
        if (c == -1) throw new NoSuchElementException();
        while (c != '-' && (c < '0' || '9' < c)) {
            c = read();
            if (c == -1) throw new NoSuchElementException();
        }
        if (c == '-') return -nextInt();
        int res = 0;
        do {
            res *= 10;
            res += c - '0';
            c = read();
        } while ('0' <= c && c <= '9');
        return res;
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

    public void println(Object... os) {
        for (int i = 0; i < os.length - 1; i++) {
            out.print(os[i]);
            out.print(' ');
        }
        out.println(os[os.length - 1]);
    }

    public void close() {
        out.close();
    }

    public void printFormat(String format, Object... args) {
        out.printf(format,args);
    }

}

class ListInt {
    int[] data;
    int size;

    public ListInt() {
        this(4);
    }

    public ListInt(int initCapacity) {
        initCapacity = Math.max(1, initCapacity);
        data = new int[initCapacity];
        size = 0;
    }

    public void add(int value) {
        if (size >= data.length) {
            int[] nData = new int[data.length * 2];
            System.arraycopy(data, 0, nData, 0, data.length);
            data = nData;
        }
        data[size++] = value;
    }

    public int get(int i) {
        if (i >= size) throw new IndexOutOfBoundsException(String.format("size = %d, i = %d", size, i));
        return data[i];
    }

    public IntIterator iterator(){
        return new IntIterator() {
            int i = 0;
            public boolean hasNext() {
                return i < size;
            }

            public int next() {
                return get(i++);
            }
        };
    }
}

class QueueInt {
    private int[] data;
    private int from = 0, to = 0;
    private int size = 0;
    public QueueInt(int initCapacity){
        data = new int[initCapacity];
    }
    public QueueInt(){
        this(4);
    }
    public void offer(int value){
        if(size == data.length){
            int[] newData = new int[data.length * 2];
            for(int i=0;i<size;i++){
                int j = i+from;
                if(j>=size)j-=size;
                newData[i] = data[j];
            }
            from=0;
            to=size;
            data = newData;
        }
        data[to++] = value;
        if(to >= data.length)to = 0;
        size++;
    }
    public int poll(){
        if(size==0)throw new EmptyQueueException();
        int res = data[from++];
        if(from >= data.length)from = 0;
        size--;
        return res;
    }
    public boolean isEmpty(){
        return size == 0;
    }
    }

interface IntIterator {
    boolean hasNext();
    int next();
}

class EmptyQueueException extends RuntimeException {
}

