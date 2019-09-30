import java.io.*;
import java.util.*;
public class b{
	long sol=0;
	String s;
	long nrt;
	long calc(int lop,long bef,long now){
		switch(lop){
		case 0: return now;
		case 1: return bef+now;
		case 2: return bef-now;
		}
		return 0;
	}
	boolean ugly(long x){
		if(x<0)x=-x;
		if(x%2==0)return true;
		if(x%3==0)return true;
		if(x%5==0)return true;
		if(x%7==0)return true;
		return false;
	}
	void count(int poz,int lop,long bef,long now){
		if(poz==s.length()-1){
			//if(nrt==2) System.err.prlongln(lop+" "+bef+" "+now+" "+ugly(calc(lop,bef,now)));
			if(ugly(calc(lop,bef,now))) sol++;
			else {}
			}
		else{
			long c=(long)(s.charAt(poz+1)-'0');
			count(poz+1,lop,bef,10*now+c);
			if(poz!=s.length()-1){
				count(poz+1,1,calc(lop,bef,now),c);
				count(poz+1,2,calc(lop,bef,now),c);
				}
		}
	
	}
	b(){
		try{
			File f = new File("B-small-attempt1.in");
			BufferedReader input =  new BufferedReader(new FileReader(f));
			BufferedWriter out = new BufferedWriter(new FileWriter("small.out"));
			long nrtests = Integer.parseInt(input.readLine());
			for(nrt=0;nrt<nrtests;nrt++){
				s=input.readLine();
				sol=0;
				count(0,0,0,(long)(s.charAt(0)-'0'));
				out.write("Case #"+(nrt+1)+": "+sol+"\n");
			}
			out.close();
		}catch(IOException e){}
	}
	public static void main(String[]args){
		new b();
	}

}