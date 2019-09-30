import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;


public class Task3 {
	public static class CumulativeTable 
	{
		private int [] sum;
		private int [] degreeTwo;
		private int n;
		
		public CumulativeTable(int n)
		{
			this.n = n;
			this.sum = new int [n + 1];
			this.degreeTwo = new int [n + 1];
			calculateDegrees();
		}
		
		private void calculateDegrees()
		{
			degreeTwo [0] = 1;
			degreeTwo [1] = 1;
			for (int i = 2; i <= n; i++)
			{
				if ((i & 1) == 0)
					degreeTwo [i] = degreeTwo [i >> 1] * 2;
				else
					degreeTwo [i] = 1;
			}
		}
		
		public void reset()
		{
			for (int i = 0; i < n; i++)
				sum [i] = 0;
		}
		
		public void add (int index, int value)
		{
			int i = index;
			while (i <= n)
			{
				sum [i] = sum [i] + value;
				i = i + degreeTwo [i];
			}
		}

		public int count (int index)
		{
			int i = index;
			int toReturn = 0;
			while (i >= 0)
			{
				toReturn = toReturn + sum [i];
				i = i - degreeTwo [i];
			}
			return toReturn;
		}

//		public static void main(String[] args) 
//		{
//			Random rnd = new Random ();
//			int n = 100;
//			int [] a = new int [n];
//			CumulativeTable ct = new CumulativeTable(n);
//			for (int i = 0; i < n; i++)
//				a [i] = 0;
//			for (int i = 0; i < 10; i++)
//			{
//				int index = rnd.nextInt(n);
//				int value = rnd.nextInt(1000);
//				a [index] = a [index] + value;
//				ct.add(index, value);
//				int sum = 0;
//				for (int j = 0; j <= index; j++)
//					sum += a [j];
//				System.out.println(sum);
//				System.out.println(ct.count(index));
//			}
//		}
		
	}

	
	public static int vr(int br, int tr, CumulativeTable kum) {
		int a = kum.count(br);
		if (a<tr) return -1;
		if (a>tr) return 1;
		if (kum.count(br-1)==tr)
			return 1;
		return 0;
	}
	
	public static void main(String[] args) {
		try {
			Scanner in = new Scanner(new BufferedInputStream(
					new FileInputStream("in.txt")));
			PrintStream out = new PrintStream(new BufferedOutputStream(
					new FileOutputStream("out.txt")));

			int TT = in.nextInt();
			for (int tt = 0; tt < TT; tt++) {
				int n = in.nextInt();
				CumulativeTable kum = new CumulativeTable(n+2);
				for(int i = 1;i<=n;i++)
					kum.add(i, 1);
				
				int[] karta = new int[n+2];
				int tr = 0;
				int left = 0;
				for(int i = 1;i<=n;i++)
				{							
					int right = n+1;
					tr = 1+(kum.count(left)+i-1)%(n-i+1);
					
					left = 0;
					while (left+1<right)
					{
						int mid = (left+right)>>1;
						int vr = vr(mid,tr,kum);
						if (vr==0)
						{
							left = mid;
							right = mid;
						}
						else if (vr==1)						
							right = mid;						
						else left = mid;
					}
					
					if (vr(left,tr,kum)<0)
						left++;
					
					karta[left] = i;
					kum.add(left, -1);
					tr--;
				}
//				System.out.println(Arrays.toString(karta));
//				System.out.println();				
				out.format("Case #%d:", 1 + tt);
				int c = in.nextInt();
				for(int i = 0;i<c;i++)
					out.format(" %d", karta[in.nextInt()]);
				out.println();
				

			}
			in.close();
			out.flush();
			out.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
