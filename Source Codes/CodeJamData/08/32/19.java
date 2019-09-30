
import java.io.*;
import java.math.BigInteger;
public class P2 {
	public static int N;
	public static String s="";
	public static int Case=0;
	public static int[][][][][] seen=new int[51][2][3][5][7];
	public static long[][][][][] M=new long[51][2][3][5][7];
	public static int len;
	public static BigInteger bigthree=new BigInteger("33333333333333333333333333333333333333333333333333");
	public static BigInteger bigtwo=new BigInteger("22222222222222222222222222222222222222222222222222");
	public static BigInteger bigfive=new BigInteger("55555555555555555555555555555555555555555555555555");
	public static BigInteger bigseven=new BigInteger("77777777777777777777777777777777777777777777777777");
	
	public static BigInteger three=new BigInteger(""+3);
	public static BigInteger two=new BigInteger(""+2);
	public static BigInteger five=new BigInteger(""+5);
	public static BigInteger seven=new BigInteger(""+7);
	public static long solve(int start,int p2,int p3,int p5,int p7){
		if(start>=len){
			if(p2==0) return 1;
			if(p3==0) return 1;
			if(p5==0) return 1;
			if(p7==0) return 1;
			return 0;
		}
		if(seen[start][p2][p3][p5][p7]==Case) return M[start][p2][p3][p5][p7];
		seen[start][p2][p3][p5][p7]=Case;
		String num="";
		long ans=0;
		if(start==0){
		   for(int i=start;i<len;i++){
			   num+=s.charAt(i);
			   BigInteger bi=new BigInteger(num);
			   BigInteger temp=new BigInteger(bi.toString());
			   int mod2=Integer.parseInt(temp.add(new BigInteger(""+p2)).mod(two).toString());
			   temp=new BigInteger(bi.toString());
			   int mod3=Integer.parseInt(temp.add(new BigInteger(""+p3)).mod(three).toString());
			   temp=new BigInteger(bi.toString());
			   int mod5=Integer.parseInt(temp.add(new BigInteger(""+p5)).mod(five).toString());
			   temp=new BigInteger(bi.toString());
			   int mod7=Integer.parseInt(temp.add(new BigInteger(""+p7)).mod(seven).toString());
			   ans+=solve(i+1,mod2,mod3,mod5,mod7);
		   }
		}
		else{
		   for(int i=start;i<len;i++){
			   num+=s.charAt(i);
			   BigInteger bi=new BigInteger(num);
			   BigInteger temp=new BigInteger(bi.toString());
			   int mod2=Integer.parseInt(temp.add(new BigInteger(""+p2)).mod(two).toString());
			   temp=new BigInteger(bi.toString());
			   int mod3=Integer.parseInt(temp.add(new BigInteger(""+p3)).mod(three).toString());
			   temp=new BigInteger(bi.toString());
			   int mod5=Integer.parseInt(temp.add(new BigInteger(""+p5)).mod(five).toString());
			   temp=new BigInteger(bi.toString());
			   int mod7=Integer.parseInt(temp.add(new BigInteger(""+p7)).mod(seven).toString());
			   ans+=solve(i+1,mod2,mod3,mod5,mod7);
			   
			   
			   BigInteger p22=new BigInteger(""+p2).add(bigtwo);
			   mod2=Integer.parseInt(p22.subtract(bi).mod(two).toString());
			   
			   BigInteger p33=new BigInteger(""+p3).add(bigthree);
			   mod3=Integer.parseInt(p33.subtract(bi).mod(three).toString());
			   
			   BigInteger p55=new BigInteger(""+p5).add(bigfive);
			   mod5=Integer.parseInt(p55.subtract(bi).mod(five).toString());
			   
			   BigInteger p77=new BigInteger(""+p7).add(bigseven);
			   mod7=Integer.parseInt(p77.subtract(bi).mod(seven).toString());
			   ans+=solve(i+1,mod2,mod3,mod5,mod7);
			   
			   
		   }
		}
		return M[start][p2][p3][p5][p7]=ans;
	}
	public static void main(String[] args) throws Exception{
		DataInputStream in=new DataInputStream(System.in);
		int T=Integer.parseInt(in.readLine());
	    Case=1;
		while(T!=0){
			s=in.readLine();
			len=s.length();
			System.out.println("Case #"+Case+": "+solve(0,0,0,0,0));
			Case++;
			T--;
		}
	}
}
