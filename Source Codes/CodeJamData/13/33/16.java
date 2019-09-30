import java.io.*;
import java.util.*;
import java.lang.*;

class Tribe{
	public int d,n,w,e,s,dd,dp,ds;
	public Tribe(int d2,int n2,int w2,int e2,int s2,int dd2,int dp2,int ds2){
		d=d2;n=n2;w=w2;e=e2;s=s2;dd=dd2;dp=dp2;ds=ds2;
	}
}

public class C_1C {
    
    public static void main(String[] args) {
		try 
		{
			Scanner s = new Scanner(new File("C-small-attempt0.in"));
			
			FileOutputStream out = new FileOutputStream(new File("lawn2.txt"));
			PrintStream p = new PrintStream(out);
			int num=s.nextInt();
			for(int n=1;n<=num;n++){
				Tribe [] tribes=new Tribe [s.nextInt()];
				for(int i=0;i<tribes.length;i++)
					tribes[i]=new Tribe(s.nextInt(),s.nextInt(),s.nextInt(),s.nextInt(),s.nextInt(),s.nextInt(),s.nextInt(),s.nextInt());
				int [] wall=new int[4000];
				int attacks=0;
				for(int i=0;i<676060+1000;i++){
					for(int j=0;j<tribes.length;j++){
						if(tribes[j].n>0&&i==tribes[j].d&&tribes[j].s>0)
						{
							for(int i2=tribes[j].w;i2<tribes[j].e;i2++){
								if(wall[i2+2000]<tribes[j].s)
								{
									attacks++;
									break;
								}
							}
						}
					}
					for(int j=0;j<tribes.length;j++){
						if(tribes[j].n>0&&i==tribes[j].d&&tribes[j].s>0)
						{
							for(int i2=tribes[j].w;i2<tribes[j].e;i2++){
								if(wall[i2+2000]<tribes[j].s)
								{
									wall[i2+2000]=tribes[j].s;
								}
							}
							tribes[j].n--;
							tribes[j].d+=tribes[j].dd;
							tribes[j].s+=tribes[j].ds;
							tribes[j].w+=tribes[j].dp;
							tribes[j].e+=tribes[j].dp;
						}
					}
				}
				p.println("Case #"+n+": "+attacks);
			}
			p.close();
		}
		catch(IOException e)
		{
			System.out.println("There was a problem:" + e);
		
		}
    }
}
