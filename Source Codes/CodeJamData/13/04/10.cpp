package cn.jds.GoogleCodeJam;

import java.math.BigInteger;
import java.util.Scanner;

public class TicTacToeTomek {
	
	static String[] r=new String[5000000];
	static String[] d=new String[10000000];
	static int count=0;		
	static int count1=0;
	static int bit=0;
	static int s=0;
	static int t=2;
	public static void main(String[] args){
		r[0]="1";
		r[1]="2";		
		count=2;
		int k=25;
		while(k>0){
			for(int i=s;i<t;i++){
				if(r[i].startsWith("2")){
					r[count]=r[i]+"0";
					count++;
					r[count]=r[i]+"1";
					count++;
					break;
				}
				if(r[i].endsWith("2"))continue;
				int t1=countt(r[i]);
				r[count]=r[i]+"0";
				count++;
				if(t1<5){
					r[count]=r[i]+"1";
					count++;
				}
				if(r[i].startsWith("2")==false)r[count]=r[i]+"2";
				count++;
			}
			s=t;
			t=count;
			k--;
		}
		d[0]="1";d[1]="4";d[2]="9";d[3]="121";d[4]="484";
		count1=5;
		int i=2,j=2;
		int bb=2;
		while(i<count){
			if(j>=count||r[j].length()>bb){
				for(int kk=i;kk<j;kk++){
					StringBuilder sb=new StringBuilder(r[kk]);
					for(k=0;k<r[kk].length();k++){
						sb.insert(r[kk].length(), r[kk].charAt(k));
					}
					BigInteger bi=new BigInteger(sb.toString());
					if(isb(bi.multiply(bi))){
						d[count1]=bi.multiply(bi).toString();
						count1++;
					}
				}
				i=j;
				bb++;
			}
			if(j>=count)break;
			StringBuilder sb=new StringBuilder(r[j]);
			for(k=0;k<r[j].length()-1;k++){
				sb.insert(r[j].length(), r[j].charAt(k));
			}
			BigInteger bi=new BigInteger(sb.toString());
			if(isb(bi.multiply(bi))){
				d[count1]=bi.multiply(bi).toString();
				count1++;
			}
			j++;			
		}
		//System.out.println(count1);
		Scanner in=new Scanner(System.in);
		int testCase=in.nextInt();
		for(i=0;i<testCase;i++){
			BigInteger low,up;
			low=in.nextBigInteger();
			up=in.nextBigInteger();
			int sum=0;
			for(j=0;j<count1;j++){
				BigInteger ttt=new BigInteger(d[j]);
				//System.out.println(ttt.toString());
				if(ttt.compareTo(up)==1)break;
				if(ttt.compareTo(low)<0){continue;}
				//System.out.println(ttt.toString());
				sum++;				
			}
			System.out.println("Case #"+(i+1)+": "+sum);
		}
//		for(i=0;i<count1;i++){
//			System.out.println(d[i]);
//		}
//		
		//for(int i=0;i<count;i++)System.out.println(r[i]);
	}
	private static boolean isb(BigInteger multiply) {
		String temp=multiply.toString();
		for(int i=0;i<temp.length()/2;i++)if(temp.charAt(i)!=temp.charAt(temp.length()-1-i))return false;
		return true;
	}
	private static int countt(String string) {
		// TODO Auto-generated method stub
		int temp = 0;
		for(int i=0;i<string.length();i++){
			if(string.charAt(i)=='1')temp++;
		}
		return temp;
	}
}

