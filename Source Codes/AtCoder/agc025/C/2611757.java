import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.flush();out.close();
    }
        static class TaskE {
          class pair{
           int l,r,id;pair(int a,int b,int c){l=a;r=b;id=c;}
          }
          ArrayList<pair> l=new ArrayList<>(),r=new ArrayList<>();
          long v(int t,int n){
           long ans1=0;
              boolean is[]=new boolean[n];
              int pst=0,p1=0,p2=0;
              while(p1!=n&&p2!=n){
               if(t==0){
                if(p1==n){
                 t=1;continue;
                }
                pair p=l.get(p1);
                if(p.l<=pst||is[p.id]){}
                else{
                 ans1+=p.l-pst;is[p.id]=true;pst=p.l;
                }
                ++p1;t=1;
               }else{
                if(p2==n){
                 t=0;continue;
                }
                pair p=r.get(p2);
                if(p.r>=pst||is[p.id]){}
                else{
                 ans1+=pst-p.r;pst=p.r;is[p.id]=true;
                }
                ++p2;t=0;
               }
              }
              ans1+=Math.abs(pst);
              return ans1;
          }
          public void solve(int testNumber, InputReader in, PrintWriter out) {
              int n=in.nextInt();
              for(int i=0;i<n;i++){
               int lt=in.nextInt(),rt=in.nextInt();
               l.add(new pair(lt,rt,i));
               r.add(new pair(lt,rt,i));
              }
              Collections.sort(l,new Comparator<pair>(){
               public int compare(pair p1,pair p2){
                return -p1.l+p2.l;
               }
              });
              Collections.sort(r,new Comparator<pair>(){
               public int compare(pair p1,pair p2){
                return p1.r-p2.r;
               }
              });
              out.print(Math.max(v(0,n),v(1,n)));
          }
          //          int ja[][],from[],to[],c[];
    //              void make(int n,int m,InputReader in){
    //               ja=new int[n+1][];from=new int[m];to=new int[m];c=new int[n+1];
    //               for(int i=0;i<m;i++){
    //                from[i]=in.nextInt();to[i]=in.nextInt();
    //                c[from[i]]++;c[to[i]]++;
    //               }
    //               for(int i=1;i<=n;i++){
    //                ja[i]=new int[c[i]];c[i]=0;
    //               }
    //               for(int i=0;i<m;i++){
    //                ja[from[i]][c[from[i]]++]=to[i];
    //                ja[to[i]][c[to[i]]++]=from[i];
    //               }
    //              }
//            int[] radixSort(int[] f){ return radixSort(f, f.length); }
//    	int[] radixSort(int[] f, int n)
//    	{
//    		int[] to = new int[n];
//    		{
//    			int[] b = new int[65537];
//    			for(int i = 0;i < n;i++)b[1+(f[i]&0xffff)]++;
//    			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
//    			for(int i = 0;i < n;i++){
//                             to[b[f[i]&0xffff]++] = f[i];
//                            }
//    			int[] d = f; f = to;to = d;
//    		}
//    		{
//    			int[] b = new int[65537];
//    			for(int i = 0;i < n;i++)b[1+(f[i]>>>16)]++;
//    			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
//    			for(int i = 0;i < n;i++)to[b[f[i]>>>16]++] = f[i];
//    			int[] d = f; f = to;to = d;
//    		}
//    		return f;
//    	}
    
       }
    static class InputReader {
        BufferedReader br;
        StringTokenizer st;
        public InputReader(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
            st = null;
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
            return Long.parseLong(next());
        }
        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}