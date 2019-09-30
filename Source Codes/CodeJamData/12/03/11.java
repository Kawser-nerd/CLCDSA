import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) throws IOException {
		FileInputStream fis = new FileInputStream(new File("in.txt"));
		FileOutputStream fos = new FileOutputStream(new File("out.txt"));
		Scanner sc = new Scanner(fis);
		PrintWriter out = new PrintWriter(fos);
		int cases = sc.nextInt();
		for(int cs = 1; cs <= cases; cs++)
		{
			int begin = sc.nextInt();
			int end = sc.nextInt();
			int cnt = 0;
			for(int n=begin; n<=end; n++)
			{
				int weishu = getWeishu(n);
				int cur = getNext(n, weishu);
				while(cur != n)
				{
					if(cur > n && cur <=end && getWeishu(cur) == weishu)
						cnt++;
					cur = getNext(cur, weishu);
				}
			}
			out.println("Case #"+cs+": "+cnt);
		}
		sc.close();
		out.close();
	}
	public static int getNext(int n, int weishu)
	{
		//int weishu= getWeishu(n);
		return n%10*getTens(weishu-1)+n/10;
	}
	private static int getTens(int n) {
		int res = 1;
		for(int i=0; i<n; i++)
			res *= 10;
		return res;
	}
	private static int getWeishu(int n) {
		int weishu = 1;
		int nweishu = 10;
		while(n >= nweishu)
		{
			nweishu*=10;
			weishu++;
		}
		return weishu;
	}
}
