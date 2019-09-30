package gcj2011rd1a;
import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class B {

   Scanner sc;
   PrintWriter pw;

   public B() throws Exception {
      sc = new Scanner(new File("B-large.in"));
      pw = new PrintWriter(new File("B-out.txt"));
      //sc = new Scanner(new File("B-in.txt"));
      //pw = new PrintWriter(System.out);

      int nCases = Integer.parseInt(sc.nextLine());
      for (int i=1; i<=nCases; i++) {
         processCase(i);
      }
      pw.flush();
      pw.close();
   }

   int N, M;
   int[] points;
   String[] dict;
   String[] lists;

   void processCase(int caseNum) {
	   int[] data = readInts();
	   N = data[0];
	   M = data[1];
	   dict = new String[N];
	   for (int i=0; i<N; i++) {
		   dict[i] = readString();
	   }
	   lists = new String[M];
	   for (int i=0; i<M; i++) {
		   lists[i] = readString();
	   }
	   StringBuffer ans = new StringBuffer();
	   for (int m=0; m<M; m++) {
		   points = new int[N];
		   for (int len=1; len<=10; len++) {
			   ArrayList<Integer> indices = new ArrayList<Integer>();
			   for (int i=0; i<N; i++) if (dict[i].length()==len) {
				   indices.add(i);
			   }
			   doit(indices, lists[m]);
		   }
		   //for (int x=0; x<N; x++) System.out.println(dict[x] + ": " + points[x] + " pts");

		   int best = -1;
		   int bestIdx = -1;
		   for (int i=0; i<N; i++) {
			   if (points[i] > best) {
				   best = points[i];
				   bestIdx = i;
			   }
		   }
		   if (m > 0) ans.append(" ");
		   ans.append(dict[bestIdx]);
	   }
	   pw.println("Case #" + caseNum + ": " + ans);
   }

   void doit(ArrayList<Integer> indices, String list) {
	   if (indices.size() <= 1) return;
	   if (list.length() < 0) return;
	   char ch = list.charAt(0);
	   boolean appears = false;
	   for (int idx: indices) {
		   if (dict[idx].indexOf(ch) >= 0) {
			   appears = true;
			   break;
		   }
	   }
	   if (!appears)  {
		   doit(indices, list.substring(1));
		   return;
	   }
	   for (int idx: indices) {
		   if (dict[idx].indexOf(ch) < 0) {
			   points[idx]++;
		   }
	   }
	   int[] mask = new int[indices.size()];
	   for (int i=0; i<indices.size(); i++) {
		   String word = dict[indices.get(i)];
		   mask[i] = 0;
		   for (int j=0; j<word.length(); j++) {
			   if (word.charAt(j) == ch) {
				   mask[i] |= (1 << j);
			   }
		   }
	   }
	   boolean[] processed = new boolean[indices.size()];
	   for (int i=0; i<indices.size(); i++) {
		   if (!processed[i]) {
			   ArrayList<Integer> i2 = new ArrayList<Integer>();
			   for (int j=i; j<indices.size(); j++) {
				   if (mask[j] == mask[i]) {
					   i2.add(indices.get(j));
					   processed[j] = true;
				   }
			   }
			   doit(i2, list.substring(1));
		   }
	   }
   }


///////////////////////////////////////////////////////////////////
   // Pre-written code below


   ///////////////////////////////////////////////
   // Parsing routines
   ///////////////////////////////////////////////

   int[] parseIntArray(String s) {
      StringTokenizer st = new StringTokenizer(s, " ");
      int[] ret = new int[st.countTokens()];
      for (int i=0; i<ret.length; i++) {
         ret[i] = Integer.parseInt(st.nextToken());
      }
      return ret;
   }

   int nextInt() {
	   return Integer.parseInt(sc.next());
   }

   int readInt() {
      return Integer.parseInt(sc.nextLine());
   }

   int[] readInts() {
      return parseIntArray(sc.nextLine());
   }

   String readString() {
      return sc.nextLine();
   }

   String[] parseStringArray(String s) {
      StringTokenizer st = new StringTokenizer(s, " ");
      String[] ret = new String[st.countTokens()];
      for (int i=0; i<ret.length; i++) {
         ret[i] = st.nextToken();
      }
      return ret;
   }

   String[] readStrings() {
      StringTokenizer st = new StringTokenizer(sc.nextLine(), " ");
      String[] ret = new String[st.countTokens()];
      for (int i=0; i<ret.length; i++) {
         ret[i] = st.nextToken();
      }
      return ret;
   }

   ///////////////////////////////////////////////

   public static void main(String[] args) {
      try {
         new B();
      } catch (Exception e) {
         e.printStackTrace();
      }
   }
}
