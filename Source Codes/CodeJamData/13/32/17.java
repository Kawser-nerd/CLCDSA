package round1C;
import static java.lang.System.*;
import static java.lang.Math.*;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class A{
    public static Scanner sc = new Scanner(in);
    public static Random rand=new Random();

    public static PrintWriter out;
    static{
    	try {
			out=new PrintWriter(new BufferedWriter(new FileWriter("C:\\Users\\shimomire\\Dropbox\\Project\\ProgramContest\\java\\GCJ\\res.out")));
		} catch (IOException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}
    }

    public boolean check(int x,int y, int t){
    	if(t==0){
    		return x==0 && y==0;
    	}
    	if(abs(x)<abs(y)){
    		if(y>0){
    			res.append("N");
    		}else{
    			res.append("S");
    		}
    		return check(x,y>0?y-t:y+t,t-1);
    	}else{
    		if(x>0){
    			res.append("E");
    		}else{
    			res.append("W");
    		}
    		return check(x>0?x-t:x+t,y,t-1);
    	}
    }

	StringBuilder res;
    public void run(){
    	int c=sc.nextInt();
    	StringBuilder sb=new StringBuilder();
    	for(long i=1;i<=c;i++){
    		int x=sc.nextInt(),y=sc.nextInt();
    		//int x=rand.nextInt(1000000),y=rand.nextInt(1000000);

    		res=new StringBuilder();
    		//最小回数から多分2,3回で到達可能になる？

    		int m=abs(x)+abs(y);

    		int j=0;
    		while(j*(j+1)<2*m)j++;

    		while(!check(x,y,j)){
    			res=new StringBuilder();
    			j++;
    		}

     		ln("Case #"+i+": "+res.reverse());
    	}

    	ln(sb);
    	out.close();
    }

    public static void main(String[] _) {
        new A().run();
    }

    public int[] nextIntArray(int n){
        int[] res=new int[n];
        for(int i=0;i<n;i++){
            res[i]=sc.nextInt();
        }
        return res;
    }
    public static void pr(Object o) {
    	out.print(o);
    }
    public static void ln(Object o) {
        out.println(o);
    }
    public static void ln() {
    	out.println();
    }

}