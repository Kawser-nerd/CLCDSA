import java.io.*;
import java.util.*;
import java.math.*;
public class B2 {
	public static Scanner scan = null;
	public static Scanner scan2 = null;
	public static PrintWriter out = null;
	public static boolean bg = false;
	public static int no = 6;
	public static ArrayList<Long> cum1x = new ArrayList();
	public static ArrayList<Long> cum2x = new ArrayList();
	public static ArrayList<Long> cum = new ArrayList();
	public static ArrayList<Long> cum1 = new ArrayList();
	public static ArrayList<Long> cum2 = new ArrayList();
	static{
		try {
			scan2 = new Scanner(System.in);
			scan = new Scanner(new FileReader("input"+no+".txt"));
			out = new PrintWriter(new File("output"+no+".txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		for (long i=0;i<8000;i++){
			long temp = i*(i+1)/2;
			if (temp%2==0){
				cum2.add(temp);
				cum2x.add(i);
			}
			else {
				cum1.add(temp);
				cum1x.add(i);
			}
			cum.add(temp);
		}
	}
	public static void main(String[] args){
		if (bg) System.out.println(cum1);
		if (bg) System.out.println(cum2);
		if (bg) System.out.println(cum1x);
		if (bg) System.out.println(cum2x);
		int t = Integer.parseInt(scan.next());
		for (int count = 0;count<t;count++){
			long x = Integer.parseInt(scan.next());
			long y = Integer.parseInt(scan.next());
			if (bg) System.out.println("x y "+x+" "+y);
			long k1 = (long)(Math.abs(x)+Math.abs(y));
			int id = -1;
			long can = -1;
			if (k1%2==0){
				id = Collections.binarySearch(cum2, k1);
				if (id <0){
					id = -id-1;
				}
				can = cum2x.get(id);
			}
			else {
				id = Collections.binarySearch(cum1, k1);
				if (id <0){
					id = -id-1;
				}
				can = cum1x.get(id);
			}
			
			if (bg) System.out.println("can "+can);
			
			
			
			long[] cor = {x,y};
			List<Character> seq1 = new ArrayList();
			while (true){
				if (bg){
					System.out.println("can "+can);
					System.out.println("cor "+Arrays.toString(cor));
					System.out.println("seq1 "+seq1);
				}
				//System.out.println("cor "+Arrays.toString(cor));
				if (can==0){
					break;
				}
				long bound = cum.get((int)can-1);
				long temp = (long)(Math.abs(cor[0]-can)+Math.abs(cor[1]));
				temp = (long)(Math.abs(cor[0]-can)+Math.abs(cor[1]));
				if (temp<=bound
						&&(temp-bound)%2==0){
					long[] w1 = new long[]{cor[0]-can,cor[1]};
					cor = w1;
					seq1.add('E');
					can--;
					continue;
				}
				temp = (long)(Math.abs(cor[0])+Math.abs(cor[1]-can));
				if (temp<=bound
						&&(temp-bound)%2==0){
					long[] w1 = new long[]{cor[0],cor[1]-can};
					cor = w1;
					seq1.add('N');
					can--;
					continue;
				}
				temp = (long)(Math.abs(cor[0])+Math.abs(cor[1]+can));
				if (temp<=bound
						&&(temp-bound)%2==0){
					long[] w1 = new long[]{cor[0],cor[1]+can};
					cor = w1;
					seq1.add('S');
					can--;
					continue;
				}
				temp = (int)(Math.abs(cor[0]+can)+Math.abs(cor[1]));
				if (temp<=bound
						&&(temp-bound)%2==0){
					long[] w1 = new long[]{cor[0]+can,cor[1]};
					cor = w1;
					seq1.add('W');
					can--;
					continue;
				}
				
			}
			StringBuilder ans1 =new StringBuilder();
			for (int j = seq1.size()-1;j>=0;j--){
				ans1.append(seq1.get(j));
			}
			System.out.println("Case #"+(count+1)+": "+ans1.toString());
			out.println("Case #"+(count+1)+": "+ans1.toString());
			out.flush();
			//scan2.next();
		}
	}
}
