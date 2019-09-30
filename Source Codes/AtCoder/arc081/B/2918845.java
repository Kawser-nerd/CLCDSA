import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;
import java.io.BufferedOutputStream;
import java.io.BufferedWriter;
import java.io.OutputStream;
import java.math.BigInteger;
 
 
 public class Main {
	
	
	
 
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Reader.init(System.in);
		int n=Reader.nextInt();
		int[][] config=new int[2][n];
		String a=Reader.next();
		String b=Reader.next();
		for(int i=0;i<n;i++) {
			config[0][i]=a.charAt(i);
			config[1][i]=b.charAt(i);
		}
		long ans=1;
		int mod=1000000007;
		int[] visited=new int[n];
			for(int j=0;j<n;j++) {
				if(visited[j]==0) {
				if(j+1<n && config[0][j]==config[0][j+1]) {
						visited[j+1]=1;
						if(j==0) {
							ans*=6;
						}
						else {
							if(config[0][j-1]==config[1][j-1]) ans*=2;
							else ans*=3;
							ans%=mod;
						}
				}
				else {
					if(j==0) ans*=3;
					else {
						if(config[0][j-1]==config[1][j-1]) ans*=2;
						ans%=mod;
					}
				}
				}
			}
		System.out.println(ans);
}
}
 class DisJoint {
		int[] parent;
		int[] rank;
		int[] colour;
		ArrayList<Integer>[] arr;
		DisJoint(int n){
			parent=new int[n+1];
			rank=new int[n+1];
			arr=new ArrayList[n+1];
			colour=new int[n+1];
			for(int i=0;i<=n;i++) {
				parent[i]=i;
				arr[i]=new ArrayList<Integer>();
				arr[i].add(i);
			}
		}

		int find(int value) {
			int par=parent[value];
			if(par==value)
				return par;
			parent[value]=find(par);
			return parent[value];
		}
		
		void union(int data1,int data2, int value) {
			int parent1=find(data1);
			int parent2=find(data2);
			if(parent1!=parent2) {
				if(rank[parent1]>=rank[parent2]) {
					parent[parent2]=parent1;
					if(rank[parent1]==rank[parent2])
						rank[parent1]++;
					if(colour[data1]==colour[data2] && value==1 || colour[data1]!=colour[data2] && value==0) {
						for(int i:arr[parent2]) {
							if(colour[i]==0) colour[i]=1;
							else colour[i]=0;
						}
					}
					arr[parent1].addAll(arr[parent2]);
				}
				else {
					parent[parent1]=parent2;
					if(colour[data1]==colour[data2] && value==1 || colour[data1]!=colour[data2] && value==0) {
						for(int i:arr[parent1]) {
							if(colour[i]==0) colour[i]=1;
							else colour[i]=0;
						}
					}
					arr[parent2].addAll(arr[parent1]);
				}
			}
		}
 }
 
class SegTree{
	long[] seg;
	int[] map;
	long[] arr;
	SegTree(int n,long[] a){
		seg=new long[4*n];
		arr=a;
		map=new int[n+1];
	}
	void build(int low,int high, int pos) {
		if(low==high) {
			map[low]=pos;
			seg[pos]=arr[low];
		}
		else {
			int middle=(low+high)/2;
			build(low,middle,2*pos+1);
			build(middle+1,high,2*pos+2);
			seg[pos]=Math.max(seg[2*pos+1], seg[2*pos+2]);
		}
	}
	void update(int low,int high, int pos,int elpos, long value) {
		if(low==high) {
			seg[pos]=value;
		}
		else {
			int middle=(low+high)/2;
			if(elpos<=middle) {
				update(low,middle,2*pos+1,elpos,value);
			}
			else update(middle+1,high,2*pos+2,elpos,value);
			seg[pos]=Math.max(seg[2*pos+1], seg[2*pos+2]);
		}
	}
}
 
 class Reader {
	    static BufferedReader reader;
	    static StringTokenizer tokenizer;
	 
	    /** call this method to initialize reader for InputStream */
	    static void init(InputStream input) {
	        reader = new BufferedReader(
	                     new InputStreamReader(input) );
	        tokenizer = new StringTokenizer("");
	    }
	 
	    /** get next word */
	    
	    static String next() throws IOException {
	        while ( ! tokenizer.hasMoreTokens() ) {
	            //TODO add check for eof if necessary
	            tokenizer = new StringTokenizer(
	                   reader.readLine() );
	        }
	        return tokenizer.nextToken();
	    }
	 
	    static int nextInt() throws IOException {
	        return Integer.parseInt( next() );
	    }
	    static long nextLong() throws IOException {
	        return Long.parseLong( next() );
	    }
	    static double nextDouble() throws IOException {
	        return Double.parseDouble( next() );
	    }
	} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.