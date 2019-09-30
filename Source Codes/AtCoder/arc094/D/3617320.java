import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args){
	new Main().run();
    }
    
    final long mo=998244353;

    void run(){
	Scanner sc=new Scanner(System.in);
	String s=sc.next();
	int n=s.length();
	if(n<=3){
	    System.out.println(f(s));
	    return;
	}
	{
	    boolean flag=true;
	    for(int i=0;i+1<s.length();++i){
		flag&=s.charAt(i)==s.charAt(i+1);
	    }
	    if(flag){
		System.out.println(1);
		return;
	    }
	}
	int sum=0;
	for(char c:s.toCharArray()){
	    if(c=='a'){
		sum+=0;
	    }else if(c=='b'){
		sum+=1;
	    }else if(c=='c'){
		sum+=2;
	    }
	    sum%=3;
	}
	long[][][][] dp=new long[n][3][3][2];//[??-1][sum][??][flag=?????]
	dp[0][0][0][0]=1;
	dp[0][1][1][0]=1;
	dp[0][2][2][0]=1;
	for(int i=1;i<n;++i){
	    for(int j=0;j<3;++j){//sum
		for(int k=0;k<3;++k){//??????
		    for(int m=0;m<3;++m){//?????
			for(int l=0;l<2;++l){
			    dp[i][(j+m)%3][m][l|(k==m?1:0)]+=dp[i-1][j][k][l];
			    dp[i][(j+m)%3][m][l|(k==m?1:0)]%=mo;
			}
		    }
		}
	    }
	}
	long ans=0;
	for(int i=0;i<3;++i){
	    ans+=dp[n-1][sum][i][1];
	}
	{
	    boolean flag=true;
	    for(int i=0;i+1<s.length();++i){
		flag&=s.charAt(i)!=s.charAt(i+1);
	    }
	    if(flag)++ans;
	}
	ans%=mo;
	System.out.println(ans);
    }

    long f(String str){
	int[] strn=new int[str.length()];
	for(int i=0;i<str.length();++i){
	    strn[i]=(int)(str.charAt(i)-'a');
	}
	class S{
	    int[] cs;
	    int num=0;
	    
	    S(int[] cs_){
		cs=Arrays.copyOf(cs_,cs_.length);
		long p=1;
		for(int c:cs){
		    num=(int)((num+c*p)%mo);
		    p=p*3%mo;
		}
	    }
	}
	boolean[] a=new boolean[81];
	ArrayDeque<S> dq=new ArrayDeque<S>();
	S src=new S(strn);
	dq.add(src);
	while(!dq.isEmpty()){
	    S s=dq.pollLast();
	    a[s.num]=true;
	    for(int i=0;i+1<s.cs.length;++i){
		if(s.cs[i]!=s.cs[i+1]){
		    int next=(3-(s.cs[i]+s.cs[i+1])%3)%3;
		    int tmp1=s.cs[i];
		    int tmp2=s.cs[i+1];
		    s.cs[i]=next;
		    s.cs[i+1]=next;
		    if(!a[new S(s.cs).num]){
			dq.addFirst(new S(s.cs));
			a[new S(s.cs).num]=true;
		    }
		    s.cs[i]=tmp1;
		    s.cs[i+1]=tmp2;
		}
	    }
	}
	long ans=0;
	for(int i=0;i<a.length;++i){
	    if(a[i])++ans;
	}
	return ans;
    }
    
}