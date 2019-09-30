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

    class Attack{
    	int d,n,w,s,e;
    	final int dd,dp,ds;
    	public Attack(int d,int n,int w,int e,int s,int dd,int dp,int ds){
    		this.d=d;
    		this.n=n;
    		this.w=w;
    		this.e=e;
    		this.s=s;
    		this.dd=dd;
    		this.dp=dp;
    		this.ds=ds;
		}
    }

	StringBuilder res;
    public void run(){
    	int c=sc.nextInt();
    	StringBuilder sb=new StringBuilder();
    	for(int i=1;i<=c;i++){
    		int N=sc.nextInt();
    		int[] wall=new int[40000];//.5も用意する。

    		Attack[] at=new Attack[N];
    		for(int j=0;j<N;j++){
    			at[j]=new Attack(sc.nextInt(), sc.nextInt(), sc.nextInt(),
    					sc.nextInt(),sc.nextInt(), sc.nextInt(),sc.nextInt(),sc.nextInt());
        	}

    		PriorityQueue<Attack> que=new PriorityQueue<>(1,new Comparator<Attack>(){
    			@Override
    			public int compare(Attack a0, Attack a1) {
    				return a0.d-a1.d;
    			}
			});
    		for(Attack a:at){
        		que.add(a);
    		}

    		long suc=0;
    		int nowd=-1;
			int[] tmpwall=Arrays.copyOf(wall,wall.length);
    		while(!que.isEmpty()){
    			Attack a=que.poll();
    			if(nowd<a.d){
    				wall=tmpwall;
    				tmpwall=Arrays.copyOf(wall,wall.length);
    				nowd=a.d;
    			}
    			boolean isOK=false;
    			for(int x=a.w*2;x<=a.e*2;x++){
    				if(wall[20000+x]<a.s){
    					tmpwall[20000+x]=max(a.s,tmpwall[20000+x]);
    					isOK=true;
    				}
    			}
    			if(isOK)suc++;
    			a.d+=a.dd;
    			a.n--;
    			a.s+=a.ds;
    			a.w+=a.dp;a.e+=a.dp;
    			if(a.n>0)que.add(a);
    		}
    		//最小回数から多分2,3回で到達可能になる？

     		ln("Case #"+i+": "+suc);
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