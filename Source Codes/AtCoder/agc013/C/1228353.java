import java.io.*;
import java.util.*;

class MyInputStream extends InputStream {
	public BufferedInputStream bis = new BufferedInputStream(System.in);

	public int read() throws IOException {
		int i;
		while ((i = bis.read()) < 48)
			if (i == -1)
				return -1;
		int temp = 0;
		while (i > 47) {
			temp = temp * 10 + i - 48;
			i = bis.read();
		}
		return temp;
	}
}

public class Main {

	static final int N = 100005;
	static final int inf = 0x3f3f3f3f;
	static final double eps = 1e-6;
    static int a[]=new int[N];
	public static void main(String[] args) throws IOException{
	MyInputStream cin=new MyInputStream();
	int n=cin.read(),l=cin.read(),t=cin.read();
    int tmp,cnt=0,d;
    for(int i=0;i<n;i++){
        a[i]=cin.read();d=cin.read();
        if(d==1){
            tmp=a[i]+t;
            a[i]=tmp%l;
            cnt+=tmp/l;
        }else{
            tmp=a[i]-t;
            a[i]=tmp%l;
            cnt+=tmp/l;
            if(a[i]<0){
            	a[i]+=l;
            	cnt--;
            }
        }
    }
    Arrays.sort(a,0,n);
    cnt%=n;
    if(cnt<0) cnt+=n;
    cnt%=n;
    StringBuilder ans=new StringBuilder("");
    for(int i=cnt;i<cnt+n;i++){
    	int j=i%n;
    	System.out.println(a[j]);
    }
}
}