import java.util.Scanner;

public class Main {
	static long[][] dp = new long[19][2];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		//18?????orNot
		dpClear();
		long countb = count4and9(String.valueOf(b), 1);
		dpClear();
		long counta = count4and9(String.valueOf(a-1), 1);
		System.out.println((b-a+1)-(countb-counta));

	}

	static void dpClear() {
		for(int i=0;i<dp.length;i++) {
			for(int j=0;j<dp[i].length;j++) {
				dp[i][j]= -1;
			}
		}
	}

	static long count4and9(String stringB,int tight) {
		int topb = Integer.valueOf(stringB.substring(0, 1));
		long count=0;
		if(dp[stringB.length()-1][tight]!=-1) {
			return  dp[stringB.length()-1][tight];
		}
		else {
			if(stringB.length()==1) {
				for(int i=0;i<=(tight==1?topb:9);i++) {
					if(i==4|i==9) {
						continue;
					}
					count++;
				}
			}
			else {
				String nextb = stringB.substring(1);
				for(int i=0;i<=(tight==1?topb:9);i++) {
					if(i==4|i==9) {
						continue;
					}
					else {
						if(tight==1&topb==i) {
							count = count + count4and9(nextb,1);
						}
						else {
							count = count + count4and9(nextb,0);
						}
					}
				}
			}
			dp[stringB.length()-1][tight]=count;
			return count;
		}
	}

	static class Pair implements Comparable<Pair> {
	    long a,b;
	    public Pair(long a,long b) {
	        this.a = a;
	        this.b = b;
	    }

	    //(a,b)???
	    @Override
	    public boolean equals(Object o) {
	        if (o instanceof Pair) {
	            Pair p = (Pair) o;
	            return a == p.a && b == p.b;
	        }
	        return super.equals(o);
	    }

	    /*
	     * x.equals(y) ??? hashCode(x) == hashCode(y)??????????
	     * ??????????????????????????????????????????
	     */
//	    @Override
//	    public int hashCode() {
//	        return a ^ b;
//	    }

	    //?????
	    @Override
	    public int compareTo(Pair o) {
	        if (a != o.a) {
	            return Long.compare(a, o.a);
	        }
	        //???
	        return Long.compare(b, o.b);
	    }
	}

}